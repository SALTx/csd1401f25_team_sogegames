#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Default configs */
static ConfigItem defaultConfigs[] = {
	{ "sound_toggle", "Turns the sound On / Off", 1.0f, 0.0f, 1.0f, CONFIG_TOGGLE },
	{ "music_volume", "Music volume", 0.8f, 0.0f, 1.0f, CONFIG_SLIDER },
	{ "sfx_volume", "SFX volume", 1.0f, 0.0f, 1.0f, CONFIG_SLIDER }
};
static const size_t defaultCount = sizeof(defaultConfigs) / sizeof(defaultConfigs[0]);

/* Runtime storage (allocated copy of defaults) */
static ConfigItem* configs = NULL;
static size_t configs_len = 0;

static void init_runtime_from_defaults(void) {
	if (configs) return;
	configs_len = defaultCount;
	configs = (ConfigItem*)malloc(sizeof(ConfigItem) * configs_len);
	if (!configs) {
		configs_len = 0;
		return;
	}
	for (size_t i = 0; i < configs_len; ++i) {
		configs[i] = defaultConfigs[i];
	}
}

size_t config_count(void) { return configs_len; }
const ConfigItem* config_defaults(void) { return defaultConfigs; }

ConfigItem* config_find(const char* name) {
	if (!configs) init_runtime_from_defaults();
	if (!configs) return NULL;
	for (size_t i = 0; i < configs_len; ++i) {
		if (strcmp(configs[i].name, name) == 0) return &configs[i];
	}
	return NULL;
}

float config_get(const char* name) {
	ConfigItem* it = config_find(name);
	return it ? it->value : 0.0f;
}

int config_set(const char* name, float v) {
	ConfigItem* it = config_find(name);
	if (!it) return -1;
	/* clamp to min/max */
	if (v < it->min) v = it->min;
	if (v > it->max) v = it->max;
	it->value = v;
	return 0;
}

/* trim helpers */
static char* trim_whitespace(char* s) {
	char* end;
	while (isspace((unsigned char)*s)) s++;
	if (*s == 0) return s;
	end = s + strlen(s) - 1;
	while (end > s && isspace((unsigned char)*end)) end--;
	end[1] = '\0';
	return s;
}

/* Parse file with lines "name=value". Ignores comments starting with '#' */
int loadConfigurationFromFile(const char* path) {
	init_runtime_from_defaults();
	if (!configs) return -1;

	FILE* f = fopen(path, "r");
	if (!f) {
		/* file doesn't exist -> write defaults to file */
		saveConfigurationToFile(path);
		return 0;
	}

	char line[256];
	while (fgets(line, sizeof(line), f)) {
		char* p = line;
		/* skip comments and empty */
		while (isspace((unsigned char)*p)) ++p;
		if (*p == '#' || *p == '\0' || *p == '\n') continue;

		char* eq = strchr(p, '=');
		if (!eq) continue;
		*eq = '\0';
		char* name = trim_whitespace(p);
		char* valstr = trim_whitespace(eq + 1);
		/* remove trailing newline from valstr */
		char* nl = strchr(valstr, '\n');
		if (nl) *nl = '\0';

		ConfigItem* it = config_find(name);
		if (!it) continue;
		/* parse float */
		char* endptr = NULL;
		float v = strtof(valstr, &endptr);
		if (endptr == valstr) continue; /* invalid number */
		/* clamp and assign */
		if (v < it->min) v = it->min;
		if (v > it->max) v = it->max;
		it->value = v;
	}
	fclose(f);
	return 0;
}

int saveConfigurationToFile(const char* path) {
	init_runtime_from_defaults();
	if (!configs) return -1;

	FILE* f = fopen(path, "w");
	if (!f) return -1;
	for (size_t i = 0; i < configs_len; ++i) {
		if (fprintf(f, "%s=%f\n", configs[i].name, configs[i].value) < 0) {
			fclose(f);
			return -1;
		}
	}
	fclose(f);
	return 0;
}

/* Convenience default loader uses "config.cfg" */
void loadConfiguration(void) {
	const char* defaultPath = "config.cfg";
	loadConfigurationFromFile(defaultPath);
}