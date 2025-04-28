/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vector3D
*/

#include "vector3D.hpp"

/* Operations */
Vector3D &Vector3D::operator+(const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D &Vector3D::operator*=(const Vector3D &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vector3D &Vector3D::operator/=(const Vector3D &v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

Vector3D &Vector3D::operator*(const Vector3D &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vector3D &Vector3D::operator*=(const double t)
{
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

Vector3D &Vector3D::operator/=(const double t)
{
    x /= t;
    y /= t;
    z /= t;
    return *this;
};

Vector3D &Vector3D::operator*(const double t)
{
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

/* Get Data */
double Vector3D::length(void) const 
{
    return std::sqrt(length_sqrt());
}

double Vector3D::length_sqrt(void) const
{
    return ((x * x) + (y * y) + (z * z));
}