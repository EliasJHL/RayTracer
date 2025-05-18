/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PointLight
*/

#pragma once

#include "Interfaces/ILight.hpp"

class PointLight : public ILight {
public:
    PointLight();
    PointLight(const Vector3D& position, float intensity = 1.0f, 
               const Structs::Color& color = Structs::Color{255, 255, 255});
    ~PointLight() override;

    // Get the direction from a point to the light source
    Vector3D getDirection(const Vector3D& point) const override;
    
    // Get the intensity adjusted by distance attenuation
    float getIntensity(const Vector3D& point) const override;
    
    // Get the color of the light
    Structs::Color getColor() const override;
    
    // Get the position of the light
    Vector3D getPosition() const override;
    
    // Calculate attenuation based on distance
    float getAttenuation(const Vector3D& point) const override;
    
    // Set the position of the light
    void setPosition(const Vector3D& position);
    
    // Set the intensity of the light
    void setIntensity(float intensity) override;
    
    // Set the color of the light
    void setColor(const Structs::Color& color) override;
    
    // Set attenuation factors
    void setAttenuationFactors(float constant, float linear, float quadratic);

private:
    Vector3D m_position;
    float m_intensity;
    Structs::Color m_color;
    
    // Attenuation factors
    float m_constantAttenuation;   // Constant factor (usually 1.0)
    float m_linearAttenuation;     // Linear factor (scales with distance)
    float m_quadraticAttenuation;  // Quadratic factor (scales with distance²)
}; 