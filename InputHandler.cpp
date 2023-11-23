#include "InputHandler.h"

const Uint8* InputHandler::GetKeyState() {
	return SDL_GetKeyboardState(NULL);
}

bool InputHandler::IsQuitEvent(SDL_Event& event) {
	return event.type == SDL_QUIT;
}