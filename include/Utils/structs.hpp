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
        /* Resolution */
        int width;
        int height;
        /* Position */
        double pos_x;
        double pos_y;
        double pos_z;
        /* Rotation */
        double rot_x;
        double rot_y;
        double rot_z;
        /* Parameters */
        double fieldOfView;
    };
}

#endif /* !STRUCTS_HPP_ */
