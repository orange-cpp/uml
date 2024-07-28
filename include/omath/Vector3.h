//
// Created by vlad on 10/28/23.
//

#pragma once

#include <cstdint>
#include <functional>

namespace omath
{
    class Vector3 {
    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        Vector3(const float x, const float y, const float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        Vector3() = default;

        bool operator==(const Vector3& src) const;
        bool operator!=(const Vector3& src) const;

        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);
        Vector3& operator*=(float fl);
        Vector3& operator*=(const Vector3& v);
        Vector3& operator/=(const Vector3& v);
        Vector3& operator+=(float fl);
        Vector3& operator/=(float fl);
        Vector3& operator-=(float fl);

        [[nodiscard]] float DistTo(const Vector3& vOther) const;
        Vector3& Abs();
        [[nodiscard]] float DistToSqr(const Vector3& vOther) const;
        [[nodiscard]] float Dot(const Vector3& vOther) const;
        [[nodiscard]] float Length() const;
        [[nodiscard]] float LengthSqr() const;
        [[nodiscard]] float Length2D() const;

        Vector3 operator-() const;
        Vector3 operator+(const Vector3& v) const;
        Vector3 operator-(const Vector3& v) const;
        Vector3 operator*(float fl) const;
        Vector3 operator*(const Vector3& v) const;
        Vector3 operator/(float fl) const;
        Vector3 operator/(const Vector3& v) const;

        template<class type>
        const type& As() const
        {
            return *reinterpret_cast<const type*>(this);
        }
        template<class type>
        type& As()
        {
            return *reinterpret_cast<type*>(this);
        }

        [[nodiscard]] Vector3 Cross(const Vector3 &v) const;
        [[nodiscard]] static Vector3 CreateVelocity(float pitch, float yaw, float speed);
        [[nodiscard]] float  Sum() const;
        [[nodiscard]] float  Sum2D() const;
        [[nodiscard]] Vector3 ViewAngleTo(const Vector3& other) const;

        [[nodiscard]] static Vector3 ForwardVector(float pitch, float yaw);
        [[nodiscard]] static Vector3 RightVector(float pitch, float yaw, float roll);
        [[nodiscard]] static Vector3 UpVector(float pitch, float yaw, float roll);


        [[nodiscard]]
        Vector3 Normalized() const;
    };
}
// ReSharper disable once CppRedundantNamespaceDefinition
namespace std
{
    template<>
    struct hash<omath::Vector3>
    {
        std::size_t operator()(const omath::Vector3& vec) const noexcept
        {
            std::size_t hash = 0;
            constexpr std::hash<float> hasher;

            hash ^= hasher(vec.x) + 0x9e3779b9 + (hash<<6) + (hash>>2);
            hash ^= hasher(vec.y) + 0x9e3779b9 + (hash<<6) + (hash>>2);
            hash ^= hasher(vec.z) + 0x9e3779b9 + (hash<<6) + (hash>>2);

            return hash;
        }
    };
}
