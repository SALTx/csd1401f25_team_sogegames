#include "shape_utils.h"
#include "collision_utils.h"

// @todo Add consideration for shape modes

int pointInRect(Point point, Quad rect) {
	int widthBound = (point.x >= rect.position.x) && (point.x <= (rect.position.x + rect.width));
	int heightBound = (point.y >= rect.position.y) && (point.y <= (rect.position.y + rect.height));

	return (widthBound && heightBound);
}

// TODO: incomplete
int rectInRect(Quad rect1, Quad rect2) {
	// edges for rect1
	float left1 = rect1.position.x;
	float right1 = rect1.position.x + rect1.width;
	float top1 = rect1.position.y;
	float bottom1 = rect1.position.y + rect1.height;

	// edges for rect2
	float left2 = rect2.position.x;
	float right2 = rect2.position.x + rect2.width;
	float top2 = rect2.position.y;
	float bottom2 = rect2.position.y + rect2.height;

	// Check for overlap on both axes (AABB)
	int overlapX = (right1 >= left2) && (left1 <= right2);
	int overlapY = (bottom1 >= top2) && (top1 <= bottom2);

	return (overlapX && overlapY);
}

int pointInCircle(Point point, Circle circle) {
	float dx = point.x - circle.center.x;
	float dy = point.y - circle.center.y;
	float distSquared = dx * dx + dy * dy;
	
	//TODO: maybe root the dist then check? works for now though
	return distSquared <= (circle.radius * circle.radius);
}

int circleInCircle(Circle circle1, Circle circle2) {
	float dx = circle1.center.x - circle2.center.x;
	float dy = circle2.center.y - circle2.center.y;

	float distSquared = dx * dx + dy * dy;
	float radiusSum = circle1.radius + circle2.radius;

	//TODO: Same as above (root before comparison)?
	return distSquared <= (radiusSum * radiusSum);
}
