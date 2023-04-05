/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** SfmlText
*/

#pragma once

#include <SFML/Graphics/Text.hpp>
#include "../../../Module Interface/ITextModule.hpp"
#include <memory>

namespace arcade
{
    class SfmlText : public arcade::interface::ITextModule
    {
        public:
            std::shared_ptr<sf::Text> text;
            std::shared_ptr<sf::Font> font;
            std::pair<float, float> pos;
        SfmlText()
        {
            text = std::make_shared<sf::Text>();
            font = std::make_shared<sf::Font>();
            pos.first = 0;
            pos.second = 0;
        }
        
        ~SfmlText() = default;
    
        void *getText() const 
        {
            return this->text.get();
        }

        void setPosition(float x, float y)
        {
            pos.first = x;
            pos.second = y;
            text->setPosition((sf::Vector2f){x, y});
        }

        void move(float x, float y)
        {
            text->setPosition((sf::Vector2f){(pos.first + x),
            (pos.second + y)});
        }
        
        void setColor(arcade::Color color)
        {
            sf::Color colo(color.r, color.g, color.b);
            text->setFillColor(colo);
            text->setOutlineColor(colo);
        }

        void setFontSize(unsigned int size)
        {
            text->setCharacterSize(size);
        }

        void setFont(std::string font)
        {
            this->font->loadFromFile(font + ".ttf");
            this->text->setFont(*this->font);
        }

        void setSize(int size)
        {
            this->text->setCharacterSize(size);
        }

        void setText(const std::string &text)
        {
            this->text->setString(text);
        }
    };
}