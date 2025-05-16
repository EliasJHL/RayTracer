/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Screen
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "Camera.hpp"
#include "Parser.hpp"
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Math/operators.hpp"
#include "PrimitiveBuilder.hpp"
#include <algorithm>
#include <map>
/* Primitives */
#include "Abstracts/APrimitive.hpp"
#include "RayTracer/Primitives/Plate.hpp"
#include "RayTracer/Primitives/Sphere.hpp"
/* Materials */
#include "Abstracts/AMaterial.hpp"
#include "RayTracer/Materials/Metal.hpp"
#include "RayTracer/Materials/Flatcolor.hpp"
#include "Interfaces/ILight.hpp"
#include "RayTracer/Lights/AmbientLight.hpp"
#include "RayTracer/Lights/DirectionalLight.hpp"

class Screen {
    public:
        Screen(void);
        ~Screen() = default;

        bool checkForHit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const;

        Vector3D calculateLighting(const Ray &ray, const Structs::hitRecord &rec) const;

        Vector3D getColor(const Ray &ray, int depth);

        void startRendering(void);

        std::vector<std::unique_ptr<APrimitive>> mPrimitives;
        std::map<std::string, std::shared_ptr<AMaterial>> mMaterials;
        std::vector<std::shared_ptr<ILight>> mLights;
        float diffuseIntensity;
};

#endif /* !SCREEN_HPP_ */
