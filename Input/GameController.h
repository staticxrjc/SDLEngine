#ifndef APP_INPUT_GAMECONTROLLER_H
#define APP_INPUT_GAMECONTROLLER_H

#include "InputAction.h"
#include <vector>

class GameController {
   public:
    GameController();
    InputAction GetActionForKey(InputKey key);
    void AddInputActionForKey(const ButtonAction& ButtonAction);
    void ClearAll();

    static bool IsPressed(InputState state);
    static bool IsReleased(InputState state);
    static InputKey ActionKey();
    static InputKey CancelKey();
    static InputKey LeftKey();
    static InputKey RightKey();
    static InputKey UpKey();
    static InputKey SpaceKey();
    static InputKey DownKey();

    inline const MouseMovedAction& GetMouseMovedAction() { return mMouseMovedAction; }
    inline void SetMouseMovedAction(const MouseMovedAction& mouseMovedAction) { mMouseMovedAction = mouseMovedAction; }

    MouseInputAction GetMouseButtonActionForMouseButton(MouseButton button);
    void AddMouseButtonAction(const MouseButtonAction& mouseButtonAction);

    static MouseButton LeftMouseButton();
    static MouseButton RightMouseButton();

   private:
    std::vector<ButtonAction> mButtonActions;
    std::vector<MouseButtonAction> mMouseButtonActions;

    MouseMovedAction mMouseMovedAction;
};

#endif  // APP_INPUT_GAMECONTROLLER_H