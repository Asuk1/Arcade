/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlSymbols
*/

#include "../include/SfmlDisplay.hpp"
#include "../include/SfmlSprite.hpp"
#include "../include/SfmlText.hpp"
#include "../include/SfmlAudio.hpp"
#include <memory>
#include <string>

extern "C"
{
    std::shared_ptr<arcade::interface::IDisplayModule> createDisplay()
    {
        return std::make_shared<arcade::SfmlDisplay>();
    }

    std::string getType(void)
    {
        return "graph";
    }
}
