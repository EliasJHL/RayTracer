/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** color
*/

#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
#include "vector3D.hpp"

void write_color(const Vector3D &pixel_color) {
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    std::cout << r << ' ' << g << ' ' << b << std::endl;
}

#endif /* !COLOR_H_ */
