/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** PrimitiveBuilder
*/

#ifndef PRIMITIVEBUILDER_HPP_
#define PRIMITIVEBUILDER_HPP_

#include "Math/vector3D.hpp"
#include "RayTracer/Primitives/Sphere.hpp"
#include "Math/ray.hpp"
#include <memory>
#include <vector>
#include <optional> // à voir pk ça ne fonctionne pas

struct Params {
    Point3D center;
    Structs::Color color;
    std::shared_ptr<AMaterial> material;

    /* Optionnal */
    double radius;
    int size_x;
    int size_y;
};

class PrimitiveBuilder {
    public:
        PrimitiveBuilder() {};
        ~PrimitiveBuilder() {};

        PrimitiveBuilder &setCenter(const Point3D &center) {
            mParams.center = center;
            return *this;
        };
        PrimitiveBuilder &setMaterial(std::shared_ptr<AMaterial> material) {
            mParams.material = material;
            return *this;
        };
        PrimitiveBuilder &setRadius(double radius) {
            mParams.radius = radius;
            return *this;
        };
        PrimitiveBuilder &setColor(Structs::Color color) {
            mParams.color = color;
            return *this;
        }

        std::unique_ptr<APrimitive> createSphere(void) {
            return std::make_unique<Sphere>(mParams.center, mParams.color, mParams.material, mParams.radius);
        };
    private:
        Params mParams;
};

#endif /* !PRIMITIVEBUILDER_HPP_ */
