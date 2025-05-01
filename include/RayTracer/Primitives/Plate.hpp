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

class Plate {
    public:
        Plate();
        ~Plate();

        bool intersect(const Ray &ray, Point3D &intersection) const;

        Point3D center;
        double size_x;
        double size_y;
        Structs::Color color;
};

#endif /* !PLATE_HPP_ */
