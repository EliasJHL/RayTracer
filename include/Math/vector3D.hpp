/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <cmath>

/**
 * @brief 3D vector class for mathematical operations
 * 
 * This class represents a vector or point in 3D space with x, y, and z components.
 * It provides various mathematical operations including vector arithmetic,
 * normalization, and length calculations that are essential for ray tracing.
 */
class Vector3D
{
    public:
        /**
         * @brief Default constructor
         * 
         * Creates a zero vector (0,0,0).
         */
        Vector3D() : x(0), y(0), z(0) {}; 
        
        /**
         * @brief Parametrized constructor
         * 
         * Creates a vector with the specified x, y, and z components.
         * 
         * @param xa X-component value
         * @param ya Y-component value
         * @param za Z-component value
         */
        Vector3D(double xa, double ya, double za) : x(xa), y(ya), z(za) {};
        
        /**
         * @brief Default destructor
         */
        ~Vector3D() = default;

        /* Operations */
        /**
         * @brief Addition assignment operator
         * 
         * Adds another vector to this vector.
         * 
         * @param v The vector to add
         * @return Vector3D& Reference to this vector after addition
         */
        Vector3D &operator+=(const Vector3D &v);
        
        /**
         * @brief Multiplication assignment operator
         * 
         * Multiplies this vector component-wise by another vector.
         * 
         * @param v The vector to multiply by
         * @return Vector3D& Reference to this vector after multiplication
         */
        Vector3D &operator*=(const Vector3D &v);
        
        /**
         * @brief Division assignment operator
         * 
         * Divides this vector component-wise by another vector.
         * 
         * @param v The vector to divide by
         * @return Vector3D& Reference to this vector after division
         */
        Vector3D &operator/=(const Vector3D &v);
        
        /**
         * @brief Multiplication operator
         * 
         * Multiplies this vector component-wise by another vector.
         * 
         * @param v The vector to multiply by
         * @return Vector3D& The resulting vector
         */
        Vector3D &operator*(const Vector3D &v);
        
        /**
         * @brief Division operator
         * 
         * Divides this vector component-wise by another vector.
         * 
         * @param v The vector to divide by
         * @return Vector3D& The resulting vector
         */
        Vector3D &operator/(const Vector3D &v);
        
        /**
         * @brief Scalar multiplication assignment
         * 
         * Multiplies this vector by a scalar.
         * 
         * @param t The scalar multiplier
         * @return Vector3D& Reference to this vector after multiplication
         */
        Vector3D &operator*=(const double t);
        
        /**
         * @brief Scalar division assignment
         * 
         * Divides this vector by a scalar.
         * 
         * @param t The scalar divisor
         * @return Vector3D& Reference to this vector after division
         */
        Vector3D &operator/=(const double t);
        
        /**
         * @brief Scalar multiplication
         * 
         * Multiplies this vector by a scalar.
         * 
         * @param t The scalar multiplier
         * @return Vector3D A new vector that is the product of this vector and the scalar
         */
        Vector3D operator*(const double t) const;

        /**
         * @brief Calculate a normalized copy of this vector
         * 
         * Returns a unit vector in the same direction as this vector.
         * 
         * @return Vector3D A normalized copy of this vector
         */
        Vector3D normalize(void) const;

        /* Get data */
        /**
         * @brief Calculate the length (magnitude) of this vector
         * 
         * @return double The length of the vector
         */
        double length(void) const;
        
        /**
         * @brief Calculate the squared length of this vector
         * 
         * This is more efficient than length() when only comparing vector lengths.
         * 
         * @return double The squared length of the vector
         */
        double length_sqrt(void) const;
        
        /**
         * @brief Normalize this vector in place
         * 
         * Changes this vector to a unit vector in the same direction.
         * 
         * @return Vector3D Reference to this vector after normalization
         */
        Vector3D normalize(void);

        /* Variables */
        double x;  ///< X-component of the vector
        double y;  ///< Y-component of the vector
        double z;  ///< Z-component of the vector
    
        /* Friend operator declarations */
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

/**
 * @brief Point3D type alias
 * 
 * A Point3D is conceptually a fixed position in 3D space,
 * implemented as a Vector3D for mathematical convenience.
 */
using Point3D = Vector3D;

#endif /* !VECTOR3D_HPP_ */