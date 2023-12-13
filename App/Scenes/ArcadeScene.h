#ifndef APP_SCENES_ARCADESCENE_H
#define APP_SCENES_ARCADESCENE_H

#include "Scene.h"
#include <memory>

enum eGame {
    TETRIS = 0,
    BREAK_OUT,
    ASTEROIDS,
    PACMAN,
    CHESS,
    NUM_GAMES
};

class Screen;

class ArcadeScene : public Scene {
   public:
    ArcadeScene();
    void Init() override;
    void Update(uint32_t dt) override;
    void Draw(Screen& theScreen) override;
    const std::string& GetSceneName() const override;

   private:
    std::unique_ptr<Scene> GetScene(eGame game);
};

#endif  // APP_SCENES_ARCADESCENE_H