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
#include "RayTracer/Primitives/Cone.hpp"
#include "Math/ray.hpp"
#include "Math/vectorOperations.hpp"
#include <memory>
#include <vector>
#include <optional> // à voir pk ça ne fonctionne pas

struct Params {
    Point3D center;
    Structs::Color color;
    std::shared_ptr<AMaterial> material;

    /* Optionnal */
    std::optional<double> radius;
    std::optional<double> height;
    std::optional<double> angle;
    std::optional<double> size_x;
    std::optional<double> size_y;
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
        PrimitiveBuilder &setHeight(double height) {
            mParams.height = height;
            return *this;
        };
        PrimitiveBuilder &setAngle(double angle) {
            mParams.angle = angle;
            return *this;
        };

        std::unique_ptr<APrimitive> createSphere(void) {
            if (!mParams.radius.has_value()) {
                throw std::runtime_error("Radius is not set for Sphere creation.");
            }
            return std::make_unique<Sphere>(mParams.center, mParams.color, mParams.material, mParams.radius.value());
        };

        std::unique_ptr<APrimitive> createCone(void) {
            if (!mParams.radius.has_value() || !mParams.height.has_value()) {
                throw std::runtime_error("Radius, height, or direction is not set for Cone creation.");
            }
            Vector3D direction = Vector3D(0, 1, 0);
            return std::make_unique<Cone>(mParams.center, direction, mParams.color, mParams.material, mParams.radius.value(), mParams.height.value());
        };
    private:
        Params mParams;
};

#endif /* !PRIMITIVEBUILDER_HPP_ */
