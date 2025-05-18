/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vectorOperations
*/

#ifndef VECTOROPERATIONS_HPP_
#define VECTOROPERATIONS_HPP_

#include "operators.hpp"
#include "vector3D.hpp"
#include <stdexcept>

/**
 * @brief Calculate the dot product of two vectors
 * 
 * Computes the scalar product of two vectors: a·b = ax*bx + ay*by + az*bz.
 * The dot product represents the cosine of the angle between two vectors
 * multiplied by their lengths.
 * 
 * @param a The first vector
 * @param b The second vector
 * @return double The dot product value
 */
inline double dot(const Vector3D &a, const Vector3D &b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/**
 * @brief Negate a vector
 * 
 * Returns a vector with all components negated.
 * 
 * @param v The vector to negate
 * @return Vector3D A new vector pointing in the opposite direction
 */
inline Vector3D operator-(const Vector3D& v)
{
    return Vector3D(-v.x, -v.y, -v.z);
}

/**
 * @brief Calculate the cross product of two vectors
 * 
 * Computes the vector product of two vectors, resulting in a new vector
 * that is perpendicular to both input vectors.
 * 
 * @param a The first vector
 * @param b The second vector
 * @return Vector3D The cross product vector
 */
inline Vector3D cross(const Vector3D &a, const Vector3D &b)
{
    return Vector3D(a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x);
}

/**
 * @brief Normalize a vector
 * 
 * Returns a unit vector in the same direction as the input vector.
 * Throws an exception if attempting to normalize a zero-length vector.
 * 
 * @param v The vector to normalize
 * @return Vector3D A normalized copy of the vector
 * @throws std::runtime_error if the vector has zero length
 */
inline Vector3D normalize(const Vector3D &v)
{
    double length = v.length();
    if (length == 0) {
        throw std::runtime_error("Cannot normalize a zero-length vector");
    }
    return v / length;
}

/**
 * @brief Calculate reflection vector
 * 
 * Computes the reflection of a vector across a normal vector.
 * This is commonly used for calculating reflective ray directions.
 * 
 * @param v The incident vector to reflect
 * @param n The surface normal vector (should be normalized)
 * @return Vector3D The reflected vector
 */
inline Vector3D reflect(const Vector3D &v, const Vector3D &n)
{
    return v - 2 * dot(v, n) * n;
}

/**
 * @brief Create a unit vector
 * 
 * Returns a unit vector in the same direction as the input vector.
 * Alternative to normalize() but without the zero-length check.
 * 
 * @param v The vector to convert to a unit vector
 * @return Vector3D A unit vector in the same direction
 */
inline Vector3D unit_vector(const Vector3D &v)
{
    return v / v.length();
}

#endif /* !VECTOROPERATIONS_HPP_ */