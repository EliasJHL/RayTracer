/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "Math/vector3D.hpp"
#include "Math/ray.hpp"

class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const = 0;
};

#endif /* !IPRIMITIVE_HPP_ */