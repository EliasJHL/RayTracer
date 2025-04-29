/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#include "Point3D.hpp"

namespace math {
    Point3D Point3D::operator+(const Vector3D& vec) const {
        return Point3D(X + vec.X, Y + vec.Y, Z + vec.Z);
    }

    Point3D& Point3D::operator+=(const Vector3D& vec) {
        X += vec.X;
        Y += vec.Y;
        Z += vec.Z;
        return *this;
    }

    Vector3D Point3D::operator-(const Point3D& other) const {
        return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
    }
}
