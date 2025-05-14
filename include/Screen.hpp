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

inline bool compare(const std::unique_ptr<APrimitive> &a, const std::unique_ptr<APrimitive> &b)
{
    return a->center.z < b->center.z;
}

class Screen {
    public:
        Screen() {
            /* Create the default materials */
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

        Vector3D calculateLighting(const Ray &ray, const Structs::hitRecord &rec) const {
            // Start with ambient contribution
            Vector3D totalLight(0, 0, 0);
            
            // Calculate lighting from all light sources
            for (const auto &light : mLights) {
                // Get light direction and intensity
                Vector3D lightDir = light->getDirection(rec.point);
                float lightIntensity = light->getIntensity(rec.point);
                
                // All lights are white, so we just multiply the intensity
                Vector3D lightColor(lightIntensity, lightIntensity, lightIntensity);
                
                // Handle ambient light - adds light regardless of normal
                if (dynamic_cast<AmbientLight*>(light.get())) {
                    totalLight += lightColor;
                    continue;
                }
                
                // For other light types (like directional), calculate diffuse lighting
                double dotProduct = rec.normal.x * lightDir.x + 
                                   rec.normal.y * lightDir.y + 
                                   rec.normal.z * lightDir.z;
                float diffuseFactor = dotProduct > 0.0 ? dotProduct : 0.0;
                
                // Apply diffuse intensity from config
                diffuseFactor *= diffuseIntensity;
                
                // Add diffuse contribution
                totalLight += lightColor * diffuseFactor;
            }
            
            // If no lights, provide a minimum ambient light so scene isn't completely dark
            if (mLights.empty()) {
                totalLight = Vector3D(0.1, 0.1, 0.1); // Minimal ambient light
            }
            
            return totalLight;
        }

        Vector3D getColor(const Ray &ray, int depth) {
            Structs::hitRecord rec;
            if (checkForHit(ray, 0.001, MAXFLOAT, rec)) {
                // Calculate lighting at the hit point
                Vector3D lighting = calculateLighting(ray, rec);
                
                // Get material color through scattering
                Ray scattered;
                Vector3D attenuation;
                if (depth < 50 && rec.material->scatter(ray, rec, attenuation, scattered)) {
                    // Combine material color with lighting
                    return attenuation * lighting * getColor(scattered, depth + 1);
                } else {
                    // Apply lighting to the base material color when no scattering
                    return Vector3D(0, 0, 0) * lighting;
                }
            } else {
                // Background gradient as before
                Vector3D unit = ray.getDirection() / ray.getDirection().length();
                double t = 0.5 * (unit.y + 1);
                return (1 - t) * Vector3D(1,1,1);
            }
        };

        void startRendering(void) {
            Parser *p = Parser::GetInstance("");

            /* Sort to get the closest to the camera on top */
            std::sort(mPrimitives.begin(), mPrimitives.end(), compare);
            Camera cam(Point3D(p->mCameraConfig.pos_x, p->mCameraConfig.pos_y, p->mCameraConfig.pos_z), -1);

            std::cout << "P3\n" << p->mCameraConfig.width << ' ' << p->mCameraConfig.height << "\n255\n";
            for (int y = 0; y < p->mCameraConfig.height; y++) {
                for (int x = 0; x < p->mCameraConfig.width; x++) {
                    Vector3D col = Vector3D(0, 0, 0);
                    for (int i = 0; i < p->antiAliasing ; i++) {
                        float co_x = float(x+drand48()) / float(p->mCameraConfig.width);
                        float co_y = float(y+drand48()) / float(p->mCameraConfig.height);
                        Ray ray = cam.getRay(co_x, co_y);
                        col += getColor(ray, 0);
                    }
                    col /= p->antiAliasing;
                    int r = 255 * col.x;
                    int g = 255 * col.y;
                    int b = 255 * col.z;
                    std::cout << r << ' ' << g << ' ' << b << '\n';
                }
            }
        };

        void addLight(std::shared_ptr<ILight> light) {
            mLights.push_back(light);
        }

        void setDiffuseIntensity(float intensity) {
            diffuseIntensity = intensity;
        }

        std::vector<std::unique_ptr<APrimitive>> mPrimitives;
        std::map<std::string, std::shared_ptr<AMaterial>> mMaterials;
        std::vector<std::shared_ptr<ILight>> mLights;
        float diffuseIntensity = 0.6f; // Default value
    protected:
};

#endif /* !SCREEN_HPP_ */
