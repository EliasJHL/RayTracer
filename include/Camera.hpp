/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Math/ray.hpp"
#include "Math/vector3D.hpp"

class Camera {
    public:
        Camera(const Point3D &pos, double fieldOfView) : lower_left(pos + Vector3D(-2, -1, -1)), horizontal(pos + Vector3D(4, 0, 0)), vertical(pos + Vector3D(0, 2, 0)),
            origin(pos + Vector3D(0, 0, 0)) {};
        Camera(const Vector3D &origin, const Vector3D &lower_l, const Vector3D &horiz, const Vector3D &verti) : 
            origin(origin), lower_left(lower_l), horizontal(horiz), vertical(verti) {};
        ~Camera() = default;

        Ray getRay(double u, double v) {
            return Ray(origin, lower_left + u * horizontal + v * vertical);
        }
        
        Vector3D lower_left;
        Vector3D horizontal;
        Vector3D vertical;
        Vector3D origin;
};
#endif /* !CAMERA_HPP_ */
