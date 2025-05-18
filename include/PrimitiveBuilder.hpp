/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** PrimitiveBuilder
*/

#ifndef PRIMITIVEBUILDER_HPP_
#define PRIMITIVEBUILDER_HPP_

#include <memory>
#include <vector>
#include <optional>
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Math/vectorOperations.hpp"
#include "RayTracer/Primitives/Cone.hpp"
#include "RayTracer/Primitives/Sphere.hpp"
#include "RayTracer/Primitives/Plane.hpp"
#include "RayTracer/Primitives/Cylinder.hpp"
#include "RayTracer/Primitives/Triangle.hpp"

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
    std::optional<Vector3D> axisPos;
    std::optional<Axis> axis;
    std::optional<Point3D> v0, v1, v2;
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

        PrimitiveBuilder &setV0(const Point3D &v0) {
            mParams.v0 = v0;
            return *this;
        };
        PrimitiveBuilder &setV1(const Point3D &v1) {
            mParams.v1 = v1;
            return *this;
        };
        PrimitiveBuilder &setV2(const Point3D &v2) {
            mParams.v2 = v2;
            return *this;
        };

        PrimitiveBuilder &setAxis(const std::string &axe) {
            if (axe == "X")
                mParams.axis = Axis::X;
            else if (axe == "Y")
                mParams.axis = Axis::Y;
            else if (axe == "Z")
                mParams.axis = Axis::Z;
            else
                throw std::runtime_error("[!] Invalid axis : " + axe + ".");
            return *this;
        }

        PrimitiveBuilder &setAxisPosition(double pos) {
            if (mParams.axis == Axis::X)
                mParams.axisPos = Vector3D(pos, 0, 0);
            if (mParams.axis == Axis::Y)
                mParams.axisPos = Vector3D(0, pos, 0);
            if (mParams.axis == Axis::Z)
                mParams.axisPos = Vector3D(0, 0, pos);
            return *this;
        }

        std::unique_ptr<APrimitive> createSphere(void) {
            if (!mParams.radius.has_value()) {
                throw std::runtime_error("[!] Radius is not set for Sphere creation.");
            }
            return std::make_unique<Sphere>("sphere", mParams.center, mParams.color, mParams.material, mParams.radius.value());
        };

        std::unique_ptr<APrimitive> createCone(void) {
            if (!mParams.radius.has_value() || !mParams.height.has_value()) {
                throw std::runtime_error("[!] Radius, height, or direction is not set for Cone creation.");
            }
            Vector3D direction = Vector3D(0, 1, 0);
            return std::make_unique<Cone>("cone", mParams.center, direction, mParams.color, mParams.material, mParams.radius.value(), mParams.height.value());
        };

        std::unique_ptr<APrimitive> createPlane(void) {
            if (!mParams.axisPos.has_value() || !mParams.axis.has_value()) {
                throw std::runtime_error("[!] Axis, position not defined.");
            }
            return std::make_unique<Plane>("plane", mParams.axisPos.value(), mParams.color, mParams.material, mParams.axis.value());
        }

        std::unique_ptr<APrimitive> createCylinder(void) {
            if (!mParams.radius.has_value() || !mParams.height.has_value()) {
                throw std::runtime_error("[!] Radius or height is not set for Cylinder creation.");
            }
            Vector3D direction = Vector3D(0, 1, 0);
            return std::make_unique<Cylinder>("cylinder", mParams.center, direction, mParams.color, mParams.material, mParams.radius.value(), mParams.height.value());
        };

        std::unique_ptr<APrimitive> createTriangle(void) {
            if (!mParams.v0.has_value() || !mParams.v1.has_value() || !mParams.v2.has_value()) {
                throw std::runtime_error("[!] Vertices are not set for Triangle creation.");
            }
            return std::make_unique<Triangle>("triangle", mParams.v0.value(), mParams.v1.value(), mParams.v2.value(), mParams.color, mParams.material);
        };
    private:
        Params mParams;
};

#endif /* !PRIMITIVEBUILDER_HPP_ */
