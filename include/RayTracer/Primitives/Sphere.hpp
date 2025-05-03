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
#include "Math/vectorOperations.hpp"

class Sphere : public APrimitive {
    public:
        Sphere(const Point3D &center, Structs::Color color, AMaterial *material, double radius)
            : APrimitive(center, color, material), radius(radius) {};
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
                double t = (-b - sqrt(discriminant)) / (2 * a);
                if (t < t_max && t > t_min) {
                    rec.t = t;
                    rec.point = r.pointAtParameter(t);
                    rec.material = material;
                    rec.color = color;
                    rec.normal = (rec.point - center) / radius;
                    return true;
                }
                t = (-b + sqrt(discriminant)) / (2 * a);
                if (t < t_max && t > t_min) {
                    rec.t = t;
                    rec.point = r.pointAtParameter(t);
                    rec.material = material;
                    rec.color = color;
                    rec.normal = (rec.point - center) / radius;
                    return true;
                }
            }
            return false;
        }

        /* Params */
        double radius;
};

#endif /* !SPHERE_HPP_ */
