/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** CameraStruct
*/

#ifndef CAMERASTRUCT_HPP_
#define CAMERASTRUCT_HPP_

namespace ConfigStruct {
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
};

#endif /* !CAMERASTRUCT_HPP_ */
