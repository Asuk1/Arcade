/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlDisplay
*/

#include "../include/SfmlDisplay.hpp"

void arcade::SfmlDisplay::closeWindow()
{
    window->close();
}

arcade::SfmlDisplay::SfmlDisplay()
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, (1080)), "Arcade Sfml");
}

void arcade::SfmlDisplay::setResolution(unsigned int x, unsigned int y)
{
    window->setSize((sf::Vector2u){x, y});
}

void arcade::SfmlDisplay::setWindowTitle(const std::string &title)
{
    window->setTitle(title);
}

bool arcade::SfmlDisplay::isOpen() const
{
    return window->isOpen();
}

void arcade::SfmlDisplay::clearWindow()
{
    window->clear(sf::Color::Black);
}

void arcade::SfmlDisplay::displayWindow()
{
    window->display();
}

bool arcade::SfmlDisplay::isTextMode() const
{
    return false;
}

unsigned int arcade::SfmlDisplay::getWindowWidth() const
{
    return window->getSize().x;
}

unsigned int arcade::SfmlDisplay::getWindowHeight() const
{
    return window->getSize().y;
}

void arcade::SfmlDisplay::setFullScreen(bool state)
{
    (void)state;
    window->create(sf::VideoMode(1920, 1080), "Arcade Sfml", sf::Style::Fullscreen);
}

std::shared_ptr<arcade::interface::ISpriteModule> arcade::SfmlDisplay::createSprite()
{
    return std::make_shared<arcade::SfmlSprite>();
}

std::shared_ptr<arcade::interface::ITextModule> arcade::SfmlDisplay::createText()
{
    return std::make_shared<arcade::SfmlText>();
}

std::shared_ptr<arcade::interface::IAudioModule> arcade::SfmlDisplay::createAudio()
{
    return std::make_shared<arcade::SfmlAudio>();
}

void arcade::SfmlDisplay::fetchInputs()
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

bool arcade::SfmlDisplay::isKeyPressed(arcade::interface::KeyCode key)
{
    return pressedKeys[key];
}

unsigned int arcade::SfmlDisplay::getMouseXPosition() const 
{
    return sf::Mouse::getPosition().x;
}

unsigned int arcade::SfmlDisplay::getMouseYPosition() const 
{
    return sf::Mouse::getPosition().y;
}

void arcade::SfmlDisplay::setFps(int fps)
{
    window->setFramerateLimit(fps);
}
            
void arcade::SfmlDisplay::draw(std::shared_ptr<arcade::interface::ISpriteModule> spriteModule)
{
    sf::Sprite *temp((sf::Sprite *)spriteModule->getSprite());
    window->draw(*temp);
}

void arcade::SfmlDisplay::draw(std::shared_ptr<arcade::interface::ITextModule> textModule)
{
    sf::Text *temp((sf::Text *)textModule->getText());
    window->draw(*temp);
}