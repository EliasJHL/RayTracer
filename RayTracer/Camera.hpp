/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../Math/Point3D.hpp"
#include "Ray.hpp"
#include "Rectangle.hpp"

namespace RayTracer {
    class Camera {
    public:
        math::Point3D origin;
        Rectangle3D screen;
    
        Camera();
        Camera(const Camera& other) = default;
        Camera(const math::Point3D& origin, const Rectangle3D& screen);
        ~Camera() = default;


        Camera& operator=(const Camera& other) = default;

        Ray ray(double u, double v) const;
    };
}

#endif /* !CAMERA_HPP_ */
