#ifndef SHAPES_TRIANGLE_H
#define SHAPES_TRIANGLE_H
#include "Shape.h"
#include "../Utils/Vec2D.h"

class Triangle : public Shape {
   public:
    Triangle() : Triangle(Vec2D::Zero, Vec2D::Zero, Vec2D::Zero) {}
    Triangle(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2);

    inline void SetP0(const Vec2D& p0) { mPoints[0] = p0; }
    inline void SetP1(const Vec2D& p1) { mPoints[1] = p1; }
    inline void SetP2(const Vec2D& p2) { mPoints[2] = p2; }

    inline Vec2D GetP0() const { return mPoints[0]; }
    inline Vec2D GetP1() const { return mPoints[1]; }
    inline Vec2D GetP2() const { return mPoints[2]; }

    Vec2D GetCenterPoint() const override;
    virtual void MoveTo(const Vec2D& point) override;

    float Area() const;

    bool ContainsPoint(const Vec2D& point) const;

   private:
    float Area(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2) const;
};
#endif  // SHAPES_TRIANGLE_H