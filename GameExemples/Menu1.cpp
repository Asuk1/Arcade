/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Game1
*/

#include "Menu1.hpp"
#include <memory>

extern "C"
{
    std::shared_ptr<arcade::interface::IGameModule> createGame()
    {
        return std::make_shared<Menu1>();
    }

    std::string getType(void)
    {
        return ("menu");
    }
}