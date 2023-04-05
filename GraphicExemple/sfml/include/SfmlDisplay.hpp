/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlDisplay
*/

#pragma once

#include <map>

#include "../../../Module Interface/IDisplayModule.hpp"
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
            //PROPERTIES:
            std::shared_ptr<sf::RenderWindow> window;
            std::map<arcade::interface::KeyCode, bool> pressedKeys;
        
            void closeWindow() override
            {
                window->close();
            }

            SfmlDisplay()
            {
                window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, (1080)), "Arcade Sfml");
            }
        
            void setResolution(unsigned int x, unsigned int y) override
            {
                window->setSize((sf::Vector2u){x, y});
            }

            void setWindowTitle(std::string title) override
            {
                window->setTitle(title);
            }
            
            unsigned int getWindowWidth() const
            {
                return window->getSize().x;
            }
            
            unsigned int getWindowHeight() const
            {
                return window->getSize().y;
            }

            bool isOpen() override
            {
                return window->isOpen();
            }
            void clearWindow() override
            {
                window->clear(sf::Color::Black);
            }
            
            void displayWindow() override
            {
                window->display();
            }
            // Window type:
            /*LibType getType()
            {
                return SFML;
            }*/
            bool isTextMode() override
            {
                return false;
            }
            
            unsigned int getWindowWidth() override
            {
                return window->getSize().x;
            }
        
            unsigned int getWindowHeight() override
            {
                return window->getSize().y;
            }

            void setFullScreen(bool state) override
            {
                window->create(sf::VideoMode(1920, 1080), "Arcade Sfml", sf::Style::Fullscreen);
            }

            std::shared_ptr<arcade::interface::ISpriteModule> createSprite() override
            {
                return std::make_shared<arcade::SfmlSprite>();
            }

            std::shared_ptr<arcade::interface::ITextModule> createText() override
            {
                return std::make_shared<arcade::SfmlText>();
            }

            std::shared_ptr<arcade::interface::IAudioModule> createAudio() override
            {
                return std::make_shared<arcade::SfmlAudio>();
            }


            //INPUT:
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
            bool isKeyPressed(arcade::interface::KeyCode key) override
            {
                return pressedKeys[key];
            }

            unsigned int getMouseXPosition() const override 
            {
                return sf::Mouse::getPosition().x;
            }

            unsigned int getMouseYPosition() const override 
            {
                return sf::Mouse::getPosition().y;
            }
            void setFps(int fps) override
            {
                window->setFramerateLimit(fps);
            }
            //////////////////////////////////////////
            // DRAW LOGIC:
            void draw(std::shared_ptr<arcade::interface::ISpriteModule> spriteModule) override
            {
                sf::Sprite *temp((sf::Sprite *)spriteModule->getSprite());
                window->draw(*temp);
            }

            void draw(std::shared_ptr<arcade::interface::ITextModule> textModule) override
            {
                window->draw(*(sf::Text *)textModule->getText());
            }
    };  
}