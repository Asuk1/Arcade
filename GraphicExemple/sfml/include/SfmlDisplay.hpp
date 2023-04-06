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
            void closeWindow() override
            {
                window->close();
            }

            /**
             * @brief Construct a new Sfml Display object
             * 
             */
            SfmlDisplay()
            {
                window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, (1080)), "Arcade Sfml");
            }
        
            /**
             * @brief Set the Resolution object
             * 
             * @param x is the width of the window
             * @param y is the height of the window
             */
            void setResolution(unsigned int x, unsigned int y) override
            {
                window->setSize((sf::Vector2u){x, y});
            }

            /**
             * @brief Set the Window Title object
             * 
             * @param title is the title of the window
             */
            void setWindowTitle(const std::string &title) override
            {
                window->setTitle(title);
            }

            /**
             * @brief Check if a key is pressed
             * 
             * @return true if the key is pressed
             * @return false if the key is not pressed
             */
            bool isOpen() const override
            {
                return window->isOpen();
            }

            /**
             * @brief Check if a key is pressed
             * 
             */
            void clearWindow() override
            {
                window->clear(sf::Color::Black);
            }
            
            /**
             * @brief Display the window
             * 
             */
            void displayWindow() override
            {
                window->display();
            }
            
            /**
             * @brief Check if a key is pressed
             * 
             * @return true if the key is pressed
             * @return false if the key is not pressed
             */
            bool isTextMode() const override
            {
                return false;
            }
            
            /**
             * @brief Get the Window Width object
             * 
             * @return unsigned int is the width of the window
             */
            unsigned int getWindowWidth() const override
            {
                return window->getSize().x;
            }

            /**
             * @brief Get the Window Height object
             * 
             * @return unsigned int is the height of the window
             */
            unsigned int getWindowHeight() const override
            {
                return window->getSize().y;
            }

            /**
             * @brief Set the Full Screen object
             * 
             * @param state is the state of the window
             */
            void setFullScreen(bool state) override
            {
                (void)state;
                window->create(sf::VideoMode(1920, 1080), "Arcade Sfml", sf::Style::Fullscreen);
            }

            /**
             * @brief Create a Sprite object
             * 
             * @return std::shared_ptr<arcade::interface::ISpriteModule> 
             */
            std::shared_ptr<arcade::interface::ISpriteModule> createSprite() override
            {
                return std::make_shared<arcade::SfmlSprite>();
            }

            /**
             * @brief Create a Text object
             * 
             * @return std::shared_ptr<arcade::interface::ITextModule> 
             */
            std::shared_ptr<arcade::interface::ITextModule> createText() override
            {
                return std::make_shared<arcade::SfmlText>();
            }

            /**
             * @brief Create a Audio object
             * 
             * @return std::shared_ptr<arcade::interface::IAudioModule> 
             */
            std::shared_ptr<arcade::interface::IAudioModule> createAudio() override
            {
                return std::make_shared<arcade::SfmlAudio>();
            }
            
            /**
             * @brief Fetch the inputs from the window
             * 
             */
            void fetchInputs() override
            {
                sf::Event event;

                while (window->pollEvent(event))
                    if (event.type == sf::Event::Closed)
                        this->window->close();

                // Mouse Input        
                pressedKeys[arcade::interface::KeyCode::MouseButton1] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
                pressedKeys[arcade::interface::KeyCode::MouseButton2] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
                pressedKeys[arcade::interface::KeyCode::MouseButton3] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
                
                // keyboard inputs
                for (int i = 0; i < arcade::interface::KeyCount; ++i)
                    pressedKeys[(arcade::interface::KeyCode)i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
                
                //(bind with smfl sf::Key for keyboard and sf::Button for mouse)
                //TODO: need to see if binding is the same for sdl and others
            }

            /**
             * @brief Check if a key is pressed
             * 
             * @param key is the key to check
             * @return true if the key is pressed
             * @return false if the key is not pressed
             */
            bool isKeyPressed(arcade::interface::KeyCode key) override
            {
                return pressedKeys[key];
            }

            /**
             * @brief Get the Mouse X Position object
             * 
             * @return unsigned int position of the mouse on the x axis
             */
            unsigned int getMouseXPosition() const override 
            {
                return sf::Mouse::getPosition().x;
            }

            /**
             * @brief Get the Mouse Y Position object
             * 
             * @return unsigned int position of the mouse on the y axis
             */
            unsigned int getMouseYPosition() const override 
            {
                return sf::Mouse::getPosition().y;
            }

            /**
             * @brief Set the Fps object
             * 
             * @param fps is the number of frame per second
             */
            void setFps(int fps) override
            {
                window->setFramerateLimit(fps);
            }
            
            /**
             * @brief Draw a sprite on the screen
             * 
             * @param spriteModule is the sprite to draw
             */
            void draw(std::shared_ptr<arcade::interface::ISpriteModule> spriteModule) override
            {
                sf::Sprite *temp((sf::Sprite *)spriteModule->getSprite());
                window->draw(*temp);
            }

            /**
             * @brief Draw a text on the screen
             * 
             * @param textModule is the text to draw
             */
            void draw(std::shared_ptr<arcade::interface::ITextModule> textModule) override
            {
                sf::Text *temp((sf::Text *)textModule->getText());
                window->draw(*temp);
            }
    };  
}
#endif /* !SFMLDISPLAY_HPP_ */
