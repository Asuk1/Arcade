/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Game1
*/

#include "../Module Interface/IGameModule.hpp"
#include "../Module Interface/IDisplayModule.hpp"
#include "../Module Interface/UserModule.hpp"
#include <iostream>



class Game1 : public arcade::interface::IGameModule
{
    public:
        Game1()
        {
            this->_pos_player.first = 100;
            this->_pos_player.second = 100;
            this->_pos_title.first = 100;
            this->_pos_title.second = 10;
        }

        size_t update(
            std::shared_ptr<arcade::interface::IDisplayModule> display,
            arcade::User_data &user,
            std::vector<std::string> &_gameLibs,
            std::vector<std::string> &_graphLibs, 
            std::vector<std::string> &_menuLibs,
            size_t &_pathToGraphLib,
            size_t &_pathtoGameLib,
            size_t &_pathToMenuLib) 
        {
            display->clearWindow();
            if (display->isKeyPressed(arcade::interface::KeyCode::Q))
                this->_pos_player.first -= 1;
            if (display->isKeyPressed(arcade::interface::KeyCode::S))
                this->_pos_player.second += 1;
            if (display->isKeyPressed(arcade::interface::KeyCode::Z))
                this->_pos_player.second -= 1;
            if (display->isKeyPressed(arcade::interface::KeyCode::D))
                this->_pos_player.first += 1;
            
            // INPUT FOR MANAGEMENT OF LIBS
            if (display->isKeyPressed(arcade::interface::KeyCode::Escape))
                return 69;
            if (display->isKeyPressed(arcade::interface::KeyCode::Up))
                return 1;
            if (display->isKeyPressed(arcade::interface::KeyCode::Down))
                return -1;
            if (display->isKeyPressed(arcade::interface::KeyCode::Left))
                return 2;
            if (display->isKeyPressed(arcade::interface::KeyCode::Right))
                return -2;
            // 

            title->setColor(255, 255, 255);
            title->setFontSize(50);
            player->setPosition(this->_pos_player.first, this->_pos_player.second);
            title->setPosition(this->_pos_title.first, this->_pos_title.second);
            display->draw(player);
            display->draw(title);
            display->fetchInputs();            
            display->displayWindow();
            return 0;
        }
        
        std::string getName() const
        {
            return "Game 1";
        }

    private:
        bool Initialisation(std::shared_ptr<arcade::interface::IDisplayModule> display)
        {
            display.get()->fetchInputs();
            player = display.get()->createSprite();
            player->setSprite("assets/test");

            title = display.get()->createText();
            title->setText("Game 1");
            return true;
        }
        
        
    private: 
        std::shared_ptr<arcade::interface::ISpriteModule> player;
        std::shared_ptr<arcade::interface::ITextModule> title;

    private:
        std::pair<float, float> _pos_player;
        std::pair<float, float> _pos_title;

};
