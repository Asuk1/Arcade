/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** sdl2Text
*/

#include "../include/sdl2Text.hpp"

arcade::sdl2Text::sdl2Text(SDL_Renderer *renderer)
{
    _text = nullptr;
    font = nullptr;
    moovePos.first = 0;
    moovePos.second = 0;
    position.x = 0;
    position.y = 0;
    rend = renderer;
}

arcade::sdl2Text::~sdl2Text()
{
    TTF_CloseFont(font);
    SDL_FreeSurface(_text);
    SDL_DestroyTexture(_display);
}

void *arcade::sdl2Text::getText() const
{
    return _display;
}

void arcade::sdl2Text::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void arcade::sdl2Text::move(float x, float y)
{
    moovePos.first = position.x + x;
    moovePos.second = position.y + y;
}

void arcade::sdl2Text::setColor(arcade::Color color)
{
    color.r = _color.r;
    color.g = _color.g;
    color.b = _color.b;
}

void arcade::sdl2Text::setFontSize(unsigned int size)
{
    TTF_CloseFont(font);
    font = TTF_OpenFont(_fontPath.c_str(), size);
}

void arcade::sdl2Text::setFont(const std::string &font)
{
    _fontPath = font;
    this->font = TTF_OpenFont(_fontPath.c_str(), 32);
}

void arcade::sdl2Text::setText(const std::string &text)
{
    _text = TTF_RenderText_Blended(font, text.c_str(), _color);
    SDL_DestroyTexture(_display);
    _display = SDL_CreateTextureFromSurface(rend, _text);
}

std::pair<float, float> arcade::sdl2Text::getPosition() const
{
    return std::make_pair(position.x, position.y);
}

arcade::Color arcade::sdl2Text::getColor() const
{
    arcade::Color retColor(_color.r, _color.g, _color.b, _color.a);
    return retColor;
}