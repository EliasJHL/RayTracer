/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <cmath>

class Vector3D
{
    public:
        /* Constructors / Destructors */
        Vector3D() : x(0), y(0), z(0) {}; 
        Vector3D(double xa, double ya, double za) : x(xa), y(ya), z(za) {};
        ~Vector3D() = default;

        /* Operations */
        Vector3D &operator+=(const Vector3D &v);
        Vector3D &operator*=(const Vector3D &v);
        Vector3D &operator/=(const Vector3D &v);
        Vector3D &operator*(const Vector3D &v);
        Vector3D &operator/(const Vector3D &v);
        Vector3D &operator*=(const double t);
        Vector3D &operator/=(const double t);
        Vector3D operator*(const double t) const;

        Vector3D normalize(void) const;

        /* Get data */
        double length(void) const;
        double length_sqrt(void) const;
        Vector3D normalize(void);

        /* Variables */
        double x;
        double y;
        double z;
    
        /* Extern the operators */
        friend Vector3D operator+=(const Vector3D &v, const Vector3D &a);
        friend Vector3D operator*=(const Vector3D &v, const Vector3D &a);
        friend Vector3D operator/=(const Vector3D &v, const Vector3D &a);
        friend Vector3D operator*(const Vector3D &v, const Vector3D &a);
        friend Vector3D operator/(const Vector3D &v, const Vector3D &a);
        friend Vector3D operator*=(const double t, const Vector3D &v);
        friend Vector3D operator/=(const double t, const Vector3D &v);
        friend Vector3D operator*(const double t, const Vector3D &v);
        friend Vector3D operator/(const double a, const Vector3D &v);
};

/* Un point 3D est un vecteur fixe */
using Point3D = Vector3D;

#endif /* !VECTOR3D_HPP_ */
