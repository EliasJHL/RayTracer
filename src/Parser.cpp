/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Parser
*/

#include "Parser.hpp"
#include "PrimitiveBuilder.hpp"
#include "Screen.hpp"

Parser *Parser::mParser = nullptr;

Parser *Parser::GetInstance(const std::string &path = "") 
{
    if (mParser == nullptr)
        mParser = new Parser(path);
    return mParser;
}

void Parser::ParseCamera(const ConfSetting &camera)
{
    /* Resolution */
    mCameraConfig.width = (int)camera["resolution"]["width"];
    mCameraConfig.height = (int)camera["resolution"]["height"];
    /* Position */
    mCameraConfig.pos_x = (camera["position"]["x"].getType() == ConfSetting::TypeInt ? (int)camera["position"]["x"] : (double)camera["position"]["x"]) / 100;
    mCameraConfig.pos_y = (camera["position"]["y"].getType() == ConfSetting::TypeInt ? (int)camera["position"]["y"] : (double)camera["position"]["y"]) / 100;
    mCameraConfig.pos_z = (camera["position"]["z"].getType() == ConfSetting::TypeInt ? (int)camera["position"]["z"] : (double)camera["position"]["z"]) / 100;
    /* Rotation */
    mCameraConfig.rot_x = (camera["rotation"]["x"].getType() == ConfSetting::TypeInt ? (int)camera["rotation"]["x"] : (double)camera["rotation"]["x"]);
    mCameraConfig.rot_y = (camera["rotation"]["y"].getType() == ConfSetting::TypeInt ? (int)camera["rotation"]["y"] : (double)camera["rotation"]["y"]);
    mCameraConfig.rot_z = (camera["rotation"]["z"].getType() == ConfSetting::TypeInt ? (int)camera["rotation"]["z"] : (double)camera["rotation"]["z"]);
    /* Parameters */
    mCameraConfig.fieldOfView = camera["fieldOfView"];
}

void Parser::ParseSphere(Screen *s, const ConfSetting &sphere)
{
    std::string material;
    PrimitiveBuilder builder;
    double x, y, z, radius;
    int r, g, b;

    x = (sphere["x"].getType() == ConfSetting::TypeInt ? (int)sphere["x"] : (double)sphere["x"]) / 1;
    y = (sphere["y"].getType() == ConfSetting::TypeInt ? (int)sphere["y"] : (double)sphere["y"]) / 1;
    z = (sphere["z"].getType() == ConfSetting::TypeInt ? (int)sphere["z"] : (double)sphere["z"]) / 1;
    radius = sphere["r"].getType() == ConfSetting::TypeInt ? (int)sphere["r"] : (double)sphere["r"];
    material = std::string(sphere["material"].c_str());
    r = sphere["color"]["r"];
    g = sphere["color"]["g"];
    b = sphere["color"]["b"];

    builder = builder.setCenter(Point3D(x, y, z));
    builder = builder.setRadius(radius);
    builder = builder.setColor(Structs::Color{r, g, b});
    builder = builder.setMaterial(s->mMaterials[material] != nullptr ? s->mMaterials[material] : s->mMaterials["flatcolor"]);

    s->mPrimitives.push_back(builder.createSphere());
}

void Parser::ParseConfig(Screen *s)
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
    if (!root.exists("camera") || !root.exists("primitives") || !root.exists("lights") || !root.exists("antiAliasing"))
        throw std::runtime_error("[!] Error : Incomplete config file");

    antiAliasing = root["antiAliasing"];

    /* Get the camera */
    try {
        const ConfSetting &camera = root["camera"];

        ParseCamera(camera);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error(nfex.what());
    } catch (const libconfig::SettingTypeException &e) {
        throw std::runtime_error("Error : Invalid data type : " + std::string(e.getPath()));
    }

    /* Get the primitives */
    try {
        const ConfSetting &primitives = root["primitives"];

        const ConfSetting &spheres = primitives["spheres"];
        const ConfSetting &planes = primitives["planes"];

        for (int i = 0; i < spheres.getLength(); ++i) {
            const ConfSetting &sphere = spheres[i];
            ParseSphere(s, sphere);
        }

        for (int i = 0; i < planes.getLength(); ++i) {
            const ConfSetting &plane = planes[i];
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Error : Parameter missing : " + std::string(nfex.getPath()));
    } catch (const libconfig::SettingTypeException &e) {
        throw std::runtime_error("Error : Invalid data type : " + std::string(e.getPath()));
    }
}