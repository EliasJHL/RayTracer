/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** ray
*/

#include "ray.hpp"

Vector3D Ray::getOrigin(void) const
{
    return mOrigin;
};

Vector3D Ray::getDirection(void) const
{
    return mDirection;
};

Vector3D Ray::pointAtParameter(double t) const
{
    return mOrigin + t * mDirection;
};