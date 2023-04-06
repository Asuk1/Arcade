/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlDisplay
*/

#ifndef SFMLDISPLAY_HPP_
    #define SFMLDISPLAY_HPP_
    #include <map>
    #include "IDisplayModule.hpp"
    #include "SfmlSprite.hpp"
    #include "SfmlText.hpp"
    #include "SfmlAudio.hpp"
    #include <SFML/Window.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Window/Event.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>

namespace arcade
{
    class SfmlDisplay : public arcade::interface::IDisplayModule
    {
        public:
            std::shared_ptr<sf::RenderWindow> window;
            std::map<arcade::interface::KeyCode, bool> pressedKeys;
        
            /**
             * @brief Destroy the Sfml Display object
             * 
             */
            void closeWindow() override;

            /**
             * @brief Construct a new Sfml Display object
             * 
             */
            SfmlDisplay();
        
            /**
             * @brief Set the Resolution object
             * 
             * @param x is the width of the window
             * @param y is the height of the window
             */
            void setResolution(unsigned int x, unsigned int y) override;

            /**
             * @brief Set the Window Title object
             * 
             * @param title is the title of the window
             */
            void setWindowTitle(const std::string &title) override;

            /**
             * @brief Check if a key is pressed
             * 
             * @return true if the key is pressed
             * @return false if the key is not pressed
             */
            bool isOpen() const override;

            /**
             * @brief Check if a key is pressed
             * 
             */
            void clearWindow() override;
            
            /**
             * @brief Display the window
             * 
             */
            void displayWindow() override;
            
            /**
             * @brief Check if a key is pressed
             * 
             * @return true if the key is pressed
             * @return false if the key is not pressed
             */
            bool isTextMode() const override;
            
            /**
             * @brief Get the Window Width object
             * 
             * @return unsigned int is the width of the window
             */
            unsigned int getWindowWidth() const override;

            /**
             * @brief Get the Window Height object
             * 
             * @return unsigned int is the height of the window
             */
            unsigned int getWindowHeight() const override;

            /**
             * @brief Set the Full Screen object
             * 
             * @param state is the state of the window
             */
            void setFullScreen(bool state) override;

            /**
             * @brief Create a Sprite object
             * 
             * @return std::shared_ptr<arcade::interface::ISpriteModule> 
             */
            std::shared_ptr<arcade::interface::ISpriteModule> createSprite() override;

            /**
             * @brief Create a Text object
             * 
             * @return std::shared_ptr<arcade::interface::ITextModule> 
             */
            std::shared_ptr<arcade::interface::ITextModule> createText() override;

            /**
             * @brief Create a Audio object
             * 
             * @return std::shared_ptr<arcade::interface::IAudioModule> 
             */
            std::shared_ptr<arcade::interface::IAudioModule> createAudio() override;
            
            /**
             * @brief Fetch the inputs from the window
             * 
             */
            void fetchInputs() override;

            /**
             * @brief Check if a key is pressed
             * 
             * @param key is the key to check
             * @return true if the key is pressed
             * @return false if the key is not pressed
             */
            bool isKeyPressed(arcade::interface::KeyCode key) override;

            /**
             * @brief Get the Mouse X Position object
             * 
             * @return unsigned int position of the mouse on the x axis
             */
            unsigned int getMouseXPosition() const override;

            /**
             * @brief Get the Mouse Y Position object
             * 
             * @return unsigned int position of the mouse on the y axis
             */
            unsigned int getMouseYPosition() const override;

            /**
             * @brief Set the Fps object
             * 
             * @param fps is the number of frame per second
             */
            void setFps(int fps) override;
            
            /**
             * @brief Draw a sprite on the screen
             * 
             * @param spriteModule is the sprite to draw
             */
            void draw(std::shared_ptr<arcade::interface::ISpriteModule> spriteModule) override;

            /**
             * @brief Draw a text on the screen
             * 
             * @param textModule is the text to draw
             */
            void draw(std::shared_ptr<arcade::interface::ITextModule> textModule) override;
    };  
}
#endif /* !SFMLDISPLAY_HPP_ */
