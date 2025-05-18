/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** IPrimitive interface - Base interface for all geometric primitives
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "Math/vector3D.hpp"
#include "Math/ray.hpp"

/**
 * @brief Interface for all geometric primitives in the raytracer
 * 
 * This interface defines the behaviors required for any geometric object
 * that can be rendered in the scene, such as spheres, planes, or triangles.
 * Primitives can determine ray intersections and provide information about
 * the intersection point.
 */
class IPrimitive {
    public:
        /**
         * @brief Virtual destructor
         */
        virtual ~IPrimitive() = default;
        
        /**
         * @brief Get the name of the primitive type
         * 
         * @return const std::string& The primitive's type name
         */
        virtual const std::string &getName(void) const = 0;
        
        /**
         * @brief Calculate whether a ray hits this primitive
         * 
         * Determines if a ray intersects with this primitive between the
         * specified distance bounds and returns information about the hit.
         * 
         * @param r The ray to check for intersection
         * @param t_min The minimum distance along the ray to check
         * @param t_max The maximum distance along the ray to check
         * @param rec Output parameter for hit information if an intersection occurs
         * @return bool True if the ray intersects the primitive, false otherwise
         */
        virtual bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const = 0;
};

#endif /* !IPRIMITIVE_HPP_ */