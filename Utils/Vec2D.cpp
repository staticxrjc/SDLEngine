#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;

std::ostream& operator<<(std::ostream& stream, const Vec2D& vec) {
    stream << "[" << vec.mX << ", " << vec.mY << "]";
    return stream;
}

Vec2D operator*(float scalar, const Vec2D& vec) {
    return vec * scalar;
}

bool Vec2D::operator==(const Vec2D& vec) const {
    return IsEqual(this->mX, vec.mX) && IsEqual(this->mY, vec.mY);
}

bool Vec2D::operator!=(const Vec2D& vec) const {
    return !(*this == vec);
}

Vec2D Vec2D::operator-() const {
    return {-mX, -mY};
}

Vec2D Vec2D::operator*(float scalar) const {
    return {mX * scalar, mY * scalar};
}

Vec2D Vec2D::operator/(float scalar) const {
    assert(std::fabs(scalar) > EPSILON);

    return {mX / scalar, mY / scalar};
}

Vec2D& Vec2D::operator*=(float scalar) {
    *this = *this * scalar;
    return *this;
}

Vec2D& Vec2D::operator/=(float scalar) {
    assert(std::fabs(scalar) > EPSILON);

    *this = *this / scalar;
    return *this;
}

Vec2D Vec2D::operator+(const Vec2D& vec) const {
    return {mX + vec.mX, mY + vec.mY};
}

Vec2D Vec2D::operator-(const Vec2D& vec) const {
    return {mX - vec.mX, mY - vec.mY};
}

Vec2D& Vec2D::operator+=(const Vec2D& vec) {
    *this = *this + vec;
    return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& vec) {
    *this = *this - vec;
    return *this;
}

float Vec2D::MagSq() const {
    return Dot(*this);
}

float Vec2D::Mag() const {
    return std::sqrt(MagSq());
}

Vec2D Vec2D::GetUnitVec() const {
    float mag = Mag();
    if (mag < EPSILON) return Zero;
    return *this / mag;
}

Vec2D& Vec2D::Normalize() {
    float mag = Mag();
    if (mag > EPSILON) *this /= mag;
    return *this;
}

float Vec2D::Distance(const Vec2D& vec) const {
    return (vec - *this).Mag();
}

float Vec2D::Dot(const Vec2D& vec) const {
    return mX * vec.mX + mY * vec.mY;
}

Vec2D Vec2D::ProjectOnto(const Vec2D& vec) const {
    Vec2D unit = vec.GetUnitVec();
    return Dot(unit) * unit;
}

float Vec2D::AngleBetween(const Vec2D& vec) const {
    return acosf(GetUnitVec().Dot(vec.GetUnitVec()));
}

Vec2D Vec2D::Reflect(const Vec2D& vec) const {
    return *this - 2 * ProjectOnto(vec);
}

Vec2D& Vec2D::Rotate(float angle, const Vec2D& focalPoint) {
    float cosine = cosf(angle);
    float sine = sinf(angle);
    Vec2D rotVec(mX, mY);
    rotVec -= focalPoint;
    float x = rotVec.mX * cosine - rotVec.mY * sine;
    rotVec.mY = rotVec.mX * sine + rotVec.mY * cosine;
    rotVec.mX = x;
    rotVec += focalPoint;
    *this = rotVec;
    return *this;
}

Vec2D Vec2D::GetRotatedVec(float angle, const Vec2D& focalPoint) const {
    float cosine = cosf(angle);
    float sine = sinf(angle);
    Vec2D rotVec(mX, mY);
    rotVec -= focalPoint;
    float x = rotVec.mX * cosine - rotVec.mY * sine;
    rotVec.mY = rotVec.mX * sine + rotVec.mY * cosine;
    rotVec.mX = x;
    rotVec += focalPoint;
    return rotVec;
}
