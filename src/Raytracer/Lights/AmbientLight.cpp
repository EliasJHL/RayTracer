/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight
*/

#include "RayTracer/Lights/AmbientLight.hpp"

AmbientLight::AmbientLight()
    : m_intensity(0.1f)
{
}

AmbientLight::AmbientLight(float intensity)
    : m_intensity(intensity)
{
}

AmbientLight::~AmbientLight()
{
}

Vector3D AmbientLight::getDirection(const Vector3D& point) const
{
    return Vector3D(0.0f, 0.0f, 0.0f);
}

float AmbientLight::getIntensity(const Vector3D& point) const
{
    return m_intensity;
}

bool AmbientLight::isShadowed(const Vector3D& point, const Ray& ray) const
{
    return false;
}

Vector3D AmbientLight::getPosition() const
{
    return Vector3D(0.0f, 0.0f, 0.0f);
}

void AmbientLight::setIntensity(float intensity)
{
    m_intensity = intensity;
} 