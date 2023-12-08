#include "Star2D.h"
#include "Line2D.h"
#include <random>
#include "../Utils/Utils.h"

Star2D::Star2D(const Vec2D& mid, float size) : mMidpoint(mid), mSize(size) {
    Vec2D StarPoint(mMidpoint.GetX(), mMidpoint.GetY() - mSize / 2);
    mPoints.push_back(StarPoint.GetRotatedVec(mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(144.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(144.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(288.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(288.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(72.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(72.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(216.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(216.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints.push_back(StarPoint.GetRotatedVec(mRotationAngle, mMidpoint));
}

void Star2D::SetSize(float size) {
    mSize = size;
    Update();
}

void Star2D::SetRandomRotation(float max) {
    float random = float(rand() % int(max * 1000)) / 1000.0f;
    SetRotation(random);
}

void Star2D::MoveTo(const Vec2D& point) {
    SetCenterPoint(point);
    Update();
}

void Star2D::Update() {
    const float pi = 3.141592654f;
    mRotationAngle += mRotationAngleChange;
    Vec2D StarPoint(mMidpoint.GetX(), mMidpoint.GetY() - mSize / 2);
    mPoints[0] = (StarPoint.GetRotatedVec(mRotationAngle, mMidpoint));
    mPoints[1] = (StarPoint.GetRotatedVec(144.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[2] = (StarPoint.GetRotatedVec(144.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[3] = (StarPoint.GetRotatedVec(288.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[4] = (StarPoint.GetRotatedVec(288.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[5] = (StarPoint.GetRotatedVec(72.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[6] = (StarPoint.GetRotatedVec(72.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[7] = (StarPoint.GetRotatedVec(216.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[8] = (StarPoint.GetRotatedVec(216.0f * PI / 180.0f + mRotationAngle, mMidpoint));
    mPoints[9] = (StarPoint.GetRotatedVec(mRotationAngle, mMidpoint));
}
