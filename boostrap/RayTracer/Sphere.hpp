/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_
#include "../Math/Point3D.hpp"
#include "../Math/Vector3D.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class Sphere {
    public:
        math::Point3D center;
        double radius;
        Sphere(const math::Point3D& center, double radius)
            : center(center), radius(radius) {}
        bool hits(const Ray& ray) const;
    };
}

#endif /* !SPHERE_HPP_ */
