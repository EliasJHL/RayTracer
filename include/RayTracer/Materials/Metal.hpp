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
#include "Math/materialOperations.hpp"

class Metal : public AMaterial{
    public:
        Metal(const std::string &n = "metal") {
            name = n;
        };
        ~Metal() = default;

        bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const
        {
            Vector3D reflected = reflect(unit_vector(rayIn.getDirection()), rec.normal);
            
            reflected = reflected + 0.9 * randomInUnitSphere();
            
            scattered = Ray(rec.point, reflected);
            
            double reflectivity = 0.9;
            double specularFactor = 0.8;
            
            double cosine = std::max(0.0, -dot(unit_vector(rayIn.getDirection()), rec.normal));
            double fresnelFactor = reflectivity + (1 - reflectivity) * pow(1 - cosine, 5);
            
            Vector3D baseColor = Vector3D(rec.color.r / 255.0, rec.color.g / 255.0, rec.color.b / 255.0);
            
            Vector3D metallicTint;
            
            if (baseColor.x > 0.6 && baseColor.y > 0.6 && baseColor.z > 0.6) {
                metallicTint = Vector3D(0.972, 0.960, 0.915);
            } else if (baseColor.x > 0.6 && baseColor.y > 0.4 && baseColor.z < 0.4) {
                metallicTint = Vector3D(0.955, 0.637, 0.538);
            } else if (baseColor.x < 0.4 && baseColor.y > 0.4 && baseColor.z < 0.4) {
                metallicTint = Vector3D(0.254, 0.829, 0.483);
            } else if (baseColor.x < 0.4 && baseColor.y < 0.4 && baseColor.z > 0.6) {
                metallicTint = Vector3D(0.273, 0.471, 0.792);
            } else {
                metallicTint = Vector3D(0.560, 0.570, 0.580);
            }
            
            attenuation = baseColor * (1.0 - specularFactor) + metallicTint * specularFactor * fresnelFactor;
            
            double minReflectivity = 0.3;
            attenuation = attenuation * std::max(minReflectivity, fresnelFactor);
            
            return (dot(scattered.getDirection(), rec.normal) > 0);
        };
};

#endif /* !METAL_HPP_ */
