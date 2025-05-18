/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** Parser
*/

#include "Parser.hpp"
#include "PrimitiveBuilder.hpp"
#include "Screen.hpp"
#include "RayTracer/Lights/AmbientLight.hpp"
#include "RayTracer/Lights/DirectionalLight.hpp"
#include <filesystem>

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
    if (s->mMaterials[material] != nullptr) {
        builder = builder.setMaterial(s->mMaterials[material]);
    } else {
        std::cerr << "[!] Material " << material << " not found -> Setting default material : flatcolor." << std::endl;
        builder = builder.setMaterial(s->mMaterials["flatcolor"]);
    }

    s->mPrimitives.push_back(builder.createSphere());
}

void Parser::ParseCone(Screen *s, const ConfSetting &cone)
{
    std::string material;
    PrimitiveBuilder builder;
    double x, y, z, radius, height;
    int r, g, b;

    x = (cone["x"].getType() == ConfSetting::TypeInt ? (int)cone["x"] : (double)cone["x"]) / 1;
    y = (cone["y"].getType() == ConfSetting::TypeInt ? (int)cone["y"] : (double)cone["y"]) / 1;
    z = (cone["z"].getType() == ConfSetting::TypeInt ? (int)cone["z"] : (double)cone["z"]) / 1;
    radius = cone["r"].getType() == ConfSetting::TypeInt ? (int)cone["r"] : (double)cone["r"];
    height = cone["h"].getType() == ConfSetting::TypeInt ? (int)cone["h"] : (double)cone["h"];
    material = std::string(cone["material"].c_str());
    r = cone["color"]["r"];
    g = cone["color"]["g"];
    b = cone["color"]["b"];

    builder = builder.setCenter(Point3D(x, y, z));
    builder = builder.setRadius(radius);
    builder = builder.setHeight(height);
    builder = builder.setColor(Structs::Color{r, g, b});
    if (s->mMaterials[material] != nullptr) {
        builder = builder.setMaterial(s->mMaterials[material]);
    } else {
        std::cerr << "[!] Material " << material << " not found -> Setting default material : flatcolor." << std::endl;
        builder = builder.setMaterial(s->mMaterials["flatcolor"]);
    }

    s->mPrimitives.push_back(builder.createCone());
}

void Parser::ParseCylinder(Screen *s, const ConfSetting &cylinder)
{
    std::string material;
    PrimitiveBuilder builder;
    double x, y, z, radius, height;
    int r, g, b;

    x = (cylinder["x"].getType() == ConfSetting::TypeInt ? (int)cylinder["x"] : (double)cylinder["x"]) / 1;
    y = (cylinder["y"].getType() == ConfSetting::TypeInt ? (int)cylinder["y"] : (double)cylinder["y"]) / 1;
    z = (cylinder["z"].getType() == ConfSetting::TypeInt ? (int)cylinder["z"] : (double)cylinder["z"]) / 1;
    radius = cylinder["r"].getType() == ConfSetting::TypeInt ? (int)cylinder["r"] : (double)cylinder["r"];
    height = cylinder["h"].getType() == ConfSetting::TypeInt ? (int)cylinder["h"] : (double)cylinder["h"];
    material = std::string(cylinder["material"].c_str());
    r = cylinder["color"]["r"];
    g = cylinder["color"]["g"];
    b = cylinder["color"]["b"];

    builder = builder.setCenter(Point3D(x, y, z));
    builder = builder.setRadius(radius);
    builder = builder.setHeight(height);
    builder = builder.setColor(Structs::Color{r, g, b});
    if (s->mMaterials[material] != nullptr) {
        builder = builder.setMaterial(s->mMaterials[material]);
    } else {
        std::cerr << "[!] Material " << material << " not found -> Setting default material : flatcolor." << std::endl;
        builder = builder.setMaterial(s->mMaterials["flatcolor"]);
    }

    s->mPrimitives.push_back(builder.createCylinder());
}

