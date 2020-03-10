#include "Point.h"

Point::Point() {
	this->x = this->y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

bool Point::operator==(const Point& point) const {
	return this->x == point.x && this->y == point.y;
}

bool Point::operator<(const Point& point) const {
	if (this->x < point.x) {
		return true;
	}
	if (this->x > point.x) {
		return false;
	}
	if (this->y < point.y) {
		return true;
	}
	return false;
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}
