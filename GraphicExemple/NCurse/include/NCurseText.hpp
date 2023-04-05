/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** SfmlText
*/

#pragma once

#include <ncurses.h>
#include <curses.h>
#include "../../../Module Interface/ITextModule.hpp"
#include <memory>

namespace arcade
{
    class NcurseText : public arcade::interface::ITextModule
    {
    public:
        std::shared_ptr<WINDOW> window;
        std::pair<float, float> pos;
        char color;
        std::string text;
        unsigned char r;
        unsigned char g;
        unsigned char b;
        std::string str;

        NcurseText()
        {
            window = std::make_shared<WINDOW>(newwin(0, 0, 0, 0));
            pos.first = 0;
            pos.second = 0;
            this->r = 255;
            this->g = 255;
            this->b = 255;
            str =  " ";
        }

        ~NcurseText() = default;

        void *getText() const override
        {
            
        }

        void setPosition(float x, float y)
        {
            pos.first = x;
            pos.second = y;
            //setsyx(pos.second, pos.first);
        }

        void move(float x, float y)
        {
            pos.first += x;
            pos.second += y;
            mvwin(window.get(), pos.second, pos.first);
        }

        void setColor(unsigned char r, unsigned char g, unsigned char b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        void setText(const std::string &text) override
        {
            mvaddstr(pos.second, pos.first, text.c_str());
        }

        void setFontSize(unsigned int size)
        {

        }

        void setFont(std::string font)
        {

        }

    };
}
