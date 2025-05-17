/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Flatcolor
*/

#ifndef FLATCOLOR_HPP_
#define FLATCOLOR_HPP_

#include "Abstracts/AMaterial.hpp"
#include "Math/vectorOperations.hpp"
#include "Math/materialOperations.hpp"

class Flatcolor : public AMaterial {
    public:
        Flatcolor(const std::string &n = "flatcolor") {
            name = n;
        };
        ~Flatcolor() = default;

        bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const
        {
            attenuation = Vector3D((rec.color.r / 255), (rec.color.g / 255), (rec.color.b / 255));
        
            return false;
        };
};

#endif /* !FLATCOLOR_HPP_ */
