/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight
*/

#pragma once

#include "Interfaces/ILight.hpp"

class AmbientLight : public ILight {
public:
    AmbientLight();
    AmbientLight(float intensity = 0.1f, const Structs::Color& color = Structs::Color{255, 255, 255});
    ~AmbientLight() override;

    Vector3D getDirection(const Vector3D& point) const override;
    float getIntensity(const Vector3D& point) const override;
    Structs::Color getColor() const override;
    bool isShadowed(const Vector3D& point, const Ray& ray) const override;
    Vector3D getPosition() const override;
    void setIntensity(float intensity) override;
    void setColor(const Structs::Color& color) override;

private:
    float m_intensity;
    Structs::Color m_color;
};