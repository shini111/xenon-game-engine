#pragma once
#include "SDL.h"

class Animator
{
public:
	int textureWidth,textureHeight, frameWidth, frameHeight;

	Animator(SDL_Texture* spriteSheet, int textureW, int textureH, int nCollumns, int nRows);
	~Animator();
};

