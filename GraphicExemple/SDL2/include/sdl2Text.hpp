/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** sdl2Text
*/

#pragma once

#ifndef SDL2TEXT_HPP_
#define SDL2TEXT_HPP_

#include "../../../Module Interface/ITextModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <memory>

namespace arcade
{
    class sdl2Text : public arcade::interface::ITextModule
    {
        public:
            // std::shared_ptr<SDL_Text> text;
            SDL_Surface *_text;
            SDL_Texture *_display;
            TTF_Font *font;
            std::string _fontPath;
            SDL_Color _color;
            SDL_Rect position;
            std::pair<float, float> moovePos;
            SDL_Renderer *rend;
        
            sdl2Text(SDL_Renderer *renderer);
            ~sdl2Text();
            void *getText() const;
            void setPosition(float x, float y);
            void move(float x, float y);
            void setColor(arcade::Color color);
            void setFontSize(unsigned int size);
            void setFont(const std::string &font);
            void setText(const std::string &text);
            std::pair<float, float> getPosition() const;
            arcade::Color getColor() const;
    };
}

#endif /* !SDL2TEXT_HPP_ */
