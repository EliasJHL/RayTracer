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
    Camera(const Point3D &pos, int fieldOfView)
    {
        origin = pos;
        
        double aspect = 2.0;
        double theta = fieldOfView * M_PI / 180.0;
        double half_height = tan(theta/2);
        double half_width = aspect * half_height;
        
        double focal_length = 1.0;
        
        lower_left = Vector3D(-half_width, -half_height, -focal_length);
        horizontal = Vector3D(2 * half_width, 0, 0);
        vertical = Vector3D(0, 2 * half_height, 0);
    }

    Camera(const Vector3D &origin, const Vector3D &lower_l, const Vector3D &horiz, const Vector3D &verti) : 
        origin(origin), lower_left(lower_l), horizontal(horiz), vertical(verti) {};

    ~Camera() = default;

    Ray getRay(double u, double v) {
        Vector3D direction = lower_left + u * horizontal + v * vertical;
        
        direction = direction.normalize();
        
        return Ray(origin, direction);
    }
    
    Vector3D origin;
    Vector3D lower_left;
    Vector3D horizontal;
    Vector3D vertical;
};

#endif