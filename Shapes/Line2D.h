#ifndef SHAPES_LINE2D_H
#define SHAPES_LINE2D_H

#include "../Utils/Vec2D.h"

class Line2D {
   public:
    Line2D() : Line2D(Vec2D::Zero, Vec2D::Zero) {}
    Line2D(float x0, float y0, float x1, float y1) : Line2D(Vec2D(x0, y0), Vec2D(x1, y1)) {}
    Line2D(const Vec2D& p0, const Vec2D& p1);

    inline const Vec2D& GetP0() const { return mP0; }
    inline const Vec2D& GetP1() const { return mP1; }

    inline void SetP0(const Vec2D& point) { mP0 = point; }
    inline void SetP1(const Vec2D& point) { mP1 = point; }

    bool operator==(const Line2D& line) const;

    float MinDistanceFrom(const Vec2D& point, bool limitToSegment = false) const;

    Vec2D ClosestPoint(const Vec2D& point, bool limitToSegment = false) const;

    Vec2D Midpoint() const;
    float Slope() const;
    float Length() const;

   private:
    Vec2D mP0;
    Vec2D mP1;
};

#endif  // SHAPES_LINE2D_H