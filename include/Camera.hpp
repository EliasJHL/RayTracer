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
        Camera(const Point3D &pos, int fieldOfView);
    
        Camera(const Vector3D &origin, const Vector3D &lower_l, const Vector3D &horiz, const Vector3D &verti) : 
            origin(origin), lower_left(lower_l), horizontal(horiz), vertical(verti) {};
    
        ~Camera() = default;
    
        Ray getRay(double u, double v);
        
        Vector3D origin;
        Vector3D lower_left;
        Vector3D horizontal;
        Vector3D vertical;
};

#endif