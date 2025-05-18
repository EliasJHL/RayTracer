/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Screen
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <map>
#include <cstring>
#include <algorithm>
#include "Camera.hpp"
#include "Parser.hpp"
#include "Math/ray.hpp"
#include "Math/vector3D.hpp"
#include "Math/operators.hpp"
#include "PrimitiveBuilder.hpp"
#include "RenderingContext.hpp"
#include "RenderingState.hpp"
#include "WindowManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
/* Primitives */
#include "Abstracts/APrimitive.hpp"
#include "RayTracer/Primitives/Plane.hpp"
#include "RayTracer/Primitives/Sphere.hpp"
/* Materials */
#include "Interfaces/ILight.hpp"
#include "Abstracts/AMaterial.hpp"
#include "RayTracer/Materials/Metal.hpp"
#include "RayTracer/Materials/Flatcolor.hpp"
#include "RayTracer/Lights/AmbientLight.hpp"
#include "RayTracer/Lights/DirectionalLight.hpp"

class Screen {
    public:
        Screen(void);
        ~Screen();

        bool checkForHit(const Ray &r, double t_min, double t_max, Structs::hitRecord &rec) const;

        Vector3D calculateLighting(const Ray &ray, const Structs::hitRecord &rec) const;

        Vector3D getColor(const Ray &ray, int depth);

        void startRendering(void);

        void createWindow(int width, int height);

        void displayWindow();

        void updatePixel(int x, int y, int r, int g, int b);

        std::vector<std::unique_ptr<APrimitive>> mPrimitives;
        std::map<std::string, std::shared_ptr<AMaterial>> mMaterials;
        std::vector<std::shared_ptr<ILight>> mLights;
        float diffuseIntensity;
    private:
        WindowManager* mWindow;
        sf::Texture mTexture;       // Texture pour stocker l'image
        sf::Sprite mSprite;         // Sprite pour afficher l'image
        sf::Uint8* mPixels;
};

#endif /* !SCREEN_HPP_ */
