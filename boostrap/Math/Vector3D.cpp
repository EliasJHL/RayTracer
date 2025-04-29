/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#include "Vector3D.hpp"

namespace math {
    double Vector3D::length() const
    {
        return std::sqrt(X * X + Y * Y + Z * Z);
    }

    double Vector3D::dot(const Vector3D& other) const
    {
        return X * other.X + Y * other.Y + Z * other.Z;
    }

    Vector3D Vector3D::operator+(const Vector3D& other) const
    {
        return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
    }

    Vector3D& Vector3D::operator+=(const Vector3D& other)
    {
        X += other.X;
        Y += other.Y;
        Z += other.Z;
        return *this;
    }

    Vector3D Vector3D::operator-(const Vector3D& other) const
    {
        return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
    }

    Vector3D& Vector3D::operator-=(const Vector3D& other)
    {
        X -= other.X;
        Y -= other.Y;
        Z -= other.Z;
        return *this;
    }

    Vector3D Vector3D::operator*(const Vector3D& other) const
    {
        return Vector3D(X * other.X, Y * other.Y, Z * other.Z);
    }

    Vector3D& Vector3D::operator*=(const Vector3D& other)
    {
        X *= other.X;
        Y *= other.Y;
        Z *= other.Z;
        return *this;
    }

    Vector3D Vector3D::operator/(const Vector3D& other) const
    {
        return Vector3D(X / other.X, Y / other.Y, Z / other.Z);
    }

    Vector3D& Vector3D::operator/=(const Vector3D& other)
    {
        X /= other.X;
        Y /= other.Y;
        Z /= other.Z;
        return *this;
    }

    Vector3D Vector3D::operator*(double scalar) const
    {
        return Vector3D(X * scalar, Y * scalar, Z * scalar);
    }

    Vector3D& Vector3D::operator*=(double scalar)
    {
        X *= scalar;
        Y *= scalar;
        Z *= scalar;
        return *this;
    }

    Vector3D Vector3D::operator/(double scalar) const
    {
        return Vector3D(X / scalar, Y / scalar, Z / scalar);
    }

    Vector3D& Vector3D::operator/=(double scalar)
    {
        X /= scalar;
        Y /= scalar;
        Z /= scalar;
        return *this;
    }

    Vector3D operator*(double scalar, const Vector3D& vec)
    {
        return vec * scalar;
    }
}
