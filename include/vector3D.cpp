/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vector3D
*/

#include "vector3D.hpp"

/* Operations */
Vector3D &Vector3D::operator+=(const Vector3D &v)
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

Vector3D &Vector3D::operator/(const Vector3D &v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
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

/* TO REMOVE FROM HERE */
Vector3D operator*(double t, const Vector3D &v)
{
    return Vector3D(v.x * t, v.y * t, v.z * t);
}

Vector3D operator+(const Vector3D &v1, const Vector3D &v2)
{
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

/* ------------------------------ */

Vector3D &Vector3D::operator/(const double a)
{
    x /= a;
    y /= a;
    z /= a;
    return *this;
};

/* Get Data */
double Vector3D::length(void) const 
{
    return std::sqrt(length_sqrt());
}

double Vector3D::length_sqrt(void) const
{
    return ((x * x) + (y * y) + (z * z));
}