/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

    #include <string>
    #include <vector>
    #include <memory>
    #include <iostream>
    #include <filesystem>
    #include "../Module Interface/UserModule.hpp"
    #include "../Module Interface/IGameModule.hpp"
    #include "../Module Interface/IDisplayModule.hpp"
    #include <exception>
    #include "DynamicLoader.hpp"
    #include <filesystem>

//Dynamic loader -> open .so récupérer les infos(getinfo(std::string info)) et close


namespace code {
    class Core {
        public:
            Core(const std::string &path)
                : _libLoader(std::make_shared<core::DynamicLoader>()),
                  _gameLoader(std::make_shared<core::DynamicLoader>()),
                  _menuLoader(std::make_shared<core::DynamicLoader>()),
                  _actual_lib(0), _actual_game(0), _actual_menu(0),
                  _is_menu_still_running(true), return_value(0)
            {
                // Load all libraries from the given path
                for (const auto &entry : std::filesystem::directory_iterator(path)) {
                    if (entry.path().extension() == ".so") {
                        std::string lib_path = entry.path().filename(); // entry.path() returns a filesystem::path object which represents the path of the file or directory. In this case, entry is an object representing an entry in the directory pointed to by path
                        std::string lib_name = entry.path().stem().string(); // entry.path() returns a filesystem::path object which represents the path of the file or directory. In this case, entry is an object representing an entry in the directory pointed to by path
                        try {
                            std::cout << "Library " << lib_name <<" successfully loaded." << std::endl;
                        } catch (const std::exception& ex) {
                            std::cerr << "Error: cannot load library " << lib_name <<" (" << ex.what() << ")" << std::endl;
                        }
                    }
                }

                if (_libs.empty()) {
                    throw std::runtime_error("Error: no libraries found in path " + path);
                }

                // Load the first library as the default one
                load_actual_lib(_libs[_actual_lib]);

                // Load the menu module
                load_actual_menu("lib_arcade_menu.so");

                // Start the loop for the game
                loop_for_game();
            }

            ~Core()
            {
                _libLoader->closeLibrary();
                _gameLoader->closeLibrary();
                _menuLoader->closeLibrary();
            }


            int loop_for_game()
            {
                while (_is_menu_still_running) {
                    // Load the menu module
                    load_actual_menu(_menus[_actual_menu]);

                    // Load the first game as the default one
                    load_actual_game(_games[_actual_game]);

                    // Start the loop for the game
                    loop_for_game();
                }
                return return_value;
            }

            void load_actual_lib(const std::string& lib_path)
            {
                try {
                    _libLoader->loadLibrary(lib_path);
                    auto tmp = _libLoader->loadSymbol<arcade::interface::IDisplayModule *(*)()>("createModule");
                    arcade::interface::IDisplayModule *_lib = tmp();

                } catch (const std::exception& ex) {
                    throw std::runtime_error("Error: cannot load library from path: " + lib_path + " (" + ex.what() + ")");
                }
            }

            void load_actual_game(const std::string &game_path)
            {
                try {
                    _gameLoader->loadLibrary(game_path);
                } catch (const std::exception& ex) {
                    throw std::runtime_error("Error: cannot load library from path: " + game_path + " (" + ex.what() + ")");
                }
            }

            void load_actual_menu(const std::string &menu_path)
            {
                try {
                    _menuLoader->loadLibrary(menu_path);
                } catch (const std::exception& ex) {
                    throw std::runtime_error("Error: cannot load library from path: " + menu_path + " (" + ex.what() + ")");
                }
            }

            bool load_prev_lib()
            {
                if (_actual_lib == 0)
                    _actual_lib = _libs.size() - 1;
                else
                    _actual_lib--;
                load_actual_lib(_libs[_actual_lib]);
                return true;
            }

            bool load_next_lib()
            {
                if (_actual_lib == _libs.size() - 1)
                    _actual_lib = 0;
                else
                    _actual_lib++;
                load_actual_lib(_libs[_actual_lib]);
                return true;
            }

            bool load_prev_game()
            {
                if (_actual_game == 0)
                    _actual_game = _games.size() - 1;
                else
                    _actual_game--;
                load_actual_game(_games[_actual_game]);
                return true;
            }

            bool load_next_game()
            {
                if (_actual_game == _games.size() - 1)
                    _actual_game = 0;
                else
                    _actual_game++;
                load_actual_game(_games[_actual_game]);
                return true;
            }

            bool load_prev_menu()
            {
                if (_actual_menu == 0)
                    _actual_menu = _menus.size() - 1;
                else
                    _actual_menu--;
                load_actual_menu(_menus[_actual_menu]);
                return true;
            }

            bool load_next_menu()
            {
                if (_actual_menu == _menus.size() - 1)
                    _actual_menu = 0;
                else
                    _actual_menu++;
                load_actual_menu(_menus[_actual_menu]);
                return true;
            }

            void handle_value_returned()
            {
                if (return_value == 1)
                    load_next_lib();
                else if (return_value == 2)
                    load_prev_lib();
                else if (return_value == 3)
                    load_next_game();
                else if (return_value == 4)
                    load_prev_game();
                else if (return_value == 5)
                    load_next_menu();
                else if (return_value == 6)
                    load_prev_menu();
                else if (return_value == 7)
                    _is_menu_still_running = false;
            }



        private:
            std::shared_ptr<core::DynamicLoader> _libLoader;
            std::shared_ptr<core::DynamicLoader> _gameLoader;
            std::shared_ptr<core::DynamicLoader> _menuLoader;

            std::shared_ptr<arcade::interface::IDisplayModule> _lib;
            std::shared_ptr<arcade::interface::IGameModule> _game;
            std::shared_ptr<arcade::interface::IGameModule> _menu;

            std::vector<std::string> _libs;
            std::vector<std::string> _games;
            std::vector<std::string> _menus;

            size_t _actual_lib;
            size_t _actual_game;
            size_t _actual_menu;

            bool _is_menu_still_running;
            int return_value;
    };
}
//changer les proto plus explicites

#endif /* !CORE_HPP_ */