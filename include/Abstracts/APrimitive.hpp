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

class APrimitive : public IPrimitive {
    public:
        APrimitive() {};
        virtual ~APrimitive() = default;
        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override = 0;

        /* Primitive's common data */
        Vector3D center;
};

#endif /* !APRIMITIVE_HPP_ */
