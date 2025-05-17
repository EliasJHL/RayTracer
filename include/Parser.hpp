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
#include <regex>
#include <iostream>
#include <filesystem>
#include "DLLoader.hpp"
#include <libconfig.h++>

/* Structs used for the parsing */
#include "Utils/structs.hpp"

class Screen;

using ConfSetting = libconfig::Setting;

class Parser {
    public:
        Parser(Parser &other) = delete;
        void operator=(const Parser &other) = delete;

        static Parser *GetInstance(const std::string &path);

        void ParseConfig(Screen *s);

        Structs::Camera &getCameraConfig(void);

        Structs::Camera mCameraConfig;
        int antiAliasing;

        void ParseLights(Screen *s, const libconfig::Config &config);

    protected:
        Parser(const std::string &path) : mConfigPath(path) {};

        void ParseCamera(const ConfSetting &camera);
        void ParseSphere(Screen *s, const ConfSetting &sphere);
        void ParsePlane(Screen *s, const ConfSetting &plane);
        void ParseCone(Screen *s, const ConfSetting &cone);

        static Parser* mParser;
        std::string mConfigPath;
};

#endif /* !PARSER_HPP_ */
