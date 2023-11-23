#include <iostream>
#include "Window.h"
#include "TextureLoader.h"
#include "InputHandler.h"


int main(int argc, char* argv[]) {
    Window window("SDL window", 640, 480);
    SDL_Renderer* renderTarget = window.GetRenderer();

    SDL_Texture* currentImage = TextureLoader::LoadTexture("resources/graphics/drone.bmp", renderTarget);
    SDL_Texture* background = TextureLoader::LoadTexture("resources/graphics/galaxy2.bmp", renderTarget);

    SDL_Rect playerRect;
    SDL_Rect playerPosition;

    playerPosition.x = playerPosition.y = 0;
    playerPosition.w = playerPosition.h = 32;
    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    float frameTime = 0;
    int prevTime = 0;
    int currentTime = 0;
    float deltaTime = 0;

    float moveSpeed = 200.0f;
    const Uint8* keyState;

    SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth / 8;
    frameHeight = textureHeight / 2;

    playerRect.x = playerRect.y = 0;
    playerRect.w = frameWidth;
    playerRect.h = frameHeight;

    float playerPositionx = playerPosition.x;
    float playerPositiony = playerPosition.y;

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

        keyState = InputHandler::GetKeyState();
        if (keyState[SDL_SCANCODE_RIGHT]) {
            playerPositionx += moveSpeed * deltaTime;
        }
        if (keyState[SDL_SCANCODE_LEFT])
            playerPositionx -= moveSpeed * deltaTime;

        frameTime += deltaTime;

        if (frameTime >= 0.1f) {
            frameTime = 0;
            playerRect.x += frameWidth;
            if (playerRect.x >= textureWidth) {
                playerRect.x = 0;
                playerRect.y += frameHeight;
                if (playerRect.y >= textureHeight) {
                    playerRect.y = 0;
                }
            }
        }
        playerPosition.x = playerPositionx;

        SDL_RenderClear(renderTarget);
        SDL_RenderCopy(renderTarget, background, NULL, NULL);
        SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
        SDL_RenderPresent(renderTarget);
    }

  

//     SDL_DestroyWindow(window);
       SDL_DestroyTexture(currentImage);
       SDL_DestroyTexture(background);
       SDL_DestroyRenderer(renderTarget);

    SDL_Quit();

    return 0;
}