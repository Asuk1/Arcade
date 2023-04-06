/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlText
*/

#include "../include/SfmlText.hpp"

arcade::SfmlText::SfmlText()
{
    text = std::make_shared<sf::Text>();
    font = std::make_shared<sf::Font>();
    pos.first = 0;
    pos.second = 0;
}

void *arcade::SfmlText::getText() const
{
    return this->text.get();
}

std::pair<float, float> arcade::SfmlText::getPosition() const
{
    return pos;
}

void arcade::SfmlText::setPosition(float x, float y)
{
    pos.first = x;
    pos.second = y;
    text->setPosition(pos.first, pos.second);
}

void arcade::SfmlText::move(float x, float y)
{
    text->setPosition((sf::Vector2f){(pos.first + x),
    (pos.second + y)});
}

void arcade::SfmlText::setColor(arcade::Color color)
{
    this->color = color;
    sf::Color colo(color.r, color.g, color.b);
    text->setFillColor(colo);
    text->setOutlineColor(colo);
}

arcade::Color arcade::SfmlText::getColor() const
{
    return color;
}

void arcade::SfmlText::setFontSize(unsigned int size)
{
    text->setCharacterSize(size);
}

void arcade::SfmlText::setFont(const std::string &font)
{
    this->font->loadFromFile(font + ".ttf");
    this->text->setFont(*this->font);
}

void arcade::SfmlText::setText(const std::string &text)
{
    this->text->setString(text);
}