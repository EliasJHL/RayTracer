/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight
*/

#pragma once

#include "Interfaces/ILight.hpp"

class DirectionalLight : public ILight {
public:
    DirectionalLight();
    DirectionalLight(const Vector3D& direction, float intensity = 1.0f, 
                     const Structs::Color& color = Structs::Color{255, 255, 255});
    ~DirectionalLight() override;

    Vector3D getDirection(const Vector3D& point) const override;
    float getIntensity(const Vector3D& point) const override;
    Structs::Color getColor() const override;
    Vector3D getPosition() const override;
    void setDirection(const Vector3D& direction);
    void setIntensity(float intensity) override;
    void setColor(const Structs::Color& color) override;
    Vector3D getDirection() const;

private:
    Vector3D m_direction;
    float m_intensity;
    Structs::Color m_color;
}; 