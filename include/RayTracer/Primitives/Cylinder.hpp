/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "Abstracts/APrimitive.hpp"
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"
#include "Math/vectorOperations.hpp"

class Cylinder : public APrimitive {
    public:
        Cylinder(const std::string &name, const Point3D &baseCenter, const Vector3D &direction, Structs::Color color, 
                std::shared_ptr<AMaterial> material, double radius, double height)
            : APrimitive(name, baseCenter, color, material), direction(normalize(direction)), 
              radius(radius), height(height) {};
        ~Cylinder() = default;

        const std::string &getName(void) const override
        {
            return name;
        };

        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override
        {
            Vector3D dir = normalize(direction);
            Point3D topCenter = center + dir * height;
            Vector3D oc = r.getOrigin() - center;
            Vector3D rayDir = r.getDirection();

            double dotDirOc = dot(dir, oc);
            double dotDirRayDir = dot(dir, rayDir);

            Vector3D ocPerp = oc - dir * dotDirOc;
            Vector3D rayDirPerp = rayDir - dir * dotDirRayDir;

            double a = dot(rayDirPerp, rayDirPerp);
            double b = 2 * dot(rayDirPerp, ocPerp);
            double c = dot(ocPerp, ocPerp) - radius * radius;
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
            
            // Calcul de la normale au point d'intersection
            Vector3D projPoint = center + dir * hitHeight;
            rec.normal = normalize(hitPoint - projPoint);
            
            return true;
        }

        /* Params */
        Vector3D direction;  // Direction de l'axe du cylindre
        double radius;       // Rayon du cylindre
        double height;       // Hauteur du cylindre
};

#endif /* !CYLINDER_HPP_ */