/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#include "RayTracer/Camera.hpp"
#include "RayTracer/Sphere.hpp"
#include "RayTracer/Color.hpp"
#include "Math/Vector3D.hpp"
#include <iostream>

int main() {
    const int width = 400;
    const int height = 400;
    
    RayTracer::Camera cam;
    RayTracer::Sphere s(math::Point3D(0, 0, -1), 0.5);
    std::cout << "P3\n" << width << " " << height << "\n255\n";
    
    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; ++i) {
            double u = static_cast<double>(i) / (width - 1);
            double v = static_cast<double>(j) / (height - 1);
            
            RayTracer::Ray r = cam.ray(u, v);
            
            if (s.hits(r)) {
                RayTracer::write_color(math::Vector3D(1, 0, 0));
            } else {
                RayTracer::write_color(math::Vector3D(0, 0, 1));
            }
        }
    }
    
    return 0;
}