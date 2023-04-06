/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ITextModule
*/

#ifndef ITEXTMODULE_HPP_
    #define ITEXTMODULE_HPP_
    #include <string>
    #include "Color.hpp"

namespace arcade
{
    namespace interface
    {
        class ITextModule {
            public:
                virtual ~ITextModule() = default;

                /**
                 * @brief Get the Text object
                 * 
                 * @return T returns the text object
                 */
                virtual void *getText() = 0;

                /**
                 * @brief Set the Text object
                 * 
                 * @param text is the text to set
                 */
                virtual void setText(const std::string &text) = 0;

                /**
                 * @brief Set the Position object
                 * 
                 * @param x is the position to move on x axis
                 * @param y is the position to move on y axis
                 */
                virtual void setPosition(float x, float y) = 0;

                /**
                 * @brief Get the Position object
                 * 
                 * @return std::pair<float, float> is the position of the text 
                 */
                virtual std::pair<float, float> getPosition() const = 0;

                /**
                 * @brief Set the Font Size object
                 * 
                 * @param size is the size to set the font
                 */
                virtual void setFontSize(unsigned int size) = 0;

                /**
                 * @brief Set the Size object
                 * 
                 * @param x is the size to move on x axis
                 * @param y is the size to move on y axis
                 */
                virtual void move(float x, float y) = 0;

                /**
                 * @brief Set the Font object
                 * 
                 * @attention the path must be without the extension
                 * @param font is the font to set
                 */
                virtual void setFont(const std::string &font) = 0;

                /**
                 * @brief Set the Color object
                 * 
                 * @param color is the color to set
                 */
                virtual void setColor(arcade::Color color) = 0;

                /**
                * @brief Get the Color object
                * 
                * @return arcade::Color is the color of the sprite
                */
                virtual arcade::Color getColor() const = 0;

    };
    } // namespace interface
} // namespace arcade

#endif /* !ITEXTMODULE_HPP_ */
