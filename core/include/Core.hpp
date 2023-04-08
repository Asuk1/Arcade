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
    #include <cstring>

//Dynamic loader -> open .so récupérer les infos(getinfo(std::string info)) et close


namespace code {
    class Core {
        public:
            Core(const std::string &path);

            ~Core();

            int loop_for_game();

            void load_actual_lib(const std::string& lib_path);

            void load_actual_game(const std::string &game_path);

            void load_actual_menu(const std::string &menu_path);

            bool load_prev_lib();

            bool load_next_lib();

            bool load_prev_game();

            bool load_next_game();

            bool load_prev_menu();

            bool load_next_menu();

            int handle_value_returned();

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
            
            arcade::User_data _user_data;
            bool _is_menu_still_running;
            int return_value;
    };
}
//changer les proto plus explicites

#endif /* !CORE_HPP_ */