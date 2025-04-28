/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "vector3D.hpp"
#include "ray.hpp"

double dot(const Vector3D &a, const Vector3D &b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector3D operator-(const Vector3D &v1, const Point3D &v2)
{
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

class Sphere {
    public:
        Sphere(Point3D c, double r) : center(c), radius(r) {};
        ~Sphere() = default;

        bool hits(const Ray &ray)
        {
            Vector3D oc = ray.getOrigin() - center;
            
            double a = dot(ray.getDirection(), ray.getDirection());
            double b = 2.0 * dot(oc, ray.getDirection());
            double c = dot(oc, oc) - radius * radius;

            /* Quadratic Equation */
            float discriminant = b * b - 4 * a * c;
            
            return (discriminant > 0);
        };

        Point3D center;
        double radius;
};

#endif /* !SPHERE_HPP_ */
