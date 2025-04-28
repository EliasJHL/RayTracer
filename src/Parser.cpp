/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Parser
*/

#include "Parser.hpp"

Parser *Parser::GetInstance(const std::string &path = "") 
{
    if (mParser == nullptr)
        mParser = new Parser(path);
    return mParser;
}

void Parser::ParseCamera(const ConfSetting &cam, const ConfSetting &res, const ConfSetting &pos, const ConfSetting &rota)
{
    
}

void Parser::ParseConfig(void)
{
    libconfig::Config cfg;

    /* Try to open the config file */
    try {
        cfg.readFile(mConfigPath.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        throw std::runtime_error("[!] Error while reading config file.");
    } catch (const libconfig::ParseException &pex) {
        throw std::runtime_error("[!] Parse error at " + std::string(pex.getFile()) + " : " + std::to_string(pex.getLine()) + " - " + pex.getError());
    }

    const ConfSetting &root = cfg.getRoot();

    /* Check config file integrity */
    if (!root.exists("camera") || !root.exists("primitives") || !root.exists("lights"))
        throw std::runtime_error("[!] Error : Incomplete config file");

    /* Get the camera */
    try {
        const ConfSetting &camera = root["camera"];

        const ConfSetting &resolution = camera["resolution"];
        const ConfSetting &position = camera["position"];
        const ConfSetting &rotation = camera["rotation"];

        ParseCamera(camera, resolution, position, rotation);

    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error(nfex.what());
    }
}