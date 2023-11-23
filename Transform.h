#pragma once
#include <SDL.h>

class Transform {
public:
	static SDL_Rect Translate(const SDL_Rect& rect, float xOffset, float yOffset);
	static SDL_Rect Scale(const SDL_Rect& rect, float xScale, float yScale);
	static SDL_Rect Rotate(const SDL_Rect& rect, float angleDegrees);
};