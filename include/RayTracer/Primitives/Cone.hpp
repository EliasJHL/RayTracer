/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "Abstracts/APrimitive.hpp"
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"
#include "Math/vectorOperations.hpp"

class Cone : public APrimitive {
    public:
        Cone(const Point3D &apex, const Vector3D &direction, Structs::Color color, 
             std::shared_ptr<AMaterial> material, double radius, double height)
            : APrimitive(apex, color, material), direction(normalize(direction)), 
              radius(radius), height(height) {};
        ~Cone() = default;

        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override
        {
            Vector3D dir = normalize(direction);
            Point3D baseCenter = center + dir * height;
            double cosTheta = height / sqrt(height * height + radius * radius);
            double k = radius / height;
            Vector3D oc = r.getOrigin() - center;
            Vector3D rayDir = r.getDirection();
            double dotDirV = dot(rayDir, dir);
            double dotOcV = dot(oc, dir);
            double a = dot(rayDir, rayDir) - (1 + k*k) * dotDirV * dotDirV;
            double b = 2 * (dot(rayDir, oc) - (1 + k*k) * dotDirV * dotOcV);
            double c = dot(oc, oc) - (1 + k*k) * dotOcV * dotOcV;
            double discriminant = b * b - 4 * a * c;
            
            if (discriminant < 0)
                return false;
                
            double t = (-b - sqrt(discriminant)) / (2 * a);
            if (t < t_min || t > t_max) {
                t = (-b + sqrt(discriminant)) / (2 * a);
                if (t < t_min || t > t_max)
                    return false;
            }
            
            Point3D hitPoint = r.pointAtParameter(t);
            Vector3D hitVector = hitPoint - center;

            double hitHeight = dot(hitVector, dir);
            if (hitHeight < 0 || hitHeight > height)
                return false;
                
            rec.t = t;
            rec.point = hitPoint;
            rec.material = material;
            rec.color = color;
            
            Vector3D cp = hitPoint - center;
            double projLength = dot(cp, dir);
            Vector3D projPoint = center + dir * projLength;
            rec.normal = normalize(hitPoint - projPoint);
            
            return true;
        }

        /* Params */
        Vector3D direction;  // Direction from apex to base center
        double radius;       // Radius at the base
        double height;       // Height of the cone
};

#endif /* !CONE_HPP_ */