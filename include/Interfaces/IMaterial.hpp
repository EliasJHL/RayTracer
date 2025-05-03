/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "IPrimitive.hpp"
#include "Utils/structs.hpp"

class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const = 0;
 
};

#endif /* !IMATERIAL_HPP_ */
