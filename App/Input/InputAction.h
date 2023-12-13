#ifndef APP_INPUT_INPUTACTION_H
#define APP_INPUT_INPUTACTION_H

#include <functional>
#include <stdint.h>

using InputKey = uint8_t;
using InputState = uint8_t;
using MouseButton = uint8_t;

using InputAction = std::function<void(uint32_t, InputState)>;

struct ButtonAction {
    InputKey key;
    InputAction action;
};

struct MousePosition {
    uint32_t xPos, yPos;
};

using MouseMovedAction = std::function<void(const MousePosition&)>;
using MouseInputAction = std::function<void(InputState, const MousePosition&)>;

struct MouseButtonAction {
    MouseInputAction mouseInputAction;
    MouseButton mouseButton;
};

#endif  // APP_INPUT_INPUTACTION_H