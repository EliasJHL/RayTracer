/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#include "Rectangle.hpp"

namespace RayTracer
{
    math::Point3D Rectangle3D::pointAt(double u, double v) const
    {
        return origin + bottom_side * u + left_side * v;
    }
}
