#include "Window.h"

Window::Window(const std::string& title, int width, int height)
	: window(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL), SDL_DestroyWindow),
	renderer(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer) {
	SDL_Init(SDL_INIT_VIDEO);
}

Window::~Window() {
	// smart pointers will automatically manage the destruction of the window and renderer
	SDL_Quit();
}

SDL_Renderer* Window::GetRenderer() const {
	return renderer.get();
}