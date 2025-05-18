/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** APrimitive
*/

#ifndef APRIMITIVE_HPP_
#define APRIMITIVE_HPP_

#include "Interfaces/IPrimitive.hpp"
#include "Math/vector3D.hpp"
#include "Abstracts/AMaterial.hpp"

class APrimitive : public IPrimitive {
    public:
        APrimitive(const std::string &name, const Point3D &c = Point3D(0,0,0), Structs::Color col = Structs::Color{255,255,255}, std::shared_ptr<AMaterial> material = nullptr) : 
            name(name), center(c), color(col), material(material) {};
        virtual ~APrimitive() = default;
        const std::string &getName(void) const override = 0;
        bool hit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const override = 0;

        /* Primitive's common data */
        std::string name;
        Point3D center;
        Structs::Color color;
        std::shared_ptr<AMaterial> material;
};

#endif /* !APRIMITIVE_HPP_ */
