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
        struct resolution {
            int width;
            int height;
        };
        struct position {
            double x;
            double y;
            double z;
        };
        struct rotation {
            double x;
            double y;
            double z;
        };
        double fieldOfView;
    };
}

#endif /* !STRUCTS_HPP_ */
