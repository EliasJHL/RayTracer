/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** PluginsManager
*/

#ifndef PLUGINSMANAGER_HPP_
#define PLUGINSMANAGER_HPP_

/* SINGLETON */

#include <map>
#include <regex>
#include <memory>
#include <iostream>
#include <filesystem>
#include "DLLoader.hpp"
#include "Abstracts/AMaterial.hpp"
#include "RayTracer/Materials/Metal.hpp"
#include "RayTracer/Materials/Flatcolor.hpp"

class PluginsManager {
    public:
        PluginsManager(const PluginsManager&) = delete;
        PluginsManager& operator=(const PluginsManager&) = delete;

        static PluginsManager *getInstance(void);

        void loadMaterial(const std::string &path, const std::string &name);

        std::map<std::string, std::shared_ptr<AMaterial>> getAllMaterials(void);

        void cleanAll(void);

        void LoadAllPlugins(void);

    private:
        PluginsManager();
        ~PluginsManager();

        static PluginsManager *mInstance;

        std::map<std::string, std::shared_ptr<DLLoader<AMaterial>>> mLoaders;
        std::map<std::string, std::shared_ptr<AMaterial>> mMaterials;
};

#endif /* !PLUGINSMANAGER_HPP_ */
