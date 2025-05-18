/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "Abstracts/APrimitive.hpp"
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"
#include "Math/vectorOperations.hpp"

class Triangle : public APrimitive {
    public:
        Triangle(const std::string &name, const Point3D &v0, const Point3D &v1, const Point3D &v2, 
                Structs::Color color, std::shared_ptr<AMaterial> material)
            : APrimitive(name, calculateCenter(v0, v1, v2), color, material), 
              v0(v0), v1(v1), v2(v2)
        {
            Vector3D edge1 = v1 - v0;
            Vector3D edge2 = v2 - v0;
            normal = normalize(cross(edge1, edge2));
        };
        
        ~Triangle() = default;

        const std::string &getName(void) const override
        {
            return name;
        };

        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override
        {
            Vector3D edge1 = v1 - v0;
            Vector3D edge2 = v2 - v0;
            Vector3D h = cross(r.getDirection(), edge2);
            double a = dot(edge1, h);
            
            if (a > -1e-8 && a < 1e-8)
                return false;
                
            double f = 1.0 / a;
            Vector3D s = r.getOrigin() - v0;
            double u = f * dot(s, h);
            
            if (u < 0.0 || u > 1.0)
                return false;
                
            Vector3D q = cross(s, edge1);
            double v = f * dot(r.getDirection(), q);
            
            if (v < 0.0 || u + v > 1.0)
                return false;
                
            double t = f * dot(edge2, q);
            
            if (t < t_min || t > t_max)
                return false;
                
            rec.t = t;
            rec.point = r.pointAtParameter(t);
            rec.normal = normal;
            rec.material = material;
            rec.color = color;
            
            return true;
        }

    private:
        Point3D calculateCenter(const Point3D &v0, const Point3D &v1, const Point3D &v2) const
        {
            return Point3D(
                (v0.x + v1.x + v2.x) / 3.0,
                (v0.y + v1.y + v2.y) / 3.0,
                (v0.z + v1.z + v2.z) / 3.0
            );
        }

        /* Params */
        Point3D v0, v1, v2;  // Les trois sommets du triangle
        Vector3D normal;     // Normale au plan du triangle
};

#endif /* !TRIANGLE_HPP_ */