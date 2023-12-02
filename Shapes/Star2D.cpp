#include "Star2D.h"
#include "Line2D.h"

Star2D::Star2D(const Vec2D& mid, int size) : mMidpoint(mid), mSize(size) {
    mSides.push_back(Line2D());
    mSides.push_back(Line2D());
    mSides.push_back(Line2D());
    mSides.push_back(Line2D());
    mSides.push_back(Line2D());
    SetSides();
}

void Star2D::SetSize(int size) {
    mSize = size;
    SetSides();
}

void Star2D::Rotate(float rotationAngle) {
    mRotationAngle += rotationAngle;
    SetSides();
}

void Star2D::SetSides() {
    const float pi = 3.141592654f;
    std::cout << mRotationAngle << std::endl;
    Vec2D StarPoint(mMidpoint.GetX(), mMidpoint.GetY() - mSize / 2);
    mSides[0].SetP0(StarPoint.GetRotatedVec(mRotationAngle, mMidpoint));
    mSides[0].SetP1(StarPoint.GetRotatedVec(144.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[1].SetP0(StarPoint.GetRotatedVec(144.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[1].SetP1(StarPoint.GetRotatedVec(288.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[2].SetP0(StarPoint.GetRotatedVec(288.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[2].SetP1(StarPoint.GetRotatedVec(72.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[3].SetP0(StarPoint.GetRotatedVec(72.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[3].SetP1(StarPoint.GetRotatedVec(216.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[4].SetP0(StarPoint.GetRotatedVec(216.0f * pi / 180.0f + mRotationAngle, mMidpoint));
    mSides[4].SetP1(StarPoint.GetRotatedVec(mRotationAngle, mMidpoint));
}
