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

bool compare(const std::unique_ptr<APrimitive> &a, const std::unique_ptr<APrimitive> &b)
{
    return a->center.z < b->center.z;
}

class Screen {
    public:
        Screen() {
            mMaterials["flatcolor"] = std::make_shared<Flatcolor>();
            mMaterials["metal"] = std::make_shared<Metal>();
        };
        ~Screen() {};

        bool checkForHit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const
        {
            Structs::hitRecord temp_rec;
            bool hitAnything = false;

            for (const auto &primitive : mPrimitives) {
                if (primitive->hit(r, t_min, t_max, temp_rec)) {
                    hitAnything = true;
                    rec = temp_rec;
                }
            }
            return hitAnything;
        }

        Vector3D getColor(const Ray &ray, int depth) {
            Structs::hitRecord rec;
            if (checkForHit(ray, 0.001, MAXFLOAT, rec)) {
                Ray scattered;
                Vector3D attenuation;
                if (depth < 50 && rec.material->scatter(ray, rec, attenuation, scattered)) {
                    return attenuation * getColor(scattered, depth + 1);
                } else {
                    return Vector3D(0, 0, 0);
                }
            } else {
                Vector3D unit = ray.getDirection() / ray.getDirection().length();
                double t = 0.5 * (unit.y + 1);
                return (1 - t) * Vector3D(1,1,1);
            }
        };

        void startRendering(void) {
            Parser *p = Parser::GetInstance("");

            int image_width = 800;
            int image_height = 400;

            Point3D center(0.7, 0, -0.9);
            mPrimitives.push_back(std::make_unique<Sphere>(center, Structs::Color{255, 190, 190}, mMaterials["metal"], 0.5));
            mPrimitives.push_back(std::make_unique<Sphere>(Point3D(-0.7, 0, -0.9), Structs::Color{190, 255, 190}, mMaterials["flatcolor"], 0.5));
            mPrimitives.push_back(std::make_unique<Sphere>(Point3D(0, 0, -2), Structs::Color{190, 250, 190}, mMaterials["metal"], 0.5));

            std::sort(mPrimitives.begin(), mPrimitives.end(), compare);
            // builder = builder.setCenter(Point3D(0.7, 0, -0.9));
            // builder = builder.setMaterial(mMaterials[1]);
            // builder = builder.setRadius(0.5);
            // mPrimitives.push_back(builder.createSphere());

            //mPrimitives.push_back((APrimitive *)new Sphere(Vector3D(0.7, 0, -0.9), 0.5, Structs::Color{255, 0, 0}));
            //mPrimitives.push_back((APrimitive *)new Sphere(Vector3D(0.7, 0, -0.9), 0.5, Structs::Color{255, 0, 0}, new Flatcolor(Vector3D(0.8, 0.3, 0.3))));
            //mPrimitives.push_back((APrimitive *)new Sphere(Vector3D(0.7, 0, -0.9), 0.5, Structs::Color{255, 0, 0}));
            ////Plate p(Vector3D(-0.9, 1, -1), Structs::Color{255, 0, 0}, 5, 5);

            Camera cam;

            std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

            for (int y = 0; y < image_height; y++) {
                for (int x = 0; x < image_width; x++) {
                    Vector3D col = Vector3D(0, 0, 0);
                    for (int i = 0; i < p->antiAliasing ; i++) {
                        float co_x = float(x+drand48()) / float(image_width);
                        float co_y = float(y+drand48()) / float(image_height);
                        Ray ray = cam.getRay(co_x, co_y);
                        col += getColor(ray, 0);
                    }
                    col /= p->antiAliasing;
                    int r = 255 * col.x;
                    int g = 255 * col.y;
                    int b = 255 * col.z;
                    std::cout << r << ' ' << g << ' ' << b << '\n';
                    //write_color(pixel_color);
                }
            }
        };

        std::vector<std::unique_ptr<APrimitive>> mPrimitives;
        std::map<std::string, std::shared_ptr<AMaterial>> mMaterials;
    protected:
};

#endif /* !SCREEN_HPP_ */
