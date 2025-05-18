/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight - Implementation of ambient lighting
*/

#pragma once

#include "Interfaces/ILight.hpp"

/**
 * @brief Ambient Light implementation
 * 
 * Ambient light represents the indirect, scattered light that illuminates
 * all surfaces uniformly regardless of their orientation. It provides a base
 * level of illumination to prevent completely dark shadows.
 */
class AmbientLight : public ILight {
public:
    /**
     * @brief Default constructor
     * 
     * Creates an ambient light with default parameters
     */
    AmbientLight();

    /**
     * @brief Parameterized constructor
     * 
     * @param intensity The intensity of the ambient light (0.0-1.0)
     * @param color The RGB color of the ambient light
     */
    AmbientLight(float intensity = 0.1f, const Structs::Color& color = Structs::Color{255, 255, 255});

    /**
     * @brief Destructor
     */
    ~AmbientLight() override;

    /**
     * @brief Get direction from point to light
     * 
     * For ambient light, direction is meaningless since it's non-directional.
     * Returns a zero vector by convention.
     * 
     * @param point The 3D point (unused for ambient light)
     * @return Vector3D A zero vector
     */
    Vector3D getDirection(const Vector3D& point) const override;

    /**
     * @brief Get light intensity at a point
     * 
     * For ambient light, intensity is uniform regardless of position.
     * 
     * @param point The 3D point (unused for ambient light)
     * @return float The global ambient intensity
     */
    float getIntensity(const Vector3D& point) const override;

    /**
     * @brief Get light color
     * 
     * @return Structs::Color The RGB color of the ambient light
     */
    Structs::Color getColor() const override;

    /**
     * @brief Check if point is in shadow
     * 
     * Ambient light is never blocked, so this always returns false.
     * 
     * @param point The 3D point (unused)
     * @param ray The ray from camera to point (unused)
     * @return bool Always false (ambient light can't be blocked)
     */
    bool isShadowed(const Vector3D& point, const Ray& ray) const override;

    /**
     * @brief Get light position
     * 
     * For ambient light, position is meaningless.
     * Returns a zero vector by convention.
     * 
     * @return Vector3D A zero vector
     */
    Vector3D getPosition() const override;

    /**
     * @brief Set light intensity
     * 
     * @param intensity The new intensity value (0.0-1.0)
     */
    void setIntensity(float intensity) override;

    /**
     * @brief Set light color
     * 
     * @param color The new RGB color
     */
    void setColor(const Structs::Color& color) override;

private:
    float m_intensity;         ///< Light intensity (0.0-1.0)
    Structs::Color m_color;    ///< Light color (RGB)
};