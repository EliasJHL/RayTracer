/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include "Abstracts/AMaterial.hpp"
#include "Math/vectorOperations.hpp"

class Metal : public AMaterial{
    public:
        Metal(const std::string &n = "metal") {
            name = n;
        };
        ~Metal() = default;

        bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const
        {
            Vector3D reflected = reflect(unit_vector(rayIn.getDirection()), rec.normal);
            scattered = Ray(rec.point, reflected);
            Vector3D objectColor = Vector3D(rec.color.r / 255.0, rec.color.g / 255.0, rec.color.b / 255.0);
            attenuation = objectColor;
            return true;
        };
};

#endif /* !METAL_HPP_ */
