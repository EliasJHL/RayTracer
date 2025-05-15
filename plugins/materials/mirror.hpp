/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Mirror
*/

#ifndef MIRROR_HPP_
#define MIRROR_HPP_

#include <string>
#include "Abstracts/AMaterial.hpp"
#include "Math/vectorOperations.hpp"

class Mirror : public AMaterial{
    public:
        Mirror(const std::string &n = "mirror") {
            name = n;
        };
        ~Mirror() = default;

        bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const;
};

#endif /* !MIRROR_HPP_ */
