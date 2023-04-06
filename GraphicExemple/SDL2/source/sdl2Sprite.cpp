/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** sdl2Sprite
*/

#include "../include/sdl2Sprite.hpp"

arcade::sdl2Sprite::sdl2Sprite(SDL_Window *window, SDL_Renderer *renderer)
{
    rend = renderer;
    surface = nullptr;
    texture = nullptr;
    position.x = 0;
    position.y = 0;
    moovePos.first = 0;
    moovePos.second = 0;
}

arcade::sdl2Sprite::~sdl2Sprite()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(rend);
}

void *arcade::sdl2Sprite::getSprite()
{
    return texture;
}

void arcade::sdl2Sprite::setSprite(std::string filePath)
{
    filePath += ".png";
    surface = IMG_Load(filePath.c_str());

    texture = SDL_CreateTextureFromSurface(rend, surface);
}

void arcade::sdl2Sprite::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
    SDL_RenderCopy(rend, texture, NULL, &position);
}

void arcade::sdl2Sprite::setCrop(int x, int y, int width, int height)
{
    // sprite->setTextureRect((SDL_Rect){x, y, width, height});
}

void arcade::sdl2Sprite::move(float x, float y)
{
    SDL_Rect moove;
    moove.x = position.x + x;
    moove.y = position.y + y;
    SDL_RenderCopy(rend, texture, NULL, &moove);

}

void arcade::sdl2Sprite::setColor(arcade::Color newColor)
{
    color = newColor;
    SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

std::pair<float, float> arcade::sdl2Sprite::getPosition() const
{
    return std::make_pair(position.x, position.y);
}

arcade::Color arcade::sdl2Sprite::getColor() const
{
    return color;
}