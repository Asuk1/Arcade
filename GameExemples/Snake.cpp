/*
** EPITECH PROJECT, 2022
** snake
** File description:
** snake
*/

#include "Snake.hpp"

extern "C"
{
    std::shared_ptr<arcade::interface::IGameModule> createGame()
    {
        return std::make_shared<Snake>();
    }

    std::string getType(void)
    {
        return ("game");
    }
}