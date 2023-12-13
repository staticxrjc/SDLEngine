#include "InputController.h"
#include "GameController.h"
#include <SDL2/SDL.h>

InputController::InputController() : mQuit(nullptr), mnoptrCurrenController(nullptr) {}

void InputController::Init(InputAction quitAction) {
    mQuit = quitAction;
}

void InputController::Update(uint32_t dt) {
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT: {
                mQuit(dt, SDL_PRESSED);
            }
            case SDL_MOUSEMOTION:
                if (mnoptrCurrenController) {
                    if (MouseMovedAction mouseMoved = mnoptrCurrenController->GetMouseMovedAction()) {
                        MousePosition position{};
                        position.xPos = sdlEvent.motion.x;
                        position.yPos = sdlEvent.motion.y;
                        mouseMoved(position);
                    }
                }
                break;

            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEBUTTONDOWN:
                if (mnoptrCurrenController) {
                    MouseInputAction action = mnoptrCurrenController->GetMouseButtonActionForMouseButton(static_cast<MouseButton>(sdlEvent.button.button));
                    MousePosition position{};
                    position.xPos = sdlEvent.button.x;
                    position.yPos = sdlEvent.button.y;

                    action(static_cast<InputState>(sdlEvent.button.state), position);
                }
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                if (mnoptrCurrenController) {
                    InputAction action = mnoptrCurrenController->GetActionForKey(sdlEvent.key.keysym.sym);
                    action(dt, static_cast<InputState>(sdlEvent.key.state));
                }
                break;
        }
    }
}

void InputController::SetGameController(GameController* controller) {
    mnoptrCurrenController = controller;
}
