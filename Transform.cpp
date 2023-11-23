#include "Transform.h"
#include <cmath>

SDL_Rect Transform::Translate(const SDL_Rect& rect, float xOffset, float yOffset) {
	SDL_Rect result = rect;
	result.x += static_cast<int>(xOffset);
	result.y += static_cast<int>(yOffset);
	return result;
}

SDL_Rect Transform::Scale(const SDL_Rect& rect, float xScale, float yScale) {
	SDL_Rect result = rect;
	result.w = static_cast<int>(rect.w * xScale);
	result.h = static_cast<int>(rect.h * yScale);
	return result;
}

SDL_Rect Transform::Rotate(const SDL_Rect& rect, float angleDegrees) {
	SDL_Rect result = rect;
	result.x += static_cast<int>(cos(angleDegrees) * rect.w);
	result.y += static_cast<int>(sin(angleDegrees) * rect.h);
	return result;
}