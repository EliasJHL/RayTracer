/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Plane
*/

#ifndef Plane_HPP_
#define Plane_HPP_

#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"
#include "Abstracts/APrimitive.hpp"
#include "Math/vectorOperations.hpp"
#include <cmath>

enum Axis {
    X = 0,
    Y = 1,
    Z = 2
};

class Plane : public APrimitive {
    public:
        Plane(const Point3D &center, Structs::Color color, std::shared_ptr<AMaterial> material, Axis axe)
            : APrimitive(center, color, material), axis(axe)
        {
            if (axis == Axis::X)
                normal = Vector3D(1, 0, 0);
            if (axis == Axis::Y)
                normal = Vector3D(0, 1, 0);
            if (axis == Axis::Z)
                normal = Vector3D(0, 0, 1);
        };
        ~Plane() = default;

        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override
        {
            /* Linear Equation */
            double denom = dot(normal, r.getDirection());
            
            if (fabs(denom) < 1e-8)
                return false;
            
            double t = dot(center - r.getOrigin(), normal) / denom;

            if (t < t_min || t > t_max) {
                return false;
            }
            
            rec.t = t;
            rec.point = r.pointAtParameter(t);
            rec.material = material;    
            rec.color = color;

            if (dot(r.getDirection(), normal) < 0) {
                rec.normal = normal;
            } else {
                rec.normal = -normal;
            }
            
            return true;
        }

        Axis axis;
        Vector3D normal;
};

#endif /* !Plane_HPP_ */
