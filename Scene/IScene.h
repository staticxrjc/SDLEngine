#ifndef APP_SCENES_SCENE_H
#define APP_SCENES_SCENE_H

#include <string>
#include <cstdint>
#include "../../Engine/Input/GameController.h"

class Screen;

// Interface
class IScene {
public:
    virtual ~IScene() = default;

    virtual void Init() = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen &theScreen) = 0;
    [[nodiscard]] virtual const std::string &GetSceneName() const = 0;

    inline GameController *GetGameController() { return &mGameController; }

protected:
    GameController mGameController;
};

#endif  // APP_SCENES_SCENE_H