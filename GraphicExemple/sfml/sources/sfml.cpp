/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlSymbols
*/

#include "SfmlDisplay.hpp"
#include "SfmlSprite.hpp"
#include "SfmlText.hpp"
#include "SfmlAudio.hpp"
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
