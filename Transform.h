#pragma once
#include <SDL.h>
#include "Vec2.h"
#include <iostream>


class Transform {
public:
	Vec2 position;
	float rotation;
	Vec2 scale;

	Transform();
	~Transform();

	void Translate(const Vec2& translation);
	void Rotate(float angle);
	void Scale(const Vec2& scaling);

	void DisplayTransform() const;
};