/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Main
*/

#include "Parser.hpp"
#include "Screen.hpp"
#include <iostream>

void errorHanling(int ac, char **av)
{
    if (ac < 2 || ac > 4) {
        throw std::runtime_error("USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration");
    }
}
// #include "structs/PrimitesStructs.hpp"
// #include "Math/vector3D.hpp"
// #include "Math/ray.hpp"
// #include "Math/operators.hpp"
// #include "RayTracer/Primitives/Sphere.hpp"
// #include "Camera.hpp"
// #include <iostream>

// Vector3D getColor(const Ray &ray)
// {
//     HitRecord rec;
//     Sphere s1(Vector3D(0.7, 0, -0.9), 0.5, Structs::Color{255, 0, 0});
//     Sphere s2(Vector3D(-0.9, -0, -0.9), 0.3, Structs::Color{255, 0, 0});
//     double t = s1.hits(ray, rec);
//     if (t > 0) {
//         Vector3D N = (ray.pointAtParameter(t)) / (ray.pointAtParameter(t)).length();
//         return N;;
//     }
//     t = s2.hits(ray, rec);
//     if (t > 0) {
//         Vector3D N = (ray.pointAtParameter(t) - Vector3D(0, 0, -1)) / (ray.pointAtParameter(t) - Vector3D(0, 0, -1)).length();
//         return N;//Vector3D(N.x + 1, N.y + 1, N.z + 1);
//     }
//     Vector3D unit = ray.getDirection() / ray.getDirection().length();
//     t = 0.5 * (unit.y + 1);
//     return (1 - t) * Vector3D(1,1,1);// + t * Vector3D(0.5,0.7,1.0);
// }

// int main() {
//     // Image

//     int image_width = 800;
//     int image_height = 400;

//     Camera cam;

//     int level_antiAliasing = 1000;

//     std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

//     for (int y = 0; y < image_height; y++) {
//         for (int x = 0; x < image_width; x++) {
//             Vector3D col = Vector3D(0, 0, 0);
//             for (int i = 0; i < level_antiAliasing ; i++) {
//                 float co_x = float(x+drand48()) / float(image_width);
//                 float co_y = float(y+drand48()) / float(image_height);
//                 Ray ray = cam.getRay(co_x, co_y);
//                 col += getColor(ray);
//             }
//             col /= level_antiAliasing;
//             int r = 255 * col.x;
//             int g = 255 * col.y;
//             int b = 255 * col.z;
//             std::cout << r << ' ' << g << ' ' << b << '\n';
//             //write_color(pixel_color);
//         }
//     }
// }
int main(int ac, char **av)
{
    Parser *parser;
    Screen s;

    try {
        errorHanling(ac, av);
        parser = Parser::GetInstance(av[1]);
        parser->ParseConfig(&s);
        s.startRendering();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
