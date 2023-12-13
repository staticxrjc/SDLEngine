//
// Created by rcole on 12/12/23.
//

#ifndef SCENES_GAMESCENE_H
#define SCENES_GAMESCENE_H

#include "Scene.h"
#include "../../Games/Game.h"
#include <memory>


class GameScene : public Scene {
public:
    GameScene(std::unique_ptr<Game> optrGame);
    virtual ~GameScene() = default;
    void Init() override;
    void Update(uint32_t dt) override;
    void Draw(Screen &theScreen) override;
    const std::string &GetSceneName() const override;


private:
    std::unique_ptr<Game> mGame;
};


#endif //SCENES_GAMESCENE_H
