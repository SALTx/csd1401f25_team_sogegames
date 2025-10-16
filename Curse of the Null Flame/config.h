#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef enum {
		CONFIG_TOGGLE = 0,
		CONFIG_SLIDER = 1
	} ConfigType;

	typedef struct {
		char name[32];
		char description[128];
		float value;
		float min;
		float max;
		ConfigType type;
	} ConfigItem;

	/* Initialize/load configuration (reads "config.cfg" in working dir).
	   Call early in startup. */
	void loadConfiguration(void);

	/* Load/Save with explicit path (returns 0 on success, non-zero on error) */
	int loadConfigurationFromFile(const char* path);
	int saveConfigurationToFile(const char* path);

	/* Query/modify runtime config items */
	ConfigItem* config_find(const char* name);
	float config_get(const char* name);     /* returns value or 0.0f if not found */
	int config_set(const char* name, float v); /* returns 0 on success, non-zero if not found */

	/* Introspection */
	size_t config_count(void);
	const ConfigItem* config_defaults(void); /* pointer to internal defaults array */

#ifdef __cplusplus
}
#endif

#endif // CONFIG_H