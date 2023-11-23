#pragma once
#include <SDL.h>

class InputHandler {
public:
	static const Uint8* GetKeyState();
	static bool IsQuitEvent(SDL_Event& event);
};