#include "shape_utils.h"
#include "collision_utils.h"

// @todo Add consideration for shape modes

int pointInRect(Point point, Quad rect) {
	int widthBound = (point.x >= rect.position.x) && (point.x <= (rect.position.x + rect.width));
	int heightBound = (point.y >= rect.position.y) && (point.y <= (rect.position.y + rect.height));

	return (widthBound && heightBound);
}

int rectInRect(Quad rect1, Quad rect2) {

}

int pointInCircle(Point point, Circle circle) {

}

int circleInCircle(Circle circle1, Circle circle2) {

}
