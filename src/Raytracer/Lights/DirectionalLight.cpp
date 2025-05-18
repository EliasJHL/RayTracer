/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight - Implementation of directional lighting
*/

#include "RayTracer/Lights/DirectionalLight.hpp"
#include <cmath>

/**
 * Default constructor
 * Creates a directional light pointing downward along the Y-axis
 * with default intensity (1.0) and white color
 */
DirectionalLight::DirectionalLight()
        : m_direction(Vector3D(0.0f, -1.0f, 0.0f)),
        m_intensity(1.0f),
        m_color{255, 255, 255}
{
    m_direction = m_direction.normalize();
}

/**
 * Parameterized constructor
 * Creates a directional light with specified direction, intensity, and color
 */
DirectionalLight::DirectionalLight(const Vector3D& direction, float intensity, const Structs::Color& color)
    : m_intensity(intensity), m_color(color)
{
    m_direction = direction.normalize();
}

/**
 * Destructor
 */
DirectionalLight::~DirectionalLight()
{
}

/**
 * Get direction from point to light
 * For directional lights, this is the same for all points (the negative of
 * the light's direction vector), since the light is considered to be at infinity
 */
Vector3D DirectionalLight::getDirection(const Vector3D& point) const
{
    return Vector3D(-m_direction.x, -m_direction.y, -m_direction.z);
}

/**
 * Get light intensity at a point
 * For directional lights, intensity is uniform throughout the scene
 */
float DirectionalLight::getIntensity(const Vector3D& point) const
{
    return m_intensity;
}

/**
 * Get light color
 */
Structs::Color DirectionalLight::getColor() const
{
    return m_color;
}

/**
 * Get light position
 * For directional lights, returns a very distant point in the
 * opposite direction of the light rays
 */
Vector3D DirectionalLight::getPosition() const
{
    float LARGE_DISTANCE = 10000.0f;
    return Vector3D(LARGE_DISTANCE * m_direction.x,
                    LARGE_DISTANCE * m_direction.y,
                    LARGE_DISTANCE * m_direction.z);
}

/**
 * Set the direction of the light rays
 */
void DirectionalLight::setDirection(const Vector3D& direction)
{
    m_direction = direction.normalize();
}

/**
 * Set light intensity
 */
void DirectionalLight::setIntensity(float intensity)
{
    m_intensity = intensity;
}

/**
 * Set light color
 */
void DirectionalLight::setColor(const Structs::Color& color)
{
    m_color = color;
}

/**
 * Get the raw direction vector of the light
 */
Vector3D DirectionalLight::getDirection() const
{
    return m_direction;
} 