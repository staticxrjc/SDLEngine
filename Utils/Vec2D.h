#ifndef UTILS_VEC2D_H
#define UTILS_VEC2D_H
#include <iostream>

class Vec2D {
   public:
    static const Vec2D Zero;

    Vec2D() : Vec2D(0.0f, 0.0f) {}
    Vec2D(float x, float y) : mX(x), mY(y) {}

    inline void SetX(float x) { mX = x; }
    inline void SetY(float y) { mY = y; }
    inline float GetX() const { return mX; }
    inline float GetY() const { return mY; }

    bool operator==(const Vec2D& vec) const;
    bool operator!=(const Vec2D& vec) const;

    Vec2D operator-() const;
    Vec2D operator*(float scalar) const;
    Vec2D operator/(float scalar) const;
    Vec2D& operator*=(float scalar);
    Vec2D& operator/=(float scalar);

    Vec2D operator+(const Vec2D& vec) const;
    Vec2D operator-(const Vec2D& vec) const;
    Vec2D& operator+=(const Vec2D& vec);
    Vec2D& operator-=(const Vec2D& vec);

    float MagSq() const;
    float Mag() const;

    Vec2D GetUnitVec() const;
    Vec2D& Normalize();

    float Distance(const Vec2D& vec) const;
    float Dot(const Vec2D& vec) const;

    Vec2D ProjectOnto(const Vec2D& vec) const;

    float AngleBetween(const Vec2D& vec) const;
    Vec2D Reflect(const Vec2D& vec) const;
    Vec2D& Rotate(float angle, const Vec2D& focalPoint = Vec2D::Zero);
    Vec2D GetRotatedVec(float angle, const Vec2D& focalPoint = Vec2D::Zero) const;

    friend std::ostream&
    operator<<(std::ostream& stream, const Vec2D& vec);
    friend Vec2D operator*(float scalar, const Vec2D& vec);

   private:
    float mX, mY;
};

#endif  // UTILS_VEC2D_H