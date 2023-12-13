//
// Created by rcole on 12/12/23.
//

#include "GameScene.h"

GameScene::GameScene(std::unique_ptr<Game> optrGame) : mGame(std::move(optrGame)) {}

void GameScene::Init() {
    mGame->Init(mGameController);
}

void GameScene::Update(uint32_t dt) {
    mGame->Update(dt);
}

void GameScene::Draw(Screen &theScreen) {
    mGame->Draw(theScreen);
}

const std::string &GameScene::GetSceneName() const {
    static std::string name;
    return name;
}

