#ifndef APP_APP_H
#define APP_APP_H

#include "../Graphics/Screen.h"
#include <cstdint>
#include <memory>
#include "Scenes/Scene.h"
#include "Input/InputController.h"

struct SDL_Window;

class App {
public:
    static App &Singleton();
    bool Init(uint32_t width, uint32_t height, uint32_t magnification);
    void Run();

    inline uint32_t Width() const { return mScreen.Width(); }

    inline uint32_t Height() const { return mScreen.Height(); }

    void PushScene(std::unique_ptr<Scene> scene);
    void PopScene();
    Scene *TopScene();  // current scene

private:
    Screen mScreen;
    SDL_Window *mnoptrWindow;

    std::vector<std::unique_ptr<Scene>> mSceneStack;
    InputController mInputController;
};

#endif  // APP_APP_H