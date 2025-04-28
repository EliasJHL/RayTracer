/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <cmath>

/* Un point 3D est un vecteur fixe */
using Point3D = Vector3D;

class Vector3D
{
    public:
        /* Constructors / Destructors */
        Vector3D() : x(0), y(0), z(0) {}; 
        Vector3D(double xa, double ya, double za) : x(xa), y(ya), z(za) {};
        ~Vector3D() = default;

        /* Operations */
        Vector3D &operator+=(const Vector3D &v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }
        Vector3D &operator*=(double t) {
            x *= t;
            y *= t;
            z *= t;
            return *this;
        }
        Vector3D operator/=(double t) {
            return *this *= 1/t;
        }

        /* Get data */
        double length(void) const {
            return std::sqrt(length_sqrt());
        }

        double length_sqrt(void) const {
            return ((x * x) + (y * y) + (z * z));
        }

        /* Variables */
        double x;
        double y;
        double z;
};

#endif /* !VECTOR3D_HPP_ */
