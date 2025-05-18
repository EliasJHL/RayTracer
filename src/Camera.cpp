/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(const Point3D &pos, int fieldOfView, const Vector3D &rot)
{
    origin = pos;
    rotation = rot;
    
    double aspect = 2.0;
    double theta = fieldOfView * M_PI / 180.0;
    double half_height = tan(theta/2);
    double half_width = aspect * half_height;
    
    double focal_length = 1.0;
    
    Vector3D base_lower_left = Vector3D(-half_width, -half_height, -focal_length);
    Vector3D base_horizontal = Vector3D(2 * half_width, 0, 0);
    Vector3D base_vertical = Vector3D(0, 2 * half_height, 0);

    lower_left = rotateVector(base_lower_left);
    horizontal = rotateVector(base_horizontal);
    vertical = rotateVector(base_vertical);
}

Ray Camera::getRay(double u, double v)
{
    Vector3D direction = lower_left + u * horizontal + v * vertical;
    
    direction = direction.normalize();
    
    return Ray(origin, direction);
}

Vector3D Camera::rotateVector(const Vector3D &vec) const
{
    /* Conversion deg to rad */
    double pitch = rotation.x * M_PI / 180.0; // X rotation
    double yaw = rotation.y * M_PI / 180.0;   // Y rotation
    double roll = rotation.z * M_PI / 180.0;  // Z rotation
    
    Vector3D rotated = vec;
    
    /* Axe Z */
    if (roll != 0.0) {
        double cosR = cos(roll);
        double sinR = sin(roll);
        double x = rotated.x * cosR - rotated.y * sinR;
        double y = rotated.x * sinR + rotated.y * cosR;
        rotated.x = x;
        rotated.y = y;
    }
    
    /* Axe X */
    if (pitch != 0.0) {
        double cosP = cos(pitch);
        double sinP = sin(pitch);
        double y = rotated.y * cosP - rotated.z * sinP;
        double z = rotated.y * sinP + rotated.z * cosP;
        rotated.y = y;
        rotated.z = z;
    }
    
    /* Axe Y */
    if (yaw != 0.0) {
        double cosY = cos(yaw);
        double sinY = sin(yaw);
        double x = rotated.x * cosY + rotated.z * sinY;
        double z = -rotated.x * sinY + rotated.z * cosY;
        rotated.x = x;
        rotated.z = z;
    }
    
    return rotated;
}