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

Parser *Parser::mParser = nullptr;

Parser *Parser::GetInstance(const std::string &path = "") 
{
    if (mParser == nullptr)
        mParser = new Parser(path);
    return mParser;
}

void Parser::ParseCamera(const ConfSetting &cam, const ConfSetting &res, const ConfSetting &pos, const ConfSetting &rota)
{
    /* Resolution */
    mCameraConfig.width = (int)res["width"];
    mCameraConfig.height = (int)res["height"];
    /* Position */
    mCameraConfig.pos_x = ConfSetting::TypeInt ? (int)pos["x"] : (double)pos["x"];
    mCameraConfig.pos_x = ConfSetting::TypeInt ? (int)pos["y"] : (double)pos["y"];
    mCameraConfig.pos_x = ConfSetting::TypeInt ? (int)pos["z"] : (double)pos["z"];
    /* Rotation */
    mCameraConfig.rot_x = ConfSetting::TypeInt ? (int)pos["x"] : (double)pos["x"];
    mCameraConfig.rot_y = ConfSetting::TypeInt ? (int)pos["y"] : (double)pos["y"];
    mCameraConfig.rot_z = ConfSetting::TypeInt ? (int)pos["z"] : (double)pos["z"];
    /* Parameters */
    mCameraConfig.fieldOfView = (int)cam["fieldOfView"];
}

void Parser::ParseSphere(Screen *s, const ConfSetting &sphere)
{
    std::string material;
    PrimitiveBuilder builder;
    double x, y, z, radius;
    int r, g, b;

    x = sphere["x"].getType() == ConfSetting::TypeInt ? (int)sphere["x"] : (double)sphere["x"];
    y = sphere["y"].getType() == ConfSetting::TypeInt ? (int)sphere["y"] : (double)sphere["y"];
    z = sphere["z"].getType() == ConfSetting::TypeInt ? (int)sphere["z"] : (double)sphere["z"];
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

        const ConfSetting &resolution = camera["resolution"];
        const ConfSetting &position = camera["position"];
        const ConfSetting &rotation = camera["rotation"];

        ParseCamera(camera, resolution, position, rotation);

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
            // TODO: Implement ParsePlane method
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

        // Parse ambient light
        if (lights.exists("ambient")) {
            float ambientIntensity = lights["ambient"];
            
            // Directly create ambient light with intensity
            auto ambient = std::make_shared<AmbientLight>(ambientIntensity);
            s->addLight(ambient);
        }

        // Parse diffuse light intensity (for later use in materials)
        if (lights.exists("diffuse")) {
            float diffuseIntensity = lights["diffuse"];
            s->setDiffuseIntensity(diffuseIntensity);
        }

        // Parse directional lights
        if (lights.exists("directional")) {
            const ConfSetting &directional = lights["directional"];
            
            for (int i = 0; i < directional.getLength(); ++i) {
                const ConfSetting &dirLight = directional[i];
                
                // Get direction (normalize it later)
                Vector3D direction;
                if (dirLight.exists("direction")) {
                    const ConfSetting &dir = dirLight["direction"];
                    direction.x = dir["x"].getType() == ConfSetting::TypeInt ? (int)dir["x"] : (double)dir["x"];
                    direction.y = dir["y"].getType() == ConfSetting::TypeInt ? (int)dir["y"] : (double)dir["y"];
                    direction.z = dir["z"].getType() == ConfSetting::TypeInt ? (int)dir["z"] : (double)dir["z"];
                } else {
                    // If no direction specified, use default (light from above)
                    direction = Vector3D(0.0, -1.0, 0.0);
                }
                
                // Get intensity if specified
                float intensity = 1.0f;
                if (dirLight.exists("intensity")) {
                    intensity = dirLight["intensity"];
                }
                
                auto directional = std::make_shared<DirectionalLight>(direction, intensity);
                s->addLight(directional);
            }
        }
        
        // Parse point lights
        if (lights.exists("point")) {
            const ConfSetting &pointLights = lights["point"];
            
            for (int i = 0; i < pointLights.getLength(); ++i) {
                const ConfSetting &pointLight = pointLights[i];
                
                // Get position
                double x = pointLight["x"].getType() == ConfSetting::TypeInt ? (int)pointLight["x"] : (double)pointLight["x"];
                double y = pointLight["y"].getType() == ConfSetting::TypeInt ? (int)pointLight["y"] : (double)pointLight["y"];
                double z = pointLight["z"].getType() == ConfSetting::TypeInt ? (int)pointLight["z"] : (double)pointLight["z"];
                
                // Just log for now - you'll implement point lights later
                //std::cout << "Found point light at position: (" << x << ", " << y << ", " << z << ")" << std::endl;
            }
        }
        
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Error : Parameter missing : " + std::string(nfex.getPath()));
    } catch (const libconfig::SettingTypeException &e) {
        throw std::runtime_error("Error : Invalid data type : " + std::string(e.getPath()));
    }
}