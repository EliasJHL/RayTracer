/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PointLight - Implementation of point light sources
*/

#pragma once

#include "Interfaces/ILight.hpp"

/**
 * @brief Point Light implementation
 * 
 * A point light emits light in all directions from a specific point in space.
 * The light intensity decreases with distance from the source according to
 * physically-based attenuation factors.
 */
class PointLight : public ILight {
public:
    /**
     * @brief Default constructor
     * 
     * Creates a point light at the origin with default parameters
     */
    PointLight();

    /**
     * @brief Parameterized constructor
     * 
     * @param position The 3D position of the light source
     * @param intensity The base intensity of the light (0.0-1.0)
     * @param color The RGB color of the light
     */
    PointLight(const Vector3D& position, float intensity = 1.0f, 
                const Structs::Color& color = Structs::Color{255, 255, 255});

    /**
     * @brief Destructor
     */
    ~PointLight() override;

    /**
     * @brief Get direction from point to light
     * 
     * For point lights, this is the normalized vector from the given
     * point to the light's position.
     * 
     * @param point The 3D point for which to calculate the direction
     * @return Vector3D The normalized direction from the point to the light
     */
    Vector3D getDirection(const Vector3D& point) const override;

    /**
     * @brief Get light intensity at a point
     * 
     * For point lights, intensity decreases with distance according to
     * physically-based attenuation factors.
     * 
     * @param point The 3D point for which to calculate intensity
     * @return float The attenuated light intensity at the point
     */
    float getIntensity(const Vector3D& point) const override;

    /**
     * @brief Get light color
     * 
     * @return Structs::Color The RGB color of the point light
     */
    Structs::Color getColor() const override;

    /**
     * @brief Get light position
     * 
     * @return Vector3D The 3D position of the light source
     */
    Vector3D getPosition() const override;

    /**
     * @brief Calculate attenuation based on distance
     * 
     * Uses the physically-based formula:
     * attenuation = 1.0 / (constant + linear * d + quadratic * d^2)
     * 
     * @param point The 3D point for which to calculate attenuation
     * @return float The attenuation factor (0.0-1.0)
     */
    float getAttenuation(const Vector3D& point) const override;

    /**
     * @brief Set light position
     * 
     * @param position The new 3D position
     */
    void setPosition(const Vector3D& position);

    /**
     * @brief Set light intensity
     * 
     * @param intensity The new base intensity value (0.0-1.0)
     */
    void setIntensity(float intensity) override;

    /**
     * @brief Set light color
     * 
     * @param color The new RGB color
     */
    void setColor(const Structs::Color& color) override;

    /**
     * @brief Set attenuation factors
     * 
     * Modifies how quickly the light intensity decreases with distance.
     * 
     * @param constant The constant attenuation factor (typically 1.0)
     * @param linear The linear attenuation factor (scales with distance)
     * @param quadratic The quadratic attenuation factor (scales with distance²)
     */
    void setAttenuationFactors(float constant, float linear, float quadratic);

private:
    Vector3D m_position;               ///< Light position in 3D space
    float m_intensity;                 ///< Base light intensity (0.0-1.0)
    Structs::Color m_color;            ///< Light color (RGB)
    
    float m_constantAttenuation;       ///< Constant attenuation factor (usually 1.0)
    float m_linearAttenuation;         ///< Linear attenuation factor (scales with distance)
    float m_quadraticAttenuation;      ///< Quadratic attenuation factor (scales with distance²)
}; 