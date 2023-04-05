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
        // PROPERTIES:
        std::shared_ptr<WINDOW> window;
        std::pair<float, float> pos;
        char texture;
        char sprite;
        char color;
        unsigned char r;
        unsigned char g;
        unsigned char b;

        // LOGIC

        NcurseSprite()
        {
            window = std::make_shared<WINDOW>(newwin(0, 0, 0, 0));
            texture = ' ';
            sprite =  ' ';
            pos.first = 0;
            pos.second = 0;
            this->r = 255;
            this->g = 255;
            this->b = 255;
        }

        ~NcurseSprite() = default;

        void *getSprite() const override
        {
    
        }

        void setSprite(std::string filePath) override
        {

        }

        void setPosition(float x, float y) override
        {
            pos.first = x;
            pos.second = y;
            wmove(window.get(), pos.second, pos.first);
        }

        void setCrop(int x, int y, int width, int height) override
        {
            wresize(window.get(), height, width);
        }

        void move(float x, float y) override
        {
            pos.first += x;
            pos.second += y;
            mvwin(window.get(), pos.second, pos.first);
        }

        void setColor(unsigned char r, unsigned char g, unsigned char b) override
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }

    };
}
