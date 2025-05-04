/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** AMaterial
*/

#ifndef AMATERIAL_HPP_
#define AMATERIAL_HPP_

#include "Math/ray.hpp"
#include "Utils/structs.hpp"
#include "Interfaces/IMaterial.hpp"

class AMaterial : public IMaterial {
    public:
        AMaterial(const std::string &name = "") {};
        virtual ~AMaterial() = default;
        bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const = 0;
        
        std::string name;
};

#endif /* !AMATERIAL_HPP_ */
