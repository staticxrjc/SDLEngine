#include "AARectangle.h"
#include "../Utils/Utils.h"
#include <cmath>

AARectangle::AARectangle(const Vec2D& topLeft, int width, int height) {
    Vec2D bottomRight(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1);
    mPoints.push_back(topLeft);
    mPoints.push_back(bottomRight);
}

AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight) {
    mPoints.push_back(topLeft);
    mPoints.push_back(bottomRight);
}

float AARectangle::GetWidth() const {
    return GetBottomRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}

float AARectangle::GetHeight() const {
    return GetBottomRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

void AARectangle::MoveTo(const Vec2D& position) {
    float width = GetWidth();
    float height = GetHeight();

    SetTopLeftPoint(position);
    SetBottomRightPoint(Vec2D(position.GetX() + width - 1.0f, position.GetY() + height - 1.0f));
}

Vec2D AARectangle::GetCenterPoint() const {
    return Vec2D(GetTopLeftPoint().GetX() + GetWidth() / 2.0f, GetTopLeftPoint().GetY() + GetHeight() / 2.0f);
}

bool AARectangle::Intersects(const AARectangle& otherRect) const {
    return !(
        otherRect.GetBottomRightPoint().GetX() < GetTopLeftPoint().GetX() ||
        otherRect.GetTopLeftPoint().GetX() > GetBottomRightPoint().GetX() ||
        otherRect.GetBottomRightPoint().GetY() < GetTopLeftPoint().GetY() ||
        otherRect.GetTopLeftPoint().GetY() > GetBottomRightPoint().GetY());
}

bool AARectangle::ContainsPoint(const Vec2D& point) const {
    bool withinX = point.GetX() >= GetTopLeftPoint().GetX() && point.GetX() <= GetBottomRightPoint().GetX();
    bool withinY = point.GetY() >= GetTopLeftPoint().GetY() && point.GetY() <= GetBottomRightPoint().GetY();
    return withinX && withinY;
}

AARectangle AARectangle::Inset(const AARectangle& rect, const Vec2D& insets) {
    return AARectangle(rect.GetTopLeftPoint() + insets, rect.GetWidth() - 2 * insets.GetX(), rect.GetHeight() - 2 * insets.GetY());
}

std::vector<Vec2D> AARectangle::GetPoints() const {
    std::vector<Vec2D> lPoints;

    lPoints.push_back(mPoints[0]);
    lPoints.push_back(Vec2D(mPoints[1].GetX(), mPoints[0].GetY()));
    lPoints.push_back(mPoints[1]);
    lPoints.push_back(Vec2D(mPoints[0].GetX(), mPoints[1].GetY()));

    return lPoints;
}
