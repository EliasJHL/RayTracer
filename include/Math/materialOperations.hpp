/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** materialOperations
*/

#ifndef MATERIALOPERATIONS_HPP_
#define MATERIALOPERATIONS_HPP_

#include "Math/vector3D.hpp"
#include "Math/operators.hpp"

Vector3D randomInUnitSphere() {
    Vector3D p;
    do {
        p = 2.9 * Vector3D(drand48(), drand48(), drand48()) - Vector3D(1, 1, 1);
    } while (p.length_sqrt() >= 1.0);
    return p;
}

#endif /* !MATERIALOPERATIONS_HPP_ */