void Parser::ParsePlane(Screen *s, const ConfSetting &plane)
{
    std::string material, axis;
    PrimitiveBuilder builder;
    double pos;
    int r, g, b;

    axis = plane["axis"].c_str();
    pos = (plane["position"].getType() == ConfSetting::TypeInt ? (int)plane["position"] : (double)plane["position"]);
    material = std::string(plane["material"].c_str());

    r = plane["color"]["r"];
    g = plane["color"]["g"];
    b = plane["color"]["b"];

    builder = builder.setAxis(axis);
    builder = builder.setAxisPosition(pos);
    builder = builder.setColor(Structs::Color{r, g, b});
    if (s->mMaterials[material] != nullptr) {
        builder = builder.setMaterial(s->mMaterials[material]);
    } else {
        std::cerr << "[!] Material " << material << " not found -> Setting default material : flatcolor." << std::endl;
        builder = builder.setMaterial(s->mMaterials["flatcolor"]);
    }

    s->mPrimitives.push_back(builder.createPlane());
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
        const ConfSetting &cones = primitives["cones"];
        const ConfSetting &cylinders = primitives["cylinders"];

        for (int i = 0; i < spheres.getLength(); ++i) {
            const ConfSetting &sphere = spheres[i];
            ParseSphere(s, sphere);
        }

        for (int i = 0; i < planes.getLength(); ++i) {
            const ConfSetting &plane = planes[i];
            ParsePlane(s, plane);
        }
        for (int i = 0; i < cones.getLength(); ++i) {
            const ConfSetting &cone = cones[i];
            ParseCone(s, cone);
        }
        for (int i = 0; i < cylinders.getLength(); ++i) {
            const ConfSetting &cylinder = cylinders[i];
            ParseCylinder(s, cylinder);
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Error : Parameter missing : " + std::string(nfex.getPath()));
    } catch (const libconfig::SettingTypeException &e) {
        throw std::runtime_error("Error : Invalid data type : " + std::string(e.getPath()));
    }
    
    /* Get the lights */
    ParseLights(s, cfg);
}

void Parser::ParseLights(Screen *s, const libconfig::Config &config)
{
    try {
        const ConfSetting &root = config.getRoot();
        const ConfSetting &lights = root["lights"];
        if (lights.exists("ambient")) {
            float ambientIntensity = lights["ambient"];
            auto ambient = std::make_shared<AmbientLight>(ambientIntensity);
            s->mLights.push_back(ambient);
        }
        if (lights.exists("diffuse")) {
            float diffuseIntensity = lights["diffuse"];
            s->diffuseIntensity = diffuseIntensity;
        }
        if (lights.exists("directional")) {
            const ConfSetting &directional = lights["directional"];
            
            for (int i = 0; i < directional.getLength(); ++i) {
                const ConfSetting &dirLight = directional[i];
                Vector3D direction;
                if (dirLight.exists("direction")) {
                    const ConfSetting &dir = dirLight["direction"];
                    direction.x = dir["x"].getType() == ConfSetting::TypeInt ? (int)dir["x"] : (double)dir["x"];
                    direction.y = dir["y"].getType() == ConfSetting::TypeInt ? (int)dir["y"] : (double)dir["y"];
                    direction.z = dir["z"].getType() == ConfSetting::TypeInt ? (int)dir["z"] : (double)dir["z"];
                } else {
                    direction = Vector3D(0.0, -1.0, 0.0);
                }
                float intensity = 1.0f;
                if (dirLight.exists("intensity")) {
                    intensity = dirLight["intensity"];
                }
                auto directional = std::make_shared<DirectionalLight>(direction, intensity);
                s->mLights.push_back(directional);
            }
        }

        if (lights.exists("point")) {
            const ConfSetting &pointLights = lights["point"];
            
            for (int i = 0; i < pointLights.getLength(); ++i) {
                const ConfSetting &pointLight = pointLights[i];
                double x = pointLight["x"].getType() == ConfSetting::TypeInt ? (int)pointLight["x"] : (double)pointLight["x"];
                double y = pointLight["y"].getType() == ConfSetting::TypeInt ? (int)pointLight["y"] : (double)pointLight["y"];
                double z = pointLight["z"].getType() == ConfSetting::TypeInt ? (int)pointLight["z"] : (double)pointLight["z"];
            }
        }
        
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Error : Parameter missing : " + std::string(nfex.getPath()));
    } catch (const libconfig::SettingTypeException &e) {
        throw std::runtime_error("Error : Invalid data type : " + std::string(e.getPath()));
    }
}