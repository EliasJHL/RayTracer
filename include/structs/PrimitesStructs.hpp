/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** PrimitesStructs
*/

#ifndef PRIMITESSTRUCTS_HPP_
#define PRIMITESSTRUCTS_HPP_

#include <string>

namespace ConfigStruct {
    struct Sphere {
        double x;
        double y;
        double z;
        double r;
        struct color {
            int r;
            int g;
            int b;
        };
    };

    struct Planes {
        std::string axis;
        double position;
        struct color {
            int r;
            int g;
            int b;
        };
    };
};

#endif /* !PRIMITESSTRUCTS_HPP_ */
