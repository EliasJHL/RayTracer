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
            Vector3D baseColor = Vector3D(rec.color.r / 255.0, rec.color.g / 255.0, rec.color.b / 255.0);

            /* Probabilité de 5% de renvoyer le rayon */
            double reflectionCoeff = 0.05;
            
            if (drand48() > reflectionCoeff) {
                attenuation = baseColor;
                return false;
            } else {
                Vector3D reflected = reflect(unit_vector(rayIn.getDirection()), rec.normal);
                scattered = Ray(rec.point, reflected);
                
                attenuation = baseColor;
                return true;
            }
        };
};

#endif /* !FLATCOLOR_HPP_ */
