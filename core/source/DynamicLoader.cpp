/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** DynamicLoader
*/

#include "../include/DynamicLoader.hpp"

bool core::DynamicLoader::loadLibrary(const std::string &path)
{
    handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return false;
    }
    return true;
}

template <typename T>
T core::DynamicLoader::loadSymbol(const std::string &symbol)
{
    auto sym = dlsym(handle, symbol.c_str());
    if (!sym) {
        std::cerr << "Cannot load symbol: " << dlerror() << std::endl; //the loaded symbol is cast to the expected type before being returned. If the symbol cannot be loaded, the function returns nullptr
        return nullptr;
    }
    return reinterpret_cast<T>(sym);
}

void core::DynamicLoader::closeLibrary()
{
    dlclose(handle);
}