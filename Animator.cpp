#include "Animator.h"
#include <iostream>

Animator::Animator(SDL_Texture* spriteSheet, int textureW, int textureH, int nCollumns, int nRows)
	:textureWidth(textureW), textureHeight(textureH)
{
	SDL_QueryTexture(spriteSheet, NULL, NULL, &textureWidth, &textureHeight);
 	frameWidth = textureWidth / nCollumns;
	frameHeight = textureHeight / nRows;
}

Animator::~Animator(){
	std::cout << "Animator Deleted" << std::endl;
}
