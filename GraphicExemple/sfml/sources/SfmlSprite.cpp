/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlSprite
*/

#include "../include/SfmlSprite.hpp"

arcade::SfmlSprite::SfmlSprite()
{
    texture = std::make_shared<sf::Texture>();
    sprite =  std::make_shared<sf::Sprite>();
    pos.first = 0;
    pos.second = 0;
}

void *arcade::SfmlSprite::getSprite() const
{
    return sprite.get();
}

void arcade::SfmlSprite::setSprite(const std::string &filePath)
{
    _filePath = filePath;
    texture->loadFromFile(filePath);
    sprite->setTexture(*texture);
}

std::pair<float, float> arcade::SfmlSprite::getPosition() const
{
    return pos;
}

void arcade::SfmlSprite::setPosition(float x, float y)
{
    pos.first = x;
    pos.second = y;
    sprite->setPosition(pos.first, pos.second);
}

void arcade::SfmlSprite::setCrop(int x, int y, int width, int height)
{
    sprite->setTextureRect(sf::IntRect(x, y, width, height));
}

void arcade::SfmlSprite::move(float x, float y)
{
    pos.first += x;
    pos.second += y;
    sprite->move(x, y);
}

void arcade::SfmlSprite::setColor(arcade::Color color)
{
    this->color = color;
    sprite->setColor((sf::Color){(sf::Uint8)color.r, (sf::Uint8)color.g, (sf::Uint8)color.b});
}

arcade::Color arcade::SfmlSprite::getColor() const
{
    return color;
}