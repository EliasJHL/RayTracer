/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** structs
*/

#ifndef STRUCTS_HPP_
#define STRUCTS_HPP_

#include "Math/vector3D.hpp"
#include <memory>

class AMaterial;

/**
 * @namespace Structs
 * @brief Contains utility structures used throughout the raytracer project.
 */

/**
 * @struct Color
 * @brief Represents an RGB color.
 *
 * @var Color::r
 * Red component (0-255).
 * @var Color::g
 * Green component (0-255).
 * @var Color::b
 * Blue component (0-255).
 */

/**
 * @struct hitRecord
 * @brief Stores information about a ray-object intersection.
 *
 * @var hitRecord::t
 * Distance from the ray origin to the intersection point.
 * @var hitRecord::point
 * The intersection point in 3D space.
 * @var hitRecord::normal
 * The surface normal at the intersection point.
 * @var hitRecord::material
 * Shared pointer to the material at the intersection.
 * @var hitRecord::color
 * The color at the intersection point.
 */

/**
 * @struct Camera
 * @brief Defines the camera's properties and parameters.
 *
 * @var Camera::width
 * Image width in pixels.
 * @var Camera::height
 * Image height in pixels.
 * @var Camera::pos_x
 * Camera position on the X axis.
 * @var Camera::pos_y
 * Camera position on the Y axis.
 * @var Camera::pos_z
 * Camera position on the Z axis.
 * @var Camera::rot_x
 * Camera rotation around the X axis (in degrees or radians).
 * @var Camera::rot_y
 * Camera rotation around the Y axis (in degrees or radians).
 * @var Camera::rot_z
 * Camera rotation around the Z axis (in degrees or radians).
 * @var Camera::fieldOfView
 * Camera field of view (in degrees).
 */
namespace Structs {
    struct Color {
        int r;
        int g;
        int b;
    };

    struct hitRecord {
        double t;
        Vector3D point;
        Vector3D normal;
        std::shared_ptr<AMaterial> material = nullptr;
        Structs::Color color;
    };

    struct Camera {
        /* Resolution */
        int width;
        int height;
        /* Position */
        double pos_x;
        double pos_y;
        double pos_z;
        /* Rotation */
        double rot_x;
        double rot_y;
        double rot_z;
        /* Parameters */
        int fieldOfView;
    };
}

#endif /* !STRUCTS_HPP_ */
