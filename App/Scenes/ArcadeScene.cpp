#include "ArcadeScene.h"
#include "../../Graphics/Screen.h"
#include "../../Shapes/Line2D.h"
#include "../../Shapes/AARectangle.h"
#include "../../Shapes/Triangle.h"
#include "../../Shapes/Circle.h"
#include "../../Graphics/Color.h"
#include "../Input/GameController.h"
#include <iostream>

ArcadeScene::ArcadeScene() {
}

void ArcadeScene::Init() {
    ButtonAction action;
    action.key = GameController::ActionKey();
    action.action = [](uint32_t dt, InputState state) {
        if (GameController::IsPressed(state))
            std::cout << "Action Button Pressed!\n";
    };

    mGameController.AddInputActionForKey(action);

    MouseButtonAction mouseButtonAction;
    mouseButtonAction.mouseButton = GameController::LeftMouseButton();
    mouseButtonAction.mouseInputAction = [](InputState state, const MousePosition &position) {
        if (GameController::IsPressed(state))
            std::cout << "Left Mouse Button Pressed!\n";
    };

    mGameController.AddMouseButtonAction(mouseButtonAction);

    mGameController.SetMouseMovedAction([](const MousePosition &position) {
        std::cout << "Mouse Position X: " << position.xPos << "\nMouse Position Y: " << position.yPos << "\n";
    });
}

void ArcadeScene::Update(uint32_t dt) {
}

void ArcadeScene::Draw(Screen &theScreen) {
    Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
    AARectangle rectangle = {Vec2D(theScreen.Width() / 2 - 25, theScreen.Height() / 2 - 25), 50, 50};
    Circle circle = {Vec2D(theScreen.Width() / 2.0f + 50.0f, theScreen.Height() / 2.0f + 50.0f), 50.0f};
    rectangle.MoveTo(Vec2D(0.0f, 0.0f));
    theScreen.Draw(triangle, Color::Red(), true, Color::Red());
    theScreen.Draw(rectangle, Color::Blue(), true, Color::Blue());
    theScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
    theScreen.Draw(triangle.GetCenterPoint(), Color::Cyan());
    theScreen.Draw(rectangle.GetCenterPoint(), Color::Cyan());
    theScreen.Draw(circle.GetCenterPoint(), Color::Cyan());
}

const std::string &ArcadeScene::GetSceneName() const {
    static std::string sceneName = "Arcade Scene";
    return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game) {
    switch (game) {
        case TETRIS: {
        }
            break;
        case BREAK_OUT: {
        }
            break;
        case ASTEROIDS: {
        }
            break;
        case PACMAN: {
        }
            break;
        case CHESS: {
        }
            break;
        default: {
        }
            break;
    }
    return nullptr;
}
