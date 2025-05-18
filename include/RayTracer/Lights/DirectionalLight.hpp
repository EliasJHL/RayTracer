/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight - Implementation of directional lighting (like sunlight)
*/

#pragma once

#include "Interfaces/ILight.hpp"

/**
 * @brief Directional Light implementation
 * 
 * Directional light represents light coming from a specific direction,
 * like sunlight. The light rays are considered parallel and the light source
 * is effectively at infinite distance, so only the direction matters.
 */
class DirectionalLight : public ILight {
public:
    /**
     * @brief Default constructor
     * 
     * Creates a directional light with default parameters
     * (pointing downward from Y-axis)
     */
    DirectionalLight();

    /**
     * @brief Parameterized constructor
     * 
     * @param direction The direction vector for the light rays
     * @param intensity The intensity of the light (0.0-1.0)
     * @param color The RGB color of the light
     */
    DirectionalLight(const Vector3D& direction, float intensity = 1.0f, 
                        const Structs::Color& color = Structs::Color{255, 255, 255});

    /**
     * @brief Destructor
     */
    ~DirectionalLight() override;

    /**
     * @brief Get direction from point to light
     * 
     * For directional light, this is the same for all points
     * (the negative of the light's direction vector).
     * 
     * @param point The 3D point (unused for directional light)
     * @return Vector3D The direction from the point to the light
     */
    Vector3D getDirection(const Vector3D& point) const override;

    /**
     * @brief Get light intensity at a point
     * 
     * For directional light, intensity is uniform regardless of position.
     * 
     * @param point The 3D point (unused for directional light)
     * @return float The directional light intensity
     */
    float getIntensity(const Vector3D& point) const override;

    /**
     * @brief Get light color
     * 
     * @return Structs::Color The RGB color of the directional light
     */
    Structs::Color getColor() const override;

    /**
     * @brief Get light position
     * 
     * For directional light, this returns a very distant point in the
     * opposite direction of the light rays.
     * 
     * @return Vector3D A distant point in the light's direction
     */
    Vector3D getPosition() const override;

    /**
     * @brief Set the direction of the light rays
     * 
     * @param direction The new direction vector (will be normalized)
     */
    void setDirection(const Vector3D& direction);

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

    /**
     * @brief Get the raw direction vector of the light
     * 
     * @return Vector3D The direction in which the light rays travel
     */
    Vector3D getDirection() const;

private:
    Vector3D m_direction;      ///< Light direction (normalized)
    float m_intensity;         ///< Light intensity (0.0-1.0)
    Structs::Color m_color;    ///< Light color (RGB)
}; 