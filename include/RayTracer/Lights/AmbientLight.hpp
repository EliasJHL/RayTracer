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
    AmbientLight(float intensity = 0.1f);
    ~AmbientLight() override;

    Vector3D getDirection(const Vector3D& point) const override;
    float getIntensity(const Vector3D& point) const override;
    bool isShadowed(const Vector3D& point, const Ray& ray) const override;
    Vector3D getPosition() const override;
    void setIntensity(float intensity) override;

private:
    float m_intensity;
};