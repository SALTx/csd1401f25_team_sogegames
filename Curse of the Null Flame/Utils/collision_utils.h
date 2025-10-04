#ifndef COLLISION_UTILS_H
#define COLLISION_UTILS_H

int pointInRect(Point point, Quad rect);
int rectInRect(Quad rect1, Quad rect2);
int pointInCircle(Point point, Circle circle);
int circleInCircle(Circle circle1, Circle circle2);

#endif // COLLISION_UTILS_H
