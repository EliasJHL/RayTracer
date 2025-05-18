/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PointLight
*/

#include "RayTracer/Lights/PointLight.hpp"
#include <cmath>

PointLight::PointLight()
        : m_position(Vector3D(0.0f, 0.0f, 0.0f)),
        m_intensity(1.0f),
        m_color{255, 255, 255},
        m_constantAttenuation(1.0f),
        m_linearAttenuation(0.09f),
        m_quadraticAttenuation(0.032f)
{
}

PointLight::PointLight(const Vector3D& position, float intensity, const Structs::Color& color)
        : m_position(position),
        m_intensity(intensity),
        m_color(color),
        m_constantAttenuation(1.0f),
        m_linearAttenuation(0.09f),
        m_quadraticAttenuation(0.032f)
{
}

PointLight::~PointLight()
{
}

Vector3D PointLight::getDirection(const Vector3D& point) const
{
    Vector3D direction = Vector3D(
        m_position.x - point.x,
        m_position.y - point.y,
        m_position.z - point.z
    );
    
    float length = std::sqrt(
        direction.x * direction.x + 
        direction.y * direction.y + 
        direction.z * direction.z
    );
    
    if (length > 0.0001f) {
        direction.x /= length;
        direction.y /= length;
        direction.z /= length;
    }
    
    return direction;
}

float PointLight::getIntensity(const Vector3D& point) const
{
    return m_intensity * getAttenuation(point);
}

Structs::Color PointLight::getColor() const
{
    return m_color;
}

Vector3D PointLight::getPosition() const
{
    return m_position;
}

float PointLight::getAttenuation(const Vector3D& point) const
{
    Vector3D diff = Vector3D(
        m_position.x - point.x,
        m_position.y - point.y,
        m_position.z - point.z
    );
    
    float distance = std::sqrt(
        diff.x * diff.x + 
        diff.y * diff.y + 
        diff.z * diff.z
    );
    float attenuation = 1.0f / (
        m_constantAttenuation + 
        m_linearAttenuation * distance + 
        m_quadraticAttenuation * distance * distance
    );
    if (attenuation > 1.0f) 
        attenuation = 1.0f;
    if (attenuation < 0.0f)
        attenuation = 0.0f;
    
    return attenuation;
}

void PointLight::setPosition(const Vector3D& position)
{
    m_position = position;
}

void PointLight::setIntensity(float intensity)
{
    m_intensity = intensity;
}

void PointLight::setColor(const Structs::Color& color)
{
    m_color = color;
}

void PointLight::setAttenuationFactors(float constant, float linear, float quadratic)
{
    m_constantAttenuation = constant;
    m_linearAttenuation = linear;
    m_quadraticAttenuation = quadratic;
} 