#ifndef SHAPES_STAR2D_H
#define SHAPES_STAR2D_H
#include <vector>
#include "../Utils/Vec2D.h"
#include "Shape.h"

class Line2D;

class Star2D : public Shape {
   public:
    Star2D() : Star2D(Vec2D::Zero, 0) {}
    Star2D(const Vec2D& mid, float size);

    void SetSize(float size);
    inline void SetRotation(float rotation) { mRotationAngleChange = rotation; }
    void SetRandomRotation(float max = 3.0f);
    inline void SetCenterPoint(const Vec2D& point) { mMidpoint = point; }
    void Update();

    inline virtual Vec2D GetCenterPoint() const override { return mMidpoint; }
    inline float GetSize() const { return mSize; }

    virtual void MoveTo(const Vec2D& point) override;

   private:
    Vec2D mMidpoint;
    float mSize;
    float mRotationAngle = 0.0f;
    float mRotationAngleChange = 0.0f;
};

#endif  // SHAPES_STAR2D_H