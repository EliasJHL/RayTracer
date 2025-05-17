/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Main
*/

#include <iostream>
#include "Parser.hpp"
#include "Screen.hpp"
#include "PluginsManager.hpp"

void errorHanling(int ac, char **av)
{
    if (ac < 2 || ac > 4) {
        throw std::runtime_error("USAGE: ./raytracer <SCENE_FILE>\n  SCENE_FILE: scene configuration");
    }
}

int main(int ac, char **av)
{
    Parser *parser;
    PluginsManager *pm;
    Screen s;

    try {
        errorHanling(ac, av);
        parser = Parser::GetInstance(av[1]);
        pm = PluginsManager::getInstance();
        pm->LoadAllPlugins();
        s.mMaterials = pm->getAllMaterials();
        if (s.mMaterials["mirror"] == nullptr)
            std::cerr << "AAAA" << std::endl;
        parser->ParseConfig(&s);
        s.startRendering();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
