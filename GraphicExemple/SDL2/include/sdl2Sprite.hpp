/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** sdl2Sprite
*/

#pragma once

#ifndef SDL2SPRITE_HPP_
#define SDL2SPRITE_HPP_

#include "../../../Module Interface/ISpriteModule.hpp"
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

namespace arcade
{
    class sdl2Sprite : public arcade::interface::ISpriteModule
    {
        public:
            //PROPERTIES:
            SDL_Surface *surface;
            SDL_Texture *texture;
            SDL_Renderer *rend;
            SDL_Rect position;
            std::pair<float, float> moovePos;
            arcade::Color color;

            // LOGIC

            sdl2Sprite(SDL_Window *window, SDL_Renderer *renderer);
            ~sdl2Sprite();

            void *getSprite() override;
            void setSprite(std::string filePath);
            void setPosition(float x, float y) override;
            void setCrop(int x, int y, int width, int height) override;
            void move(float x, float y) override;
            void setColor(arcade::Color newColor);
            std::pair<float, float> getPosition() const;
            arcade::Color getColor() const;
    };
}

#endif /* !SDL2SPRITE_HPP_ */
