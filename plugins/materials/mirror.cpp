/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** mirror
*/

#include "mirror.hpp"

bool Mirror::scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const
{
    Vector3D reflected = reflect(unit_vector(rayIn.getDirection()), rec.normal);
    scattered = Ray(rec.point, reflected);
    Vector3D objectColor = Vector3D(rec.color.r / 255.0, rec.color.g / 255.0, rec.color.b / 255.0);
    attenuation = Vector3D(0.9, 0.9, 0.9) * 0.9 + objectColor * 0.1;
    return true;
};

extern "C" {
    AMaterial *createMaterial(void) {
        return new Mirror();
    }
}