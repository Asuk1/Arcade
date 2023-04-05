/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlSprite
*/

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include "../../../Module Interface/ISpriteModule.hpp"
#include "../../../Module Interface/Color.hpp"
#include <memory>

namespace arcade
{
    class SfmlSprite : public arcade::interface::ISpriteModule
    {
        public:
            //PROPERTIES:
            std::shared_ptr<sf::Sprite> sprite;
            std::shared_ptr<sf::Texture> texture;

            std::pair<float, float> pos;
    
            // LOGIC
    
            SfmlSprite()
            {
                texture = std::make_shared<sf::Texture>();
                sprite =  std::make_shared<sf::Sprite>();
                pos.first = 0;
                pos.second = 0;
            }
            
            ~SfmlSprite() = default;
            
            void *getSprite() const override
            {
                return sprite.get();
            }
    
            void setSprite(std::string filePath) override
            {
                filePath += ".png";
                texture->loadFromFile(filePath);
    
                sprite->setTexture(*texture);
            }
    
            void setPosition(float x, float y) override
            {
                pos.first = x;
                pos.second = y;
                sprite->setPosition((sf::Vector2f){x, y});
            }

            void setCrop(int x, int y, int width, int height) override
            {
                sprite->setTextureRect((sf::IntRect){x, y, width, height});
            }
    
            void move(float x, float y) override
            {
                sprite->setPosition((sf::Vector2f){(pos.first + x), (pos.second + y)});
            }
            
            void setColor(arcade::Color color) override
            {
                sprite->setColor((sf::Color){color.r, color.g, color.b});
            }
    };  
}