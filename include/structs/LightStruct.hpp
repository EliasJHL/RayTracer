/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** LightStruct
*/

#ifndef LIGHTSTRUCT_HPP_
#define LIGHTSTRUCT_HPP_

namespace ConfigStruct {
    struct Light {
        double ambient;
        double diffuse;
        struct point {
            double x;
            double y;
            double z;
        };
    };
};

#endif /* !LIGHTSTRUCT_HPP_ */
