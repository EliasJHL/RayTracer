/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Parser
*/

/* SINGLETON DESIGN PATTERN */

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <libconfig.h++>

/* Structs used for the parsing */
#include "structs/CameraStruct.hpp"
#include "structs/LightStruct.hpp"
#include "structs/PrimitesStructs.hpp"

struct AllData {
    ConfigStruct::Camera *camera;
    std::vector<std::unique_ptr<ConfigStruct::Light>> lights;
    std::vector<std::unique_ptr<ConfigStruct::Planes>> planes;
    std::vector<std::unique_ptr<ConfigStruct::Sphere>> spheres;
};

struct DataPrimitives {
    std::vector<std::unique_ptr<ConfigStruct::Planes>> planes;
    std::vector<std::unique_ptr<ConfigStruct::Sphere>> spheres;
};

using ConfSetting = libconfig::Setting;

class Parser {
    public:
        Parser(Parser &other) = delete;
        void operator=(const Parser &other) = delete;

        static Parser *GetInstance(const std::string &path);

        void ParseConfig(void);

        ConfigStruct::Camera &getCameraConfig(void);

        // Ajouter la récup des différents éléments

    protected:
        Parser(const std::string &path) : mConfigPath(path) {};

        void ParseCamera(const ConfSetting &cam, const ConfSetting &res,
            const ConfSetting &pos, const ConfSetting &rota);

        ConfigStruct::Camera *mCameraConfig;

        static Parser* mParser;
        std::string mConfigPath;
};

#endif /* !PARSER_HPP_ */
