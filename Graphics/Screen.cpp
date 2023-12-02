#include "Screen.h"
#include "../Utils/Vec2D.h"
#include "../Shapes/Line2D.h"
#include "../Shapes/Star2D.h"
#include <SDL2/SDL.h>
#include <cassert>

Screen::~Screen() {
    if (moptrWindow) {
        SDL_DestroyWindow(moptrWindow);
        moptrWindow = nullptr;
        SDL_Quit();
    }
}

SDL_Window* Screen::Init(uint32_t width, uint32_t height, uint32_t magnification) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL_Init Failed\n";
        return nullptr;
    }

    mWidth = width;
    mHeight = height;

    moptrWindow = SDL_CreateWindow(
        "Make A Line",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        mWidth * magnification,
        mHeight * magnification,
        0);

    if (moptrWindow == nullptr) {
        std::cout << "Could not Create Window, Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    mnoptrWindowSurface = SDL_GetWindowSurface(moptrWindow);

    SDL_PixelFormat* pixelFormat = mnoptrWindowSurface->format;

    Color::InitColorFormat(pixelFormat);  // Mandatory

    mClearColor = Color::Black();

    mBackBuffer.Init(pixelFormat->format, mWidth, mHeight);

    mBackBuffer.Clear(mClearColor);

    return moptrWindow;
}

void Screen::SwapScreen() {
    assert(moptrWindow);
    if (!moptrWindow) return;
    ClearScreen();

    SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrWindowSurface, nullptr);

    SDL_UpdateWindowSurface(moptrWindow);

    mBackBuffer.Clear();
}

void Screen::Draw(int x, int y, const Color& color) {
    assert(moptrWindow);
    if (!moptrWindow) return;
    mBackBuffer.SetPixel(color, x, y);
}

void Screen::Draw(const Vec2D& point, const Color& color) {
    assert(moptrWindow);
    if (!moptrWindow) return;
    mBackBuffer.SetPixel(color, point.GetX(), point.GetY());
}

void Screen::Draw(const Line2D& line, const Color& color) {
    assert(moptrWindow);
    if (!moptrWindow) return;

    int dx, dy;

    int x0 = roundf(line.GetP0().GetX());
    int y0 = roundf(line.GetP0().GetY());
    int x1 = roundf(line.GetP1().GetX());
    int y1 = roundf(line.GetP1().GetY());

    dx = x1 - x0;
    dy = y1 - y0;

    signed const char ix((dx > 0) - (dx < 0));
    signed const char iy((dy > 0) - (dy < 0));

    dx = abs(dx) * 2;
    dy = abs(dy) * 2;

    Draw(x0, y0, color);

    if (dx >= dy) {  // Travel along x
        int d = dy - dx / 2;

        while (x0 != x1) {
            if (d >= 0) {
                d -= dx;
                y0 += iy;
            }

            d += dy;
            x0 += ix;

            Draw(x0, y0, color);
        }
    }
    else {  // Travel along y
        int d = dx - dy / 2;

        while (y0 != y1) {
            if (d >= 0) {
                d -= dy;
                x0 += ix;
            }

            d += dx;
            y0 += iy;

            Draw(x0, y0, color);
        }
    }
}

void Screen::Draw(const Star2D& star, const Color& color) {
    for (auto& side : star.GetSides()) {
        Draw(side, color);
    }
}

void Screen::ClearScreen() {
    assert(moptrWindow);
    if (!moptrWindow) return;
    SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor());
}
