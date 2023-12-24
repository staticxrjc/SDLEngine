//
// Created by rcole on 12/12/23.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <string>

class GameController;

class Screen;

class IGame {
public:
    virtual ~IGame() = default;
    virtual void Init(GameController &controller) = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen &screen) = 0;
    virtual std::string GetName() const = 0;
};

#endif //ENGINE_GAME_H
