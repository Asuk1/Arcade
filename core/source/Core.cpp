/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core
*/

#include "../include/Core.hpp"

code::Core::Core(const std::string &path) : _user_data()
{
    this->return_value = 0;
    this->_is_menu_still_running = true;
    this->_actual_game = 0;
    this->_actual_menu = 0;

    // load all yout actual graphicals library

    _libs = {"./lib/arcade_ncurses.so", "./lib/arcade_sdl2.so", "./lib/arcade_sfml.so"};
    for (int i = 0; i < _libs.size(); ++i) {
        if (path == _libs[i]) {
            this->_actual_lib = i;
            this->load_actual_lib(_libs[i]);
            break;
        }
    }

    _games = {"./lib/arcade_snake.so", "./lib/arcade_pacman.so"};
    for (int i = 0; i < _games.size(); ++i) {
        if (path == _games[i]) {
            this->_actual_game = i;
            this->load_actual_game(_games[i]);
            break;
        }
    }
    _game.get()->Initialisation(_lib);

    // init param of window if you want

    this->_lib->setWindowTitle("Arcade");
    this->_lib->setFps(60);
    this->_lib->setResolution(1600, 900);

}

code::Core::~Core()
{

}


int code::Core::loop_for_game()
{
    while (this->_lib->isOpen())
    {
        if (this->_is_menu_still_running) {
            try {
                this->return_value = this->_menu->update(this->_lib, this->_user_data, _games, _libs, _menus, _actual_lib, _actual_game, _actual_menu);
            } catch (const std::exception &e) {
                std::cerr << "Error Game: " << e.what() << "\n";
            }
        } else {
            try {
                this->return_value = this->_game->update(this->_lib, this->_user_data, _games, _libs, _menus, _actual_lib, _actual_game, _actual_menu);
            } catch (const std::exception &e) {
                std::cerr << "Error Game: " << e.what() << "\n";
            }
        }
        if (this->handle_value_returned() == 84)
            return 84;
        /*this->return_value = 0; reset le ret value a zero a chaque tour de boucle
        un truc qui va raffraichir de rafraichir la list des lib a chaque tour de boucle
        this->_graph->fetchInputs(); permet de rafraichir les inputs a chaque tour de boucle
        if (this->_graph->isKeyPressed(arcade::interface::Escape)) permet de quitter le jeu si on appuie sur echap
            return 0;
        */
    }
}

void code::Core::load_actual_lib(const std::string& lib_path)
{
    std::shared_ptr<arcade::interface::IDisplayModule> (*createDisplay)();

    try {
        _libLoader->loadLibrary(lib_path);
    } catch (const std::exception& ex) {
        throw std::runtime_error("Error: cannot load library from path: " + lib_path + " (" + ex.what() + ")");
    }
    if (_libLoader != nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + lib_path);
    createDisplay = _libLoader->loadSymbol<std::shared_ptr<arcade::interface::IDisplayModule> (*)()>("createDisplay");
    if (createDisplay == nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + lib_path);
    this->_lib = createDisplay();
    if (this->_lib == nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + lib_path);
}

void code::Core::load_actual_game(const std::string &game_path)
{
    std::shared_ptr<arcade::interface::IGameModule> (*createGame)();

    try {
        _gameLoader->loadLibrary(game_path);;
    } catch (const std::exception& ex) {
        throw std::runtime_error("Error: cannot load library from path: " + game_path + " (" + ex.what() + ")");
    }
    if (_gameLoader != nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + game_path);
    createGame = _libLoader->loadSymbol<std::shared_ptr<arcade::interface::IGameModule> (*)()>("createGame");
    if (createGame == nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + game_path);
    this->_game = createGame();
    if (this->_game == nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + game_path);
}

void code::Core::load_actual_menu(const std::string &menu_path)
{
    std::shared_ptr<arcade::interface::IGameModule> (*createMenu)();

    try {
        _menuLoader->loadLibrary(menu_path);
    } catch (const std::exception& ex) {
        throw std::runtime_error("Error: cannot load library from path: " + menu_path + " (" + ex.what() + ")");
    }
    if (_menuLoader != nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + menu_path);
    createMenu = _libLoader->loadSymbol<std::shared_ptr<arcade::interface::IGameModule> (*)()>("createMenu");
    if (createMenu == nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + menu_path);
    this->_menu = createMenu();
    if (this->_menu == nullptr)
        throw std::runtime_error("Error: cannot load library from path: " + menu_path);
}

bool code::Core::load_prev_lib()
{
    if (_actual_lib == 0)
        _actual_lib = _libs.size() - 1;
    else
        _actual_lib--;
    load_actual_lib(_libs[_actual_lib]);
    return true;
}

bool code::Core::load_next_lib()
{
    if (_actual_lib == _libs.size() - 1)
        _actual_lib = 0;
    else
        _actual_lib++;
    load_actual_lib(_libs[_actual_lib]);
    return true;
}

bool code::Core::load_prev_game()
{
    if (_actual_game == 0)
        _actual_game = _games.size() - 1;
    else
        _actual_game--;
    load_actual_game(_games[_actual_game]);
    return true;
}

bool code::Core::load_next_game()
{
    if (_actual_game == _games.size() - 1)
        _actual_game = 0;
    else
        _actual_game++;
    load_actual_game(_games[_actual_game]);
    return true;
}

bool code::Core::load_prev_menu()
{
    if (_actual_menu == 0)
        _actual_menu = _menus.size() - 1;
    else
        _actual_menu--;
    load_actual_menu(_menus[_actual_menu]);
    return true;
}

bool code::Core::load_next_menu()
{
    if (_actual_menu == _menus.size() - 1)
        _actual_menu = 0;
    else
        _actual_menu++;
    load_actual_menu(_menus[_actual_menu]);
    return true;
}

int code::Core::handle_value_returned()
{
    if (return_value == 1) {
        if (!load_next_game())
            return 84;
        _game->Initialisation(this->_lib);
    } else if (return_value == -1) {
        if (!load_prev_game())
            return 84;
        _game->Initialisation(this->_lib);
    } else if (return_value == 69) {
        _is_menu_still_running = false;
    } else if (return_value == 2) {
        if (!load_next_lib())
            return 84;
        _game->Initialisation(this->_lib);
        _menu->Initialisation(this->_lib);
    } else if (return_value == -2) {
        if (!load_prev_lib())
            return 84;
        _game->Initialisation(this->_lib);
        _menu->Initialisation(this->_lib);
    } else if (return_value == 3) {
        if (!load_next_menu())
            return 84;
        _menu->Initialisation(this->_lib);
    } else if (return_value == -3) {
        if (!load_prev_menu())
            return 84;
        _menu->Initialisation(this->_lib);
    } else if (return_value == 84) {
        return 84;
    }

    return 0;
}
