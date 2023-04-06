/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlSprite
*/

#ifndef SFMLSPRITE_HPP_
    #define SFMLSPRITE_HPP_
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include <string>
    #include "ISpriteModule.hpp"
    #include <memory>

namespace arcade
{
    class SfmlSprite : public arcade::interface::ISpriteModule
    {
        public:
            //PROPERTIES:
            std::shared_ptr<sf::Sprite> sprite;
            std::shared_ptr<sf::Texture> texture;
            std::string _filePath;
            arcade::Color color;
            std::pair<float, float> pos;
    
            // LOGIC
    
            /**
             * @brief Construct a new Sfml Sprite object
             * 
             */
            SfmlSprite()
            {
                texture = std::make_shared<sf::Texture>();
                sprite =  std::make_shared<sf::Sprite>();
                pos.first = 0;
                pos.second = 0;
            }
            
            /**
             * @brief Destroy the Sfml Sprite object
             * 
             */
            ~SfmlSprite() = default;
            
            /**
             * @brief Get the Sprite object
             * 
             * @return void* returns the sprite object
             */
            void *getSprite() const override
            {
                return sprite.get();
            }

            /**
             * @brief Set the Sprite object
             * @attention the path must be without the extension
             * @param filePath is the path to the sprite
             */
            void setSprite(const std::string &filePath) override
            {
                _filePath = filePath;
                _filePath += ".png";
                texture->loadFromFile(_filePath);
                sprite->setTexture(*texture);
            }

            /**
             * @brief Get the Position object
             * 
             * @return std::pair<float, float> returns the position of the sprite
             */
            std::pair<float, float> getPosition() const override
            {
                return pos;
            }
    
            /**
             * @brief Set the Position object
             * 
             * @param x is the x position 
             * @param y is the y position
             */
            void setPosition(float x, float y) override
            {
                pos.first = x;
                pos.second = y;
                sprite->setPosition((sf::Vector2f){x, y});
            }

            /**
             * @brief Set the Crop object
             * 
             * @param x is the x position of the crop
             * @param y is the y position of the crop
             * @param width is the width of the crop
             * @param height is the height of the crop
             */
            void setCrop(int x, int y, int width, int height) override
            {
                sprite->setTextureRect((sf::IntRect){x, y, width, height});
            }
    
            /**
             * @brief Move the sprite
             * 
             * @param x is the x position
             * @param y is the y position
             */
            void move(float x, float y) override
            {
                sprite->setPosition((sf::Vector2f){(pos.first + x), (pos.second + y)});
            }
            
            /**
             * @brief Set the Color object
             * 
             * @param r is the red value
             * @param g is the green value
             * @param b is the blue value
             */
            void setColor(arcade::Color color) override
            {
                this->color = color;
                sprite->setColor((sf::Color){(sf::Uint8)color.r, (sf::Uint8)color.g, (sf::Uint8)color.b});
            }

            /**
             * @brief Get the Color object
             * 
             * @return arcade::Color returns the color of the sprite
             */
            arcade::Color getColor() const override
            {
                return color;
            }
    };  
}

#endif /* !SFMLSPRITE_HPP_ */
