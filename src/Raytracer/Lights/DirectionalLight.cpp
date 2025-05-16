/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight
*/

#include "RayTracer/Lights/DirectionalLight.hpp"
#include <cmath>

DirectionalLight::DirectionalLight()
    : m_direction(Vector3D(0.0f, -1.0f, 0.0f)),
      m_intensity(1.0f)
{
    m_direction = m_direction.normalize();
}

DirectionalLight::DirectionalLight(const Vector3D& direction, float intensity)
    : m_intensity(intensity)
{
    m_direction = direction.normalize();
}

DirectionalLight::~DirectionalLight()
{
}

Vector3D DirectionalLight::getDirection(const Vector3D& point) const
{
    return Vector3D(-m_direction.x, -m_direction.y, -m_direction.z);
}

float DirectionalLight::getIntensity(const Vector3D& point) const
{
    return m_intensity;
}

Vector3D DirectionalLight::getPosition() const
{
    float LARGE_DISTANCE = 10000.0f;
    return Vector3D(LARGE_DISTANCE * m_direction.x,
                    LARGE_DISTANCE * m_direction.y,
                    LARGE_DISTANCE * m_direction.z);
}

void DirectionalLight::setDirection(const Vector3D& direction)
{
    m_direction = direction.normalize();
}

void DirectionalLight::setIntensity(float intensity)
{
    m_intensity = intensity;
}

Vector3D DirectionalLight::getDirection() const
{
    return m_direction;
} 