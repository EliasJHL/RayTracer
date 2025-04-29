/*
** EPITECH PROJECT, 2025
** _
** File description:
** _
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include "../Math/Vector3D.hpp"
#include <iostream>

namespace RayTracer {
    void write_color(const math::Vector3D& color) {
        int r = static_cast<int>(255.999 * color.X);
        int g = static_cast<int>(255.999 * color.Y);
        int b = static_cast<int>(255.999 * color.Z);

        r = (r < 0) ? 0 : (r > 255) ? 255 : r;
        g = (g < 0) ? 0 : (g > 255) ? 255 : g;
        b = (b < 0) ? 0 : (b > 255) ? 255 : b;

        std::cout << r << " " << g << " " << b << "\n";
    }
}

#endif /* !COLOR_HPP_ */
