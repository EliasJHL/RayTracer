/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** PluginsManager
*/

#include "PluginsManager.hpp"

PluginsManager* PluginsManager::mInstance = nullptr;

PluginsManager::PluginsManager()
{
    mMaterials["flatcolor"] = std::make_shared<Flatcolor>();
    mMaterials["metal"] = std::make_shared<Metal>();
}

PluginsManager::~PluginsManager()
{
    cleanAll();
}

void PluginsManager::cleanAll(void)
{
    mMaterials.clear();
    mLoaders.clear();
}

PluginsManager *PluginsManager::getInstance(void)
{
    if (mInstance == nullptr)
        mInstance = new PluginsManager();
    return mInstance;
}

void PluginsManager::loadMaterial(const std::string& path, const std::string &name)
{
    auto loaderIt = mLoaders.find(name);
    if (loaderIt != mLoaders.end()) {
        std::clog << "Material " << name << " (" << path << ") is already loaded." << std::endl;
        return;
    }

    try {
        auto loader = std::make_shared<DLLoader<AMaterial>>(path);
        mLoaders[name] = loader;
        AMaterial* matPtr = loader->getInstance("createMaterial");
        if (matPtr != nullptr) {
            mMaterials[name] = std::shared_ptr<AMaterial>(matPtr);
            std::clog << "[i] Material " << name << " is now loaded." << std::endl;
        } else {
            std::cerr << "[!] Failed to create material " << name << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error loading plugin " << path << ": " << e.what() << std::endl;
        return;
    }
}

std::map<std::string, std::shared_ptr<AMaterial>> PluginsManager::getAllMaterials(void)
{
    std::clog << "[d] Available materials :" << std::endl;
    for (const auto& [key, value] : mMaterials) {
        std::clog << "  - " << key << std::endl;
    }
    return mMaterials;
}

void PluginsManager::LoadAllPlugins(void)
{
    const std::filesystem::path plugins{"plugins"};
    std::regex const e{"raytracer_([A-Za-z0-9\\+]+)\\.so"};
    std::smatch m;

    for (auto const &dir : std::filesystem::directory_iterator{plugins})
    {
        std::string dirPath = std::string(dir.path());

        if (!std::regex_search(dirPath, m, e))
            continue;

        try {
            loadMaterial(dirPath, m[1]);
        } catch (const std::exception &e) {
            // load primitive
            continue;
        }
    }
}