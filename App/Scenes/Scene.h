#ifndef APP_SCENES_SCENE_H
#define APP_SCENES_SCENE_H

#include <string>
#include <stdint.h>
#include "../Input/GameController.h"

class Screen;

// Interface
class Scene {
public:
    virtual ~Scene() {}

    virtual void Init() = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen &theScreen) = 0;
    virtual const std::string &GetSceneName() const = 0;

    inline GameController *GetGameController() { return &mGameController; }

protected:
    GameController mGameController;
};

#endif  // APP_SCENES_SCENE_H