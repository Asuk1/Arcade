/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlText
*/

#ifndef SFMLTEXT_HPP_
    #define SFMLTEXT_HPP_
    #include <SFML/Graphics/Text.hpp>
    #include "ITextModule.hpp"
    #include <memory>

namespace arcade
{
    class SfmlText : public arcade::interface::ITextModule
    {
        public:
            std::shared_ptr<sf::Text> text;
            std::shared_ptr<sf::Font> font;
            std::pair<float, float> pos;
            arcade::Color color;

        /**
         * @brief Construct a new Sfml Text object
         * 
         */
        SfmlText()
        {
            text = std::make_shared<sf::Text>();
            font = std::make_shared<sf::Font>();
            pos.first = 0;
            pos.second = 0;
        }
        
        /**
         * @brief Destroy the Sfml Text object
         * 
         */
        ~SfmlText() = default;
    
        /**
         * @brief Get the Text object
         * 
         * @return void* is the text object
         */
        void *getText() const override
        {
            return this->text.get();
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
            text->setPosition((sf::Vector2f){x, y});
        }

        /**
         * @brief Move the text
         * 
         * @param x is the x position
         * @param y is the y position
         */
        void move(float x, float y) override
        {
            text->setPosition((sf::Vector2f){(pos.first + x),
            (pos.second + y)});
        }
        
        /**
         * @brief Set the Color object
         * 
         * @param color is the color to use
         */
        void setColor(arcade::Color color) override
        {
            this->color = color;
            sf::Color colo(color.r, color.g, color.b);
            text->setFillColor(colo);
            text->setOutlineColor(colo);
        }

        /**
         * @brief Get the Color object
         * 
         * @return arcade::Color returns the color of the text
         */
        arcade::Color getColor() const override
        {
            return color;
        }

        /**
         * @brief Set the Font Size object
         * 
         * @param size is the size of the font
         */
        void setFontSize(unsigned int size) override
        {
            text->setCharacterSize(size);
        }

        /**
         * @brief Set the Font object
         * @attention the path must be without the extension
         * @param font is the font to use
         */
        void setFont(const std::string &font) override
        {
            this->font->loadFromFile(font + ".ttf");
            this->text->setFont(*this->font);
        }

        /**
         * @brief Set the Text object
         * 
         * @param text is the text to display
         */
        void setText(const std::string &text) override
        {
            this->text->setString(text);
        }
    };
}
#endif /* !SFMLTEXT_HPP_ */
