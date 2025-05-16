/*
** EPITECH PROJECT, 2025
** B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <functional>
#include <dlfcn.h>
#include <stdexcept>

template <typename T>
class DLLoader {
public:
    DLLoader(const std::string &path) {
        handler = dlopen(path.c_str(), RTLD_LAZY);
            
        if (handler == nullptr)
            throw std::runtime_error(dlerror());
    }

    ~DLLoader() {
        // if (handler)
        //     dlclose(handler);
    }

    T *getInstance(const std::string &symbol) const {
        void *ptr = dlsym(handler, symbol.c_str());

        if (ptr == nullptr)
            throw std::runtime_error(dlerror());
        std::function<T *(void)> symFcn = reinterpret_cast<T *(*)()>(ptr);
        return symFcn();
    }

private:
    void *handler;
};

#endif /* !DLLOADER_HPP_ */