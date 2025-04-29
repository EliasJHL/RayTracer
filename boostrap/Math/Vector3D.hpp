/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_
#include <cmath>
#include <iostream>
#include <ostream>

namespace math {
    class Vector3D {
    public:
        double X;
        double Y;
        double Z;

        Vector3D() = default;
        Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}
        double length() const;
        double dot(const Vector3D& other) const;
        Vector3D operator+(const Vector3D& other) const;
        Vector3D& operator+=(const Vector3D& other);
        Vector3D operator-(const Vector3D& other) const;
        Vector3D& operator-=(const Vector3D& other);
        Vector3D operator*(const Vector3D& other) const;
        Vector3D& operator*=(const Vector3D& other);
        Vector3D operator/(const Vector3D& other) const;
        Vector3D& operator/=(const Vector3D& other);
        Vector3D operator*(double scalar) const;
        Vector3D& operator*=(double scalar);
        Vector3D operator/(double scalar) const;
        Vector3D& operator/=(double scalar);
    };
    Vector3D operator*(double scalar, const Vector3D& vec);
}


#endif /* !VECTOR3D_HPP_ */
