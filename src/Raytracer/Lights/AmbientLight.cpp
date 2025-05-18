/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight
*/

#include "RayTracer/Lights/AmbientLight.hpp"

AmbientLight::AmbientLight()
    : m_intensity(0.1f), m_color{255, 255, 255}
{
}

AmbientLight::AmbientLight(float intensity, const Structs::Color& color)
    : m_intensity(intensity), m_color(color)
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

Structs::Color AmbientLight::getColor() const
{
    return m_color;
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

void AmbientLight::setColor(const Structs::Color& color)
{
    m_color = color;
} 