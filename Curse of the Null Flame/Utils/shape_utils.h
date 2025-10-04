#ifndef SHAPE_UTILS_H
#define SHAPE_UTILS_H

//! Point
typedef struct {
	float x;
	float y;
} Point;

//! Quad
typedef struct {
	Point position;
	float width;
	float height;
} Quad;

//! Circle
typedef struct {
	Point center;
	float radius;
} Circle;

#endif // SHAPE_UTILS_H
