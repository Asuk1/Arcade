/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** NCurseSymbols
*/

#include "../include/NCurseDisplay.hpp"
#include "../include/NCurseSprite.hpp"
#include "../include/NCurseText.hpp"
#include <memory>
#include <string>

extern "C"
{
    std::shared_ptr<arcade::interface::IDisplayModule> createDisplay()
    {
        return std::make_shared<arcade::NcurseDisplay>();
    }

    std::string getName(void)
    {
        return "ncurses";
    }
}
