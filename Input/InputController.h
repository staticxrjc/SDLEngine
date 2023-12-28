#ifndef APP_INPUT_INPUTCONTROLLER_H
#define APP_INPUT_INPUTCONTROLLER_H

#include "InputAction.h"

class GameController;

class InputController {
   public:
    InputController();
    void Init(InputAction quitAction);
    void Update(uint32_t dt);

    void SetGameController(GameController* controller);

   private:
    InputAction mQuit;
    GameController* mnoptrCurrenController;
};

#endif  // APP_INPUT_INPUTCONTROLLER_H