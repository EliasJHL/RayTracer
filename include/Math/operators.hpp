/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** operators
*/

#ifndef OPERATORS_HPP_
#define OPERATORS_HPP_

#include "Math/vector3D.hpp"

/*
** inline sert à déclarer qu'il peut il y avoir plusieurs définitions de la fonction
*/

inline Vector3D operator*(double t, const Vector3D &v)
{
    return Vector3D(v.x * t, v.y * t, v.z * t);
}

inline Vector3D operator+(const Vector3D &v1, const Vector3D &v2)
{
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vector3D operator-(const Vector3D &v1, const Point3D &v2)
{
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline double dot(const Vector3D &a, const Vector3D &b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

#endif /* !OPERATORS_HPP_ */
