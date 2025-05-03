/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** APrimitive
*/

#ifndef APRIMITIVE_HPP_
#define APRIMITIVE_HPP_

#include "Interfaces/IPrimitive.hpp"
#include "Math/vector3D.hpp"
#include "Abstracts/AMaterial.hpp"

class APrimitive : public IPrimitive {
    public:
        APrimitive(const Point3D &c = Point3D(0,0,0), Structs::Color col = Structs::Color{255,255,255}, AMaterial *mat = nullptr) : 
            center(c), color(col), material(mat) {};
        virtual ~APrimitive() = default;
        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override = 0;

        /* Primitive's common data */
        Point3D center;
        Structs::Color color;
        AMaterial *material;
};

#endif /* !APRIMITIVE_HPP_ */
