/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vectorOperations
*/

#ifndef VECTOROPERATIONS_HPP_
#define VECTOROPERATIONS_HPP_

#include "operators.hpp"
#include "vector3D.hpp"

inline double dot(const Vector3D &a, const Vector3D &b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D reflect(const Vector3D &v, const Vector3D &n)
{
    return v - 2 * dot(v, n) * n;
}

inline Vector3D unit_vector(const Vector3D &v)
{
    return v / v.length();
}

#endif /* !VECTOROPERATIONS_HPP_ */
