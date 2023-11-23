#pragma once
#include <SDL.h>
#include <string>

class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	SDL_Renderer* GetRenderer() const;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

