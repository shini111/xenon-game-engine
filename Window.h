#pragma once
#include <SDL.h>
#include <string>
#include <memory>

class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	SDL_Renderer* GetRenderer() const;

private:
	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
};

