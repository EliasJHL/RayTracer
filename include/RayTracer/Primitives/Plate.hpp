/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Plate
*/

#ifndef PLATE_HPP_
#define PLATE_HPP_

#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"
#include "Abstracts/APrimitive.hpp"

// class Plate : public APrimitive {
//     public:
//         Plate(const Point3D &center, Structs::Color color, AMaterial *materialsx, double sy) : center(c), color(col), size_x(sx), size_y(sy) {};
//         ~Plate() = default;

//         double hits(const Ray &ray, Structs::hitRecord &hit) {
//             Vector3D normal(0, 1, 0);
//             double d = dot (normal, ray.getDirection());
//             if (std::abs(d) > 0) {
//                 double t = dot((center - ray.getOrigin()), normal) / d;
//                 if (t >= 0) {
//                     Point3D hitPoint = ray.getOrigin() + ray.getDirection() * t;
//                     if (std::abs(hitPoint.x - center.x) <= size_x / 2 &&
//                         std::abs(hitPoint.z - center.z) <= size_y / 2) {
//                         return t;
//                     }
//                 }
//             }
//             return -1.0;
//         };

//         Point3D center;
//         double size_x;
//         double size_y;
//         Structs::Color color;
// };

#endif /* !PLATE_HPP_ */
