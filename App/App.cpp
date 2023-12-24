#include "App.h"
#include <SDL2/SDL.h>
#include "../Utils/Vec2D.h"
#include "./Scenes/ArcadeScene.h"
#include <cassert>

App &App::Singleton() {
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t magnification) {
    mWindow = mScreen.Init(width, height, magnification);

    std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
    PushScene(std::move(arcadeScene));

    return mWindow != nullptr;
}

void App::Run() {
    if (!mWindow) return;
    Vec2D screenCenter = {float(mScreen.Width()) / 2.0f, float(mScreen.Height()) / 2.0f};

    bool running = true;

    uint32_t lastTick = SDL_GetTicks();
    uint32_t currentTick;

    uint32_t dt = 10;
    uint32_t accumulator = 0;

    mInputController.Init([&running](uint32_t dt, InputState state) {
        running = false;
    });

    while (running) {
        currentTick = SDL_GetTicks();
        uint32_t frameTime = currentTick - lastTick;

        if (frameTime > 300) frameTime = 300;

        lastTick = currentTick;

        accumulator += frameTime;

        // Input
        mInputController.Update(dt);

        Scene *topScene = TopScene();

        if (topScene) {
            // Update
            while (accumulator >= dt) {
                // update current scene by dt
                topScene->Update(dt);
                accumulator -= dt;
            }

            // Render
            topScene->Draw(mScreen);
        }

        mScreen.SwapScreen();
    }
}

void App::PushScene(std::unique_ptr<Scene> scene) {
    assert(scene);
    scene->Init();
    mInputController.SetGameController(scene->GetGameController());
    mSceneStack.emplace_back(std::move(scene));
    setWindowTitle();
}

void App::PopScene() {
    if (mSceneStack.empty()) return;
    mSceneStack.pop_back();
    setWindowTitle();
}

Scene *App::TopScene() {
    if (mSceneStack.empty()) return nullptr;

    return mSceneStack.back().get();
}

void App::setWindowTitle() {
    Scene *topScene = TopScene();
    if (topScene)
        SDL_SetWindowTitle(mWindow, topScene->GetSceneName().c_str());
}
