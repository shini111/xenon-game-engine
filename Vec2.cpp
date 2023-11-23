#include "Vec2.h"

Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

void Vec2::Set(float newX, float newY) {
	x = newX;
	y = newY;
}

Vec2 Vec2::operator+(const Vec2& other) const {
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
	return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const {
	if (scalar != 0.0f) {
		return Vec2(x / scalar, y / scalar);
	}
	else {
		std::cerr << "Error: Division by zero." << std::endl;
		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
	os << "(" << vec.x << ", " << vec.y << ")";
	return os;
}