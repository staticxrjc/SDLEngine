#include "Line2D.h"
#include "../Utils/Utils.h"
#include "../Utils/Vec2D.h"
#include <cmath>

Line2D::Line2D(const Vec2D& p0, const Vec2D& p1) {
    mP0 = p0;
    mP1 = p1;
}

bool Line2D::operator==(const Line2D& line) const {
    return line.GetP0() == mP0 && line.GetP1() == mP1;
}

float Line2D::MinDistanceFrom(const Vec2D& point, bool limitToSegment) const {
    return point.Distance(ClosestPoint(point, limitToSegment));
}

Vec2D Line2D::ClosestPoint(const Vec2D& point, bool limitToSegment) const {
    Vec2D p0ToPoint = point - mP0;
    Vec2D p0ToP1 = mP1 - mP0;

    float l2 = p0ToP1.MagSq();
    float dot = p0ToPoint.Dot(p0ToP1);

    float t = dot / l2;

    if (limitToSegment) t = std::fmaxf(0.0f, std::fminf(1.0f, t));

    return mP0 + p0ToP1 * t;
}

Vec2D Line2D::Midpoint() const {
    return Vec2D((mP0.GetX() + mP1.GetX()) / 2.0f, (mP0.GetY() + mP1.GetY() / 2.0f));
}

float Line2D::Slope() const {
    float dx = mP0.GetX() - mP1.GetX();
    if (fabsf(dx) < EPSILON) return 0;

    return (mP0.GetY() - mP1.GetY()) / dx;
}

float Line2D::Length() const {
    return mP1.Distance(mP0);
}
