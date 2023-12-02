#include "ScreenBuffer.h"
#include <SDL2/SDL.h>
#include <cassert>

ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer) {
    mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);

    SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
}

ScreenBuffer::~ScreenBuffer() {
    if (mSurface) SDL_FreeSurface(mSurface);
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer) {
    if (&screenBuffer == this) return *this;

    if (mSurface != nullptr) {
        SDL_FreeSurface(mSurface);
        mSurface = nullptr;
    }

    if (screenBuffer.mSurface != nullptr) {
        mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);
        SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height) {
    mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
    Clear();
}

void ScreenBuffer::Clear(const Color& color) {
    assert(mSurface);
    if (!mSurface) return;
    SDL_FillRect(mSurface, nullptr, color.GetPixelColor());
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y) {
    assert(mSurface);
    if (!(mSurface && y < mSurface->h && y >= 0 && x >= 0 && x < mSurface->w)) return;
    SDL_LockSurface(mSurface);

    uint32_t* pixels = (uint32_t*)mSurface->pixels;

    size_t index = GetIndex(y, x);

    pixels[index] = color.GetPixelColor();

    SDL_UnlockSurface(mSurface);
}

size_t ScreenBuffer::GetIndex(int r, int c) {
    assert(mSurface);
    if (!mSurface) return 0;
    return r * mSurface->w + c;
}
