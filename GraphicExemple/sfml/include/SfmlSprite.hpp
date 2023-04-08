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
    #include "../../../Module Interface/ISpriteModule.hpp"
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
            SfmlSprite();
            
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
            void *getSprite() override;

            /**
             * @brief Set the Sprite object
             * @attention the path must be without the extension
             * @param filePath is the path to the sprite
             */
            void setSprite(const std::string &filePath) override;

            /**
             * @brief Get the Position object
             * 
             * @return std::pair<float, float> returns the position of the sprite
             */
            std::pair<float, float> getPosition() const override;
    
            /**
             * @brief Set the Position object
             * 
             * @param x is the x position 
             * @param y is the y position
             */
            void setPosition(float x, float y) override;

            /**
             * @brief Set the Crop object
             * 
             * @param x is the x position of the crop
             * @param y is the y position of the crop
             * @param width is the width of the crop
             * @param height is the height of the crop
             */
            void setCrop(int x, int y, int width, int height) override;
    
            /**
             * @brief Move the sprite
             * 
             * @param x is the x position
             * @param y is the y position
             */
            void move(float x, float y) override;
            
            /**
             * @brief Set the Color object
             * 
             * @param r is the red value
             * @param g is the green value
             * @param b is the blue value
             */
            void setColor(arcade::Color color) override;

            /**
             * @brief Get the Color object
             * 
             * @return arcade::Color returns the color of the sprite
             */
            arcade::Color getColor() const override;
    };  
}

#endif /* !SFMLSPRITE_HPP_ */
