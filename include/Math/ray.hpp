/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

// -----------------
// p(t) = a + t * b
// -----------------
// p(t) : Point à la distance t
// t : distance
// a : point d'origine
// b : Direction

#include "Math/vector3D.hpp"
#include "Utils/structs.hpp"
#include "Math/operators.hpp"

class Ray {
    public:
        Ray() {};
        Ray(const Vector3D &a, const Vector3D &b) : mOrigin(a), mDirection(b) {};
        
        Vector3D getOrigin(void) const;
        Vector3D getDirection(void) const;

        Vector3D pointAtParameter(double t) const;

    private:
        Vector3D mOrigin;
        Vector3D mDirection;
};

#endif /* !RAY_HPP_ */
