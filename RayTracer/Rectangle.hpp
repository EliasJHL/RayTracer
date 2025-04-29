/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "../Math/Point3D.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {
    class Rectangle3D {
    public:
        math::Point3D origin;
        math::Vector3D bottom_side;
        math::Vector3D left_side;

        Rectangle3D() = default;
        Rectangle3D(const math::Point3D& origin, 
                   const math::Vector3D& bottom_side, 
                   const math::Vector3D& left_side)
            : origin(origin), bottom_side(bottom_side), left_side(left_side) {}

        math::Point3D pointAt(double u, double v) const;
    };
}

#endif /* !RECTANGLE3D_HPP_ */
