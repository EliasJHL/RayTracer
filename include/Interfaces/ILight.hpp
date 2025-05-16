/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ILight interface
*/

#pragma once

#include "Math/vector3D.hpp"
#include "Math/ray.hpp"

class ILight {
public:
    virtual ~ILight() = default;

    // Get the direction from a point to the light source
    virtual Vector3D getDirection(const Vector3D& point) const = 0;

    // Get the intensity of the light (0.0-1.0 range)
    virtual float getIntensity(const Vector3D& point) const = 0;

    // Check if there's a shadow between a point and the light
    virtual bool isShadowed(const Vector3D& point, const Ray& ray) const {
        return false;
    }
    
    // Get attenuation based on distance
    virtual float getAttenuation(const Vector3D& point) const {
        return 1.0f;
    }

    // Set the intensity of the light
    virtual void setIntensity(float intensity) = 0;
    
    // Get the position of the light (if applicable)
    virtual Vector3D getPosition() const = 0;
};