#include "Vec2.h"
#include <iostream>

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


Vec2 Vec2::operator*(const Vec2& other) const {
		return Vec2(x * other.x, y * other.y);
}

Vec2 Vec2::operator*(float scalar) const {
	return Vec2(x * scalar, y * scalar);
}


Vec2 Vec2::operator/(const Vec2& other) const {
	if (other.x != 0.0f && other.y != 0.0f) {
		return Vec2(x / other.x, y / other.y);
	}
	else {
		std::cerr << "Error: Division by zero in vector division." << std::endl;
		return *this;
	}
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



// 
// Vec2::operator SDL_Point() const {
// 	SDL_Point point;
// 	point.x = static_cast<int>(x);
// 	point.y = static_cast<int>(y);
// 	return point;
// }
// 
// Vec2::operator SDL_Rect() const {
// 	SDL_Rect rect;
// 	rect.x = static_cast<int>(x);
// 	rect.y = static_cast<int>(y);
// 	return rect;
// }