/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** structs
*/

#ifndef STRUCTS_HPP_
#define STRUCTS_HPP_

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
    };
}

#endif /* !STRUCTS_HPP_ */
