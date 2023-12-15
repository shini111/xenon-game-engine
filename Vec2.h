#pragma once
#include <SDL.h>
#include <iostream>

class Vec2 {
public:
	float x, y;

	Vec2();
	Vec2(float, float y);

	void Set(float newX, float newY);

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator*(const Vec2& other) const;
	Vec2 operator*(float scalar) const;
	Vec2 operator/(const Vec2& other) const;
	Vec2 operator/(float scalar) const;
	
	void Log(std::string msg = "") const {
		std::cout << msg << "(X,Y) = (" << x << " " << y << ")" << std::endl;
	}

// 	operator SDL_Point() const;
// 
// 	operator SDL_Rect() const; // Direct conversion to SDL_Rect
};