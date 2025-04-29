/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#include "Camera.hpp"

namespace RayTracer {
    Camera::Camera() 
        : origin(math::Point3D(0, 0, 0)) {
        math::Point3D screenOrigin(-1, -1, -1);
        math::Vector3D bottomSide(2, 0, 0);
        math::Vector3D leftSide(0, 2, 0);
        screen = Rectangle3D(screenOrigin, bottomSide, leftSide);
    }

    Camera::Camera(const math::Point3D& origin, const Rectangle3D& screen)
        : origin(origin), screen(screen) {}

    Ray Camera::ray(double u, double v) const {
        math::Point3D point = screen.pointAt(u, v);
        math::Vector3D direction = point - origin;
        return Ray(origin, direction);
    }
}