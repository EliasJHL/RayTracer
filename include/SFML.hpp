/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** WindowManager
*/

#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Parser.hpp"

class WindowManager {
    public:
        WindowManager(int width, int height, const std::string& title = "Raytracer")
            : width(width), height(height) {
            window.create(sf::VideoMode(width, height), title);
            texture.create(width, height);
            sprite.setTexture(texture);
            pixels.resize(width * height * 4, 0);
        }

        void setPixel(unsigned int x, unsigned int y, sf::Color color) {
            if (x < width && y < height) {
                int index = (y * width + x) * 4;
                pixels[index] = color.r;
                pixels[index + 1] = color.g;
                pixels[index + 2] = color.b;
                pixels[index + 3] = color.a;
            }
        }

        void display() {
            texture.update(pixels.data());
            window.clear();
            window.draw(sprite);
            window.display();
        }

        bool isOpen() const {
            return window.isOpen();
        }

        void processEvents() {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
    private:
        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite sprite;
        std::vector<sf::Uint8> pixels;
        int width;
        int height;
};

#endif // WINDOW_MANAGER_HPP