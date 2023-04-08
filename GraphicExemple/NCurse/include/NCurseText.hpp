/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** NcurseText
*/

#pragma once

#include <ncurses.h>
#include <curses.h>
#include "../../../Module Interface/ITextModule.hpp"
#include "../../../Module Interface/Color.hpp"
#include <memory>

namespace arcade
{
    class NcurseText : public arcade::interface::ITextModule
    {
    public:
        std::shared_ptr<WINDOW> window;
        std::pair<float, float> pos;
        short color;
        std::string text;
        unsigned char r;
        unsigned char g;
        unsigned char b;

        NcurseText()
        {
            window = std::make_shared<WINDOW>(newwin(0, 0, 10, 10));
            pos.first = 0;
            pos.second = 0;
            this->r = 255;
            this->g = 255;
            this->b = 255;
            color = COLOR_WHITE;
            text = " ";
        }

        ~NcurseText() = default;

        void *getText()
        {

        }

        void setText(const std::string &text)
        {
            this->text = text;
            mvwprintw(window.get(), pos.second, pos.first, text.c_str());
        }

        void setPosition(float x, float y)
        {
            pos.first = x;
            pos.second = y;
            mvwin(window.get(), y, x);
        }

        std::pair<float, float> getPosition() const
        {
            return pos;
        }

        void move(float x, float y)
        {
            pos.first += x;
            pos.second += y;
            mvwin(window.get(), pos.second, pos.first);
        }

        void setColor(arcade::Color color)
        {
            this->r = color.r;
            this->g = color.g;
            this->b = color.b;
            if (color.r == 255 && color.g == 255 && color.b == 255)
                this->color = COLOR_WHITE;
            else if (color.r == 0 && color.g == 0 && color.b == 0)
                this->color = COLOR_BLACK;
            else if (color.r == 255 && color.g == 0 && color.b == 0)
                this->color = COLOR_RED;
            else if (color.r == 0 && color.g == 255 && color.b == 0)
                this->color = COLOR_GREEN;
            else if (color.r == 0 && color.g == 0 && color.b == 255)
                this->color = COLOR_BLUE;
            else if (color.r == 255 && color.g == 255 && color.b == 0)
                this->color = COLOR_YELLOW;
            else if (color.r == 255 && color.g == 0 && color.b == 255)
                this->color = COLOR_MAGENTA;
            else if (color.r == 0 && color.g == 255 && color.b == 255)
                this->color = COLOR_CYAN;
            else
                this->color = COLOR_WHITE;
            wattron(window.get(), COLOR_PAIR(this->color));
        }

        arcade::Color getColor() const
        {

        }

        void setFontSize(unsigned int size)
        {

        }

        void setFont(const std::string &path)
        {

        }

    };
} 
