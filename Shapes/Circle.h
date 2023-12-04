#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
   public:
    Circle() : Circle(Vec2D::Zero, 0.0f) {}
    Circle(const Vec2D& midpoint, float radius);

    inline virtual Vec2D GetCenterPoint() const override { return mPoints[0]; }
    inline float GetRadius() const { return mRadius; }
    inline void SetRadius(float radius) { mRadius = radius; }
    inline virtual void MoveTo(const Vec2D& point) override { mPoints[0] = point; }

    bool Intersects(const Circle& otherCircle) const;
    bool ContainsPoint(const Vec2D& point) const;

   private:
    float mRadius;
};

#endif  // SHAPES_CIRCLE_H