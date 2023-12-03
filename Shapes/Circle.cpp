#include "Circle.h"
#include "../Utils/Utils.h"

Circle::Circle(const Vec2D& midpoint, float radius) : mRadius(radius) {
    mPoints.push_back(midpoint);
}

bool Circle::Intersects(const Circle& otherCircle) const {
    return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < (GetRadius() + otherCircle.GetRadius());
}

bool Circle::ContainsPoint(const Vec2D& point) const {
    return IsLessThanOrEqual(GetCenterPoint().Distance(point), GetRadius());
}
