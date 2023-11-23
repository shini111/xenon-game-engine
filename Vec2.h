#pragma once
#include <iostream>

class Vec2 {
public:
	float x, y;

	Vec2();
	Vec2(float x, float y);

	void Set(float newX, float newY);

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator*(float scalar) const;
	Vec2 operator/(float scalar) const;

	friend std::ostream& operator<<(std::ostream& os, const Vec2& vec);
};