/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"

class Sphere {
    public:
        Sphere(Point3D c, double r, Structs::Color col) : center(c), radius(r), color(col) {};
        ~Sphere() = default;

        double hits(const Ray &ray, HitRecord &hit)
        {
            Vector3D oc = ray.getOrigin() - center;
            
            double a = dot(ray.getDirection(), ray.getDirection());
            double b = 2.0 * dot(oc, ray.getDirection());
            double c = dot(oc, oc) - radius * radius;

            /* Quadratic Equation */
            float discriminant = b * b - 4 * a * c;

            if (discriminant < 0)
                return -1.0;
            return (-b - sqrt(discriminant)) / (2 * a);
        };

        Point3D center;
        double radius;
        Structs::Color color;
};

#endif /* !SPHERE_HPP_ */
