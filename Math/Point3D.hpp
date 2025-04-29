/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_
#include <cmath>
#include <iostream>
#include <ostream>
#include "Vector3D.hpp"

namespace math {
    class Point3D {
    public:
        double X;
        double Y;
        double Z;

        Point3D() = default;

        Point3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

        Point3D operator+(const Vector3D& vec) const;
        Point3D& operator+=(const Vector3D& vec);

        Vector3D operator-(const Point3D& other) const;
    };
}

#endif /* !POINT3D_HPP_ */
