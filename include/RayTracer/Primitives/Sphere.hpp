/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Abstracts/APrimitive.hpp"
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"

class Sphere : public APrimitive {
    public:
        Sphere(Point3D c, double r, Structs::Color col) : center(c), radius(r), color(col) {};
        ~Sphere() = default;

        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override
        {
            Vector3D oc = r.getOrigin() - center;
            
            double a = dot(r.getDirection(), r.getDirection());
            double b = 2.0 * dot(oc, r.getDirection());
            double c = dot(oc, oc) - radius * radius;

            /* Quadratic Equation */
            float discriminant = b * b - 4 * a * c;

            if (discriminant > 0) {
                double t = (-b - sqrt(discriminant)) / a;
                if (t < t_max && t > t_min) {
                    rec.t = t;
                    rec.point = r.pointAtParameter(t);
                    rec.normal = (rec.point - center) / radius;
                }
                t = (-b + sqrt(discriminant)) / a;
                if (t < t_max && t > t_min) {
                    rec.t = t;
                    rec.point = r.pointAtParameter(t);
                    rec.normal = (rec.point - center) / radius;
                }
                return true;
            }
            return false;
        }

        Point3D center;
        double radius;
        Structs::Color color;
};

#endif /* !SPHERE_HPP_ */
