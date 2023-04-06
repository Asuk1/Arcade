/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** DynamicLoader
*/

#pragma once

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef DYNAMICLOADER_HPP_
#define DYNAMICLOADER_HPP_

namespace core {
    class DynamicLoader {
        public:
            DynamicLoader() = default;
            ~DynamicLoader() = default;

            bool loadLibrary(const std::string &path)
            {
                handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!handle) {
                    std::cerr << "Cannot open library: " << dlerror() << std::endl;
                    return false;
                }
                return true;
            }

            template <typename T>
            T loadSymbol(const std::string &symbol)
            {
                auto sym = dlsym(handle, symbol.c_str());
                if (!sym) {
                    std::cerr << "Cannot load symbol: " << dlerror() << std::endl; //the loaded symbol is cast to the expected type before being returned. If the symbol cannot be loaded, the function returns nullptr
                    return nullptr;
                }
                return reinterpret_cast<T>(sym);
            }

            void closeLibrary()
            {
                dlclose(handle);
            }
        private:
            void *handle;
    };
}

#endif /* !DYNAMICLOADER_HPP_ */