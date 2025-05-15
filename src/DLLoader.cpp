/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

template <typename T>
DLLoader<T>::DLLoader(const std::string &path) {
    handler = dlopen(path.c_str(), RTLD_LAZY);
        
    if (handler == nullptr)
        throw std::runtime_error(dlerror());
}
template <typename T>
DLLoader<T>::~DLLoader() {
    if (handler)
        dlclose(handler);
}

template <typename T>
T *DLLoader<T>::getInstance(const std::string &symbol) const {
    void *ptr = dlsym(handler, symbol.c_str());

    if (ptr == nullptr)
        throw std::runtime_error(dlerror());
    std::function<T *(void)> symFcn = reinterpret_cast<T *(*)()>(ptr);
    return symFcn();
}