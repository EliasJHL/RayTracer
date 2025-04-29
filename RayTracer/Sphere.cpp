/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#include "Sphere.hpp"

namespace RayTracer {
    bool Sphere::hits(const Ray& ray) const {
        math::Vector3D oc = ray.origin - center;

        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * oc.dot(ray.direction);
        double c = oc.dot(oc) - radius * radius;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return false;
        return discriminant >= 0;
    }
}