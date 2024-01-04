#include <iostream>
#include "Window.h"
#include "TextureLoader.h"
#include "InputHandler.h"
#include "Transform.h"
#include "Animator.h"


int main(int argc, char* argv[]) {
	Window window("SDL window", 640, 480);
	SDL_Renderer* renderTarget = window.GetRenderer();

	SDL_Texture* currentImage = TextureLoader::LoadTexture("resources/graphics/drone.bmp", renderTarget);
	SDL_Texture* background = TextureLoader::LoadTexture("resources/graphics/galaxy2.bmp", renderTarget);
	


// 	int frameWidth, frameHeight;
// 	int textureWidth, textureHeight;
	
// 	frameWidth = textureWidth / 8;
// 	frameHeight = textureHeight / 2;

	Animator playerAnimator(currentImage, 0, 0, 8, 2);
//	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
/*	SDL_QueryTexture(currentImage, NULL, NULL, &playerAnimator.textureWidth, &playerAnimator.textureHeight);*/
	


	float frameTime = 0;
	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;

	const float moveSpeed = 200.0f;

	SDL_Rect playerRect;
	/*playerRect = { 0, 0, frameWidth, frameHeight };*/
	playerRect = { 0,0, playerAnimator.frameWidth, playerAnimator.frameHeight };
	SDL_Rect playerRenderPosition;
	playerRenderPosition = {0,0,32,32};

	Transform playerTransform; // Create a Transform for the player
	playerTransform.position.Set(playerRenderPosition.x, playerRenderPosition.y);

	SDL_SetRenderDrawColor(renderTarget, 0xFF, 0, 0, 0xFF);

	bool isRunning = true;
	SDL_Event ev;

	while (isRunning) {
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;

		while (SDL_PollEvent(&ev) != 0) {
			// Getting the events
			if (InputHandler::IsQuitEvent(ev))
				isRunning = false;
		}

		const Uint8* keyState = InputHandler::GetKeyState();

		// Update player position using the Transform class
		if (keyState[SDL_SCANCODE_RIGHT]) {
			playerTransform.Translate(Vec2(moveSpeed * deltaTime, 0.0f));
		}
		if (keyState[SDL_SCANCODE_LEFT]) {
			playerTransform.Translate(Vec2(-moveSpeed * deltaTime, 0.0f));
		}if (keyState[SDL_SCANCODE_UP]) {
			playerTransform.Translate(Vec2(0.0f, -moveSpeed * deltaTime));
		}
		if (keyState[SDL_SCANCODE_DOWN]) {
			playerTransform.Translate(Vec2(0.0f, moveSpeed * deltaTime));
		}


		frameTime += deltaTime;

		if (frameTime >= 0.1f) {
			frameTime = 0;
			playerRect.x += playerAnimator.frameWidth;
			if (playerRect.x >= playerAnimator.textureWidth) {
				playerRect.x = 0;
				playerRect.y += playerAnimator.frameHeight;
				if (playerRect.y >= playerAnimator.textureHeight) {
					playerRect.y = 0;
				}
			}
		}

		// Set the player position based on the Transform
		playerRenderPosition.x = static_cast<int>(playerTransform.position.x);
		playerRenderPosition.y = static_cast<int>(playerTransform.position.y);

		SDL_RenderClear(renderTarget);
		SDL_RenderCopy(renderTarget, background, NULL, NULL);
		SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerRenderPosition);
		SDL_RenderPresent(renderTarget);
	}

// 	SDL_DestroyTexture(currentImage);
//	SDL_DestroyTexture(background);
// 	SDL_DestroyRenderer(renderTarget);
// 
// 	SDL_Quit();

	return 0;
}