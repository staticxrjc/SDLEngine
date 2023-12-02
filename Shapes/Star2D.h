#ifndef SHAPES_STAR2D_H
#define SHAPES_STAR2D_H
#include <vector>
#include "../Utils/Vec2D.h"

class Line2D;

class Star2D {
   public:
    Star2D() : Star2D(Vec2D::Zero, 0) {}
    Star2D(const Vec2D& mid, int size);

    void SetSize(int size);
    void Rotate(float rotationAngle);
    inline std::vector<Line2D> GetSides() const { return mSides; }

   private:
    void SetSides();
    std::vector<Line2D> mSides;
    Vec2D mMidpoint;
    int mSize;
    float mRotationAngle = 0.0f;
};

#endif  // SHAPES_STAR2D_H