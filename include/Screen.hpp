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
#include "RayTracer/Primitives/Sphere.hpp"

class Screen {
    public:
        Screen() {};
        ~Screen() {};

        Vector3D getColor(const Ray &ray) {
            HitRecord rec;
            Sphere s1(Vector3D(0.7, 0, -0.9), 0.5, Structs::Color{255, 0, 0});
            Sphere s2(Vector3D(-0.9, -0, -0.9), 0.3, Structs::Color{255, 0, 0});
            double t = s1.hits(ray, rec);
            if (t > 0) {
                Vector3D N = ray.pointAtParameter(t) / ray.pointAtParameter(t).length();
                return N;
            }
            t = s2.hits(ray, rec);
            if (t > 0) {
                Vector3D N = ray.pointAtParameter(t) / ray.pointAtParameter(t).length();
                return N;
            }
            Vector3D unit = ray.getDirection() / ray.getDirection().length();
            t = 0.5 * (unit.y + 1);
            return (1 - t) * Vector3D(1,1,1);
        };

        void startRendering(void) {
            Parser *p = Parser::GetInstance("");

            int image_width = 800;
            int image_height = 400;

            Camera cam;

            std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

            for (int y = 0; y < image_height; y++) {
                for (int x = 0; x < image_width; x++) {
                    Vector3D col = Vector3D(0, 0, 0);
                    for (int i = 0; i < p->antiAliasing ; i++) {
                        float co_x = float(x+drand48()) / float(image_width);
                        float co_y = float(y+drand48()) / float(image_height);
                        Ray ray = cam.getRay(co_x, co_y);
                        col += getColor(ray);
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

    protected:
    private:
};

#endif /* !SCREEN_HPP_ */
