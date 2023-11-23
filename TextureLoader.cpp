#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const std::string& filepath, SDL_Renderer* renderTarget) {
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
	if (surface != nullptr) {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		SDL_FreeSurface(surface);
	}
	return texture;
}