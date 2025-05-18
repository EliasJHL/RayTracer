/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight - Implementation of ambient lighting
*/

#include "RayTracer/Lights/AmbientLight.hpp"

/**
 * Default constructor
 * Creates an ambient light with default intensity (0.1) and white color
 */
AmbientLight::AmbientLight()
    : m_intensity(0.1f), m_color{255, 255, 255}
{
}

/**
 * Parameterized constructor
 * Creates an ambient light with specified intensity and color
 */
AmbientLight::AmbientLight(float intensity, const Structs::Color& color)
    : m_intensity(intensity), m_color(color)
{
}

/**
 * Destructor
 */
AmbientLight::~AmbientLight()
{
}

/**
 * Get direction from point to light
 * For ambient light, direction is meaningless since it illuminates all
 * surfaces uniformly regardless of their orientation. Returns a zero vector.
 */
Vector3D AmbientLight::getDirection(const Vector3D& point) const
{
    return Vector3D(0.0f, 0.0f, 0.0f);
}

/**
 * Get light intensity at a point
 * For ambient light, intensity is uniform throughout the scene
 */
float AmbientLight::getIntensity(const Vector3D& point) const
{
    return m_intensity;
}

/**
 * Get light color
 */
Structs::Color AmbientLight::getColor() const
{
    return m_color;
}

/**
 * Check if point is in shadow
 * Ambient light is never blocked, so always returns false
 */
bool AmbientLight::isShadowed(const Vector3D& point, const Ray& ray) const
{
    return false;
}

/**
 * Get light position
 * For ambient light, position is meaningless. Returns a zero vector.
 */
Vector3D AmbientLight::getPosition() const
{
    return Vector3D(0.0f, 0.0f, 0.0f);
}

/**
 * Set light intensity
 */
void AmbientLight::setIntensity(float intensity)
{
    m_intensity = intensity;
}

/**
 * Set light color
 */
void AmbientLight::setColor(const Structs::Color& color)
{
    m_color = color;
} 