/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Main
*/

#include "Parser.hpp"
#include <iostream>

void errorHanling(int ac, char **av)
{
    if (ac < 2 || ac > 4) {
        throw std::runtime_error("USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration");
    }
    
}

int main(int ac, char **av)
{
    try {
        errorHanling(ac, av);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
