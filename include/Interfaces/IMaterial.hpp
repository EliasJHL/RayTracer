/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** IMaterial interface - Base interface for all material types
*/

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "IPrimitive.hpp"
#include "Utils/structs.hpp"

/**
 * @brief Interface for all materials in the raytracer
 * 
 * This interface defines the behaviors required for any material.
 * Materials determine how light interacts with object surfaces,
 * including reflection, refraction, and absorption properties.
 */
class IMaterial {
    public:
        /**
         * @brief Virtual destructor
         */
        virtual ~IMaterial() = default;
        
        /**
         * @brief Calculates how a ray scatters when hitting this material
         * 
         * This method determines whether a ray is absorbed or scattered by the material
         * and if scattered, in what direction and with what attenuation.
         * 
         * @param rayIn The incoming ray that hits the surface
         * @param rec The hit record containing information about the intersection
         * @param attenuation Output parameter for the ray's color attenuation
         * @param scattered Output parameter for the scattered ray
         * @return bool True if the ray was scattered, false if it was absorbed
         */
        virtual bool scatter(const Ray &rayIn, const Structs::hitRecord &rec, Vector3D &attenuation, Ray &scattered) const = 0;
};

#endif /* !IMATERIAL_HPP_ */