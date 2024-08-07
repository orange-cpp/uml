//
// Vector4.cpp
//

#include "omath/Vector4.h"

#include <algorithm>
#include <cmath>

namespace omath
{
    bool Vector4::operator==(const Vector4& src) const
    {
        return Vector3::operator==(src) && w == src.w;
    }

    bool Vector4::operator!=(const Vector4& src) const
    {
        return !(*this == src);
    }

    Vector4& Vector4::operator+=(const Vector4& v)
    {
        Vector3::operator+=(v);
        w += v.w;
        return *this;
    }

    Vector4& Vector4::operator-=(const Vector4& v)
    {
        Vector3::operator-=(v);
        w -= v.w;
        return *this;
    }

    Vector4& Vector4::operator*=(float scalar)
    {
        Vector3::operator*=(scalar);
        w *= scalar;
        return *this;
    }

    Vector4& Vector4::operator*=(const Vector4& v)
    {
        Vector3::operator*=(v);
        w *= v.w;
        return *this;
    }

    Vector4& Vector4::operator/=(float scalar)
    {
        Vector3::operator/=(scalar);
        w /= scalar;
        return *this;
    }

    Vector4& Vector4::operator/=(const Vector4& v)
    {
        Vector3::operator/=(v);
        w /= v.w;
        return *this;
    }

    float Vector4::Length() const
    {
        return std::sqrt(LengthSqr());
    }

    float Vector4::LengthSqr() const
    {
        return Vector3::LengthSqr() + w * w;
    }

    float Vector4::Dot(const Vector4& vOther) const
    {
        return Vector3::Dot(vOther) + w * vOther.w;
    }

    Vector4& Vector4::Abs()
    {
        Vector3::Abs();
        w = std::abs(w);
        return *this;
    }

    Vector4& Vector4::Clamp(const float min, const float max)
    {
        x = std::clamp(x, min, max);
        y = std::clamp(y, min, max);
        z = std::clamp(z, min, max);

        return *this;
    }

    Vector4 Vector4::operator-() const
    {
        return {-x, -y, -z, -w};
    }

    Vector4 Vector4::operator+(const Vector4& v) const
    {
        return {x + v.x, y + v.y, z + v.z, w + v.w};
    }

    Vector4 Vector4::operator-(const Vector4& v) const
    {
        return {x - v.x, y - v.y, z - v.z, w - v.w};
    }

    Vector4 Vector4::operator*(float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    Vector4 Vector4::operator*(const Vector4& v) const
    {
        return {x * v.x, y * v.y, z * v.z, w * v.w};
    }

    Vector4 Vector4::operator/(float scalar) const
    {
        return {x / scalar, y / scalar, z / scalar, w / scalar};
    }

    Vector4 Vector4::operator/(const Vector4& v) const
    {
        return {x / v.x, y / v.y, z / v.z, w / v.w};
    }

    float Vector4::Sum() const
    {
        return x + y + z + w;
    }
}
