/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ILight interface
*/

#pragma once

#include "Math/vector3D.hpp"
#include "Math/ray.hpp"
#include "Utils/structs.hpp" // Include structs for Color

class ILight {
public:
    virtual ~ILight() = default;
    virtual Vector3D getDirection(const Vector3D& point) const = 0;
    virtual float getIntensity(const Vector3D& point) const = 0;
    virtual Structs::Color getColor() const = 0;
    virtual bool isShadowed(const Vector3D& point, const Ray& ray) const {
        return false;
    }
    virtual float getAttenuation(const Vector3D& point) const {
        return 1.0f;
    }
    virtual void setIntensity(float intensity) = 0;
    virtual void setColor(const Structs::Color& color) = 0;
    virtual Vector3D getPosition() const = 0;
};