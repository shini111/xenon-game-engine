#pragma once
#include <SDL.h>

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

	operator SDL_Point() const;

	operator SDL_Rect() const; // Direct conversion to SDL_Rect
};