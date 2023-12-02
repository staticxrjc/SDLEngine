#ifndef GRAPHICS_SCREEN_H
#define GRAPHICS_SCREEN_H
#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"

struct SDL_Window;
struct SDL_Surface;
class Vec2D;
class Line2D;
class Star2D;

class Screen {
   public:
    Screen() : mWidth(0), mHeight(0), moptrWindow(nullptr), mnoptrWindowSurface(nullptr) {}
    ~Screen();

    SDL_Window* Init(uint32_t width, uint32_t height, uint32_t magnification);
    void SwapScreen();

    void inline SetClearColor(const Color& color = Color::Black()) { mClearColor = color; }
    uint32_t inline Width() { return mWidth; }
    uint32_t inline Height() { return mHeight; }

    // Draw Methods Here
    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& point, const Color& color);
    void Draw(const Line2D& line, const Color& color);
    void Draw(const Star2D& star, const Color& color);

   private:
    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);

    void ClearScreen();

    uint32_t mWidth;
    uint32_t mHeight;
    uint32_t mMagnification;

    Color mClearColor;
    ScreenBuffer mBackBuffer;

    SDL_Window* moptrWindow;
    SDL_Surface* mnoptrWindowSurface;
};

#endif  // GRAPHICS_SCREEN_H