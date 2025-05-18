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

Vector3D Screen::calculateLighting(const Ray &ray, const Structs::hitRecord &rec) const {
    Vector3D totalLight(0, 0, 0);
    
    for (const auto &light : mLights) {
        Vector3D lightDir = light->getDirection(rec.point);
        float intensity = light->getIntensity(rec.point);
        
        Structs::Color lightColorStruct = light->getColor();
        Vector3D lightColor(
            lightColorStruct.r / 255.0,
            lightColorStruct.g / 255.0,
            lightColorStruct.b / 255.0
        );
        
        lightColor = lightColor * intensity;
        
        if (dynamic_cast<AmbientLight*>(light.get())) {
            totalLight += lightColor;
            continue;
        }
        
        bool inShadow = false;
        if (cast_shadows) {
            Ray shadowRay(rec.point, lightDir);
            Structs::hitRecord shadowRec;
                
            if (checkForHit(shadowRay, 0.001, std::numeric_limits<double>::max(), shadowRec)) {
                if (dynamic_cast<PointLight*>(light.get())) {
                    Vector3D lightPos = light->getPosition();
                    Vector3D toLight = Vector3D(
                        lightPos.x - rec.point.x,
                        lightPos.y - rec.point.y,
                        lightPos.z - rec.point.z
                    );
                    double distanceToLight = std::sqrt(
                        toLight.x * toLight.x +
                        toLight.y * toLight.y +
                        toLight.z * toLight.z
                    );
                    if (shadowRec.t < distanceToLight) {
                        inShadow = true;
                    }
                } else {
                    inShadow = true;
                }
            }
        }
        
        if (!inShadow) {
            double dotProduct = rec.normal.x * lightDir.x + 
                               rec.normal.y * lightDir.y + 
                               rec.normal.z * lightDir.z;
            float diffuseFactor = dotProduct > 0.0 ? dotProduct : 0.0;            
            diffuseFactor *= diffuseIntensity;
            totalLight += lightColor * diffuseFactor;
        }
    }
    if (mLights.empty()) {
        totalLight = Vector3D(0.1, 0.1, 0.1);
    }
    return totalLight;
}

Vector3D Screen::getColor(const Ray &ray, int depth) {
    Structs::hitRecord rec;
    
    if (checkForHit(ray, 0.001, std::numeric_limits<double>::max(), rec)) {
        Vector3D materialColor;      
        Vector3D lighting = calculateLighting(ray, rec);
        
        if (depth < max_depth) {
            Ray scattered;
            Vector3D attenuation;
            
            if (rec.material && rec.material->scatter(ray, rec, attenuation, scattered)) {
                Vector3D reflectedColor = getColor(scattered, depth + 1);
                
                materialColor = Vector3D(
                    attenuation.x * reflectedColor.x,
                    attenuation.y * reflectedColor.y,
                    attenuation.z * reflectedColor.z
                );
            } else {
                materialColor = Vector3D(
                    rec.color.r / 255.0,
                    rec.color.g / 255.0,
                    rec.color.b / 255.0
                );
            }
        } else {
            materialColor = Vector3D(
                rec.color.r / 255.0,
                rec.color.g / 255.0,
                rec.color.b / 255.0
            );
        }
        
        return Vector3D(
            materialColor.x * lighting.x,
            materialColor.y * lighting.y,
            materialColor.z * lighting.z
        );
    } else {
        Vector3D unit_direction = ray.getDirection();
        unit_direction = unit_direction / std::sqrt(
            unit_direction.x * unit_direction.x +
            unit_direction.y * unit_direction.y +
            unit_direction.z * unit_direction.z
        );
        
        float t = 0.5 * (unit_direction.y + 1.0);
        return Vector3D(1.0, 1.0, 1.0) * (1.0 - t) + Vector3D(0.5, 0.7, 1.0) * t;
    }
}

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