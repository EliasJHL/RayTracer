/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "../Math/Point3D.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {
    class Ray {
    public:
        math::Point3D origin;
        math::Vector3D direction;

        Ray() = default;
        Ray(const math::Point3D& origin, const math::Vector3D& direction)
            : origin(origin), direction(direction) {}
    };
}

#endif /* !RAY_HPP_ */
