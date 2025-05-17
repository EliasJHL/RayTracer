/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Screen
*/

#include "Screen.hpp"

Screen::Screen() : diffuseIntensity(0.6)
{
    /* Create the default materials */
    mMaterials["flatcolor"] = std::make_shared<Flatcolor>();
    mMaterials["metal"] = std::make_shared<Metal>();
}

bool Screen::checkForHit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const
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

Vector3D Screen::calculateLighting(const Ray &ray, const Structs::hitRecord &rec) const 
{
    Vector3D totalLight(0, 0, 0);
    
    for (const auto &light : mLights) {
        Vector3D lightDir = light->getDirection(rec.point);
        float lightIntensity = light->getIntensity(rec.point);
        
        Vector3D lightColor(lightIntensity, lightIntensity, lightIntensity);
        
        if (dynamic_cast<AmbientLight*>(light.get())) {
            totalLight += lightColor;
            continue;
        }
        
        double dotProduct = rec.normal.x * lightDir.x + 
                           rec.normal.y * lightDir.y + 
                           rec.normal.z * lightDir.z;
        float diffuseFactor = dotProduct > 0.0 ? dotProduct : 0.0;

        diffuseFactor *= diffuseIntensity;
        totalLight += lightColor * diffuseFactor;
    }
    
    if (mLights.empty()) {
        totalLight = Vector3D(0.1, 0.1, 0.1);
    }
    return totalLight;
}

Vector3D Screen::getColor(const Ray &ray, int depth)
{
    Structs::hitRecord rec;
    if (checkForHit(ray, 0.001, MAXFLOAT, rec)) {
        Vector3D lighting = calculateLighting(ray, rec);
        
        Ray scattered;
        Vector3D attenuation;
        if (depth < 50 && rec.material->scatter(ray, rec, attenuation, scattered)) {
            return attenuation * lighting * getColor(scattered, depth + 1);
        } else {
            return attenuation * lighting;
        }
    } else {
        Vector3D unit = ray.getDirection() / ray.getDirection().length();
        double t = 0.5 * (unit.y + 1);
        return (1 - t) * Vector3D(1, 1, 1);
    }
};

inline bool compare(const std::unique_ptr<APrimitive> &a, const std::unique_ptr<APrimitive> &b)
{
    return a->center.z < b->center.z;
}

void Screen::startRendering(void) {
    Parser *p = Parser::GetInstance("");

    /* Sort to get the closest to the camera on top */
    std::sort(mPrimitives.begin(), mPrimitives.end(), compare);

    Camera cam(Point3D(p->mCameraConfig.pos_x, p->mCameraConfig.pos_y, p->mCameraConfig.pos_z), p->mCameraConfig.fieldOfView);
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