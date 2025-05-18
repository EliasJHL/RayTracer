/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ILight interface - Base interface for all light sources
*/

#pragma once

#include "Math/vector3D.hpp"
#include "Math/ray.hpp"
#include "Utils/structs.hpp" // Include structs for Color

/**
 * @brief Interface for all light sources in the raytracer
 * 
 * This interface defines the behaviors required for any light source.
 * Lights can provide direction, intensity, color, and can determine if
 * a point is in shadow relative to the light source.
 */
class ILight {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~ILight() = default;

    /**
     * @brief Get the direction from a point to the light source
     * 
     * @param point The 3D point for which to calculate the light direction
     * @return Vector3D Normalized direction vector from the point to the light
     */
    virtual Vector3D getDirection(const Vector3D& point) const = 0;

    /**
     * @brief Get the intensity of the light at a specific point
     * 
     * @param point The 3D point for which to calculate the light intensity
     * @return float The intensity value (0.0-1.0)
     */
    virtual float getIntensity(const Vector3D& point) const = 0;

    /**
     * @brief Get the color of the light
     * 
     * @return Structs::Color The RGB color of the light
     */
    virtual Structs::Color getColor() const = 0;

    /**
     * @brief Check if a point is in shadow relative to this light
     * 
     * @param point The 3D point to check for shadows
     * @param ray The ray from the camera to the point
     * @return bool True if the point is in shadow, false otherwise
     */
    virtual bool isShadowed(const Vector3D& point, const Ray& ray) const {
        return false;
    }

    /**
     * @brief Get the attenuation factor based on distance
     * 
     * Determines how the light intensity changes with distance.
     * 
     * @param point The 3D point for which to calculate attenuation
     * @return float The attenuation factor (0.0-1.0)
     */
    virtual float getAttenuation(const Vector3D& point) const {
        return 1.0f;
    }

    /**
     * @brief Set the intensity of the light
     * 
     * @param intensity The new intensity value (0.0-1.0)
     */
    virtual void setIntensity(float intensity) = 0;

    /**
     * @brief Set the color of the light
     * 
     * @param color The new RGB color
     */
    virtual void setColor(const Structs::Color& color) = 0;

    /**
     * @brief Get the position of the light
     * 
     * For positional lights, returns the actual position.
     * For directional lights, returns a distant point in the light's direction.
     * 
     * @return Vector3D The position or distant point in the light's direction
     */
    virtual Vector3D getPosition() const = 0;
};