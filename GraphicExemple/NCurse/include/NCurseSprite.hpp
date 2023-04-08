/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** NCurseSprite
*/

#pragma once

#include <ncurses.h>
#include <curses.h>
#include <string>
#include "../../../Module Interface/ISpriteModule.hpp"
#include <memory>

namespace arcade
{
    class NcurseSprite : public arcade::interface::ISpriteModule
    {
    public:
        std::shared_ptr<WINDOW> window;
        std::pair<float, float> pos;
        std::string texture;
        std::string sprite;
        chtype color;
        int r;
        int g;
        int b;

        NcurseSprite()
        {
            window = std::make_shared<WINDOW>(newwin(0, 0, 0, 0));
            texture = " ";
            sprite = " ";
            pos.first = 0;
            pos.second = 0;
            r = 255;
            g = 255;
            b = 255;
        }

        ~NcurseSprite() = default;

        void *getSprite()
        {

        }

        void setSprite(const std::string &path)
        {

        }

        void setPosition(float x, float y)
        {
            pos.first = x;
            pos.second = y;
            wmove(window.get(), pos.second, pos.first);
        }

        std::pair<float, float> getPosition() const
        {
            return pos;
        }

        void setCrop(int x, int y, int width, int height) 
        {
            wresize(window.get(), height, width);
            pos.first += x;
            pos.second += y;
            mvwin(window.get(), pos.second, pos.first);
        }

        void move(float x, float y) 
        {
            pos.first += x;
            pos.second += y;
            mvwin(window.get(), pos.second, pos.first);
        }

        void setColor(arcade::Color color) 
        {
            r = color.r;
            g = color.g;
            b = color.b;
            init_color(COLOR_WHITE + 1, r * 1000 / 255, g * 1000 / 255, b * 1000 / 255);
            init_pair(1, COLOR_WHITE + 1, COLOR_BLACK);
            this->color = COLOR_PAIR(1);
        }


        arcade::Color getColor() const
        {

        }
    };
}
