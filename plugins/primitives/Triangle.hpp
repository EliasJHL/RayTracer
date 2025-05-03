/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "Abstracts/APrimitive.hpp"
#include "Abstracts/AMaterial.hpp"
#include "Math/Vector3D.hpp"
#include <memory>

class Triangle : public APrimitive {
    public:
        Triangle(const Vector3D &center, Structs::Color color, std::shared_ptr<AMaterial> material,
                 const Vector3D &v0, const Vector3D &v1, const Vector3D &v2);
        ~Triangle() noexcept override = default;

        bool hit(const Ray &ray, double t_min, double t_max, Structs::hitRecord &rec) const override;

    private:
        Vector3D mV0;
        Vector3D mV1;
        Vector3D mV2;
};

#endif /* !TRIANGLE_HPP_ */
