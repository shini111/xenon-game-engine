#pragma once
#include <SDL.h>
#include <string>

class TextureLoader {
public:
	static SDL_Texture* LoadTexture(const std::string& filepath, SDL_Renderer* renderTarget);
};
