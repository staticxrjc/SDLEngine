#ifndef GRAPHICS_SCREENBUFFER_H
#define GRAPHIACS_SCREENBUFFER_H
#include <iostream>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer {
   public:
    ScreenBuffer() : mSurface(nullptr) {}
    ScreenBuffer(const ScreenBuffer& screenBuffer);
    ~ScreenBuffer();

    ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

    void Init(uint32_t format, uint32_t width, uint32_t height);

    inline SDL_Surface* GetSurface() { return mSurface; }

    void Clear(const Color& color = Color::Black());

    void SetPixel(const Color& color, int x, int y);

   private:
    SDL_Surface* mSurface;

    size_t GetIndex(int r, int c);
};

#endif  // GRAPHICS_SCREENBUFFER_H