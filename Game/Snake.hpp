/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** snake
*/

#include "../Module Interface/IGameModule.hpp"
#include "../Module Interface/IDisplayModule.hpp"
#include "../Module Interface/UserModule.hpp"
#include <iostream>
#include <vector>

class Snake : public arcade::interface::IGameModule
{
    public:
        Snake()
        {
            // initialize snake and apple positions
            this->snake = {{10, 10}, {9, 10}, {8, 10}};
            this->apple = {20, 20};
            this->direction = 'R';
            this->gameOver = false;
            this->score = 0;
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
            this->handleInput(display);
            this->placeApple();
            this->moveSnake();
            this->checkCollisions(display);
            this->drawSnake(display);
            this->drawApple(display);
            this->drawScore(display);
            display->fetchInputs();
            display->displayWindow();
            if (this->gameOver) {
                std::cout << "Game over! Score: " << this->score << std::endl;
                return 69;
            }
            return 0;
        }

        std::string getName() const override
        {
            return "Snake";
        }

        private:

            void handleInput (std::shared_ptr<arcade::interface::IDisplayModule> display)
            {
                if (display->isKeyPressed(arcade::interface::KeyCode::Up) && this->direction != 'D')
                    this->direction = 'U';
                else if (display->isKeyPressed(arcade::interface::KeyCode::Down) && this->direction != 'U')
                    this->direction = 'D';
                else if (display->isKeyPressed(arcade::interface::KeyCode::Left) && this->direction != 'R')
                    this->direction = 'L';
                else if (display->isKeyPressed(arcade::interface::KeyCode::Right) && this->direction != 'L')
                    this->direction = 'R';
            }

            void moveSnake ()
            {
                for (int i = this->snake.size() - 1; i > 0; --i)
                    this->snake[i] = this->snake[i - 1];
                if (this->direction == 'U')
                    this->snake[0].second -= 1;
                else if (this->direction == 'D')
                    this->snake[0].second += 1;
                else if (this->direction == 'L')
                    this->snake[0].first -= 1;
                else if (this->direction == 'R')
                    this->snake[0].first += 1;
            }

            void checkCollisions (std::shared_ptr<arcade::interface::IDisplayModule> display)
            {
                // check if snake has hit the wall
                if (this->snake[0].first < 0 || this->snake[0].first >= display->getWindowWidth() || this->snake[0].second < 0 || this->snake[0].second >= display->getWindowHeight())
                    this->gameOver = true;
                // check if snake has hit itself
                for (int i = 1; i < this->snake.size(); ++i)
                    if (this->snake[0] == this->snake[i])
                        this->gameOver = true;
                // check if snake has eaten an apple
                if (this->snake[0] == this->apple) {
                    this->score += 10;
                    this->snake.push_back({-1, -1});
                    this->placeApple();
                }
            }

            void drawSnake (std::shared_ptr<arcade::interface::IDisplayModule> display)
            {
                std::shared_ptr<arcade::interface::ISpriteModule> snake_unit = display->createSprite();
                std::shared_ptr<arcade::interface::ISpriteModule> snake_head = display->createSprite();
                /*
                    snake_unit->setSprite(path_unit)
                    snake_head->setSprite(path_head)
                */
                bool first_time = true;

                for (auto const &pos : this->snake) {
                    if (first_time) {
                        snake_head->setColor(arcade::GREEN);
                        snake_head->setPosition(pos.first, pos.second);
                        display->draw(snake_head);
                        first_time = false;
                    } else {
                        snake_unit->setPosition(pos.first, pos.second);
                        snake_unit->setColor(arcade::GREEN);
                        display->draw(snake_unit);
                    }
                }
            }

            void drawApple (std::shared_ptr<arcade::interface::IDisplayModule> display)
            {
                std::shared_ptr<arcade::interface::ISpriteModule> apple = display->createSprite();
                /*
                    apple->setSprite(path_apple)
                */

                bool first_time = true;

                if (first_time) {
                    apple->setColor(arcade::RED);
                    apple->setPosition(this->apple.first, this->apple.second);
                    apple->placeApple();
                    display->draw(apple);
                    first_time = false;
                } else {
                    apple->setPosition(this->apple.first, this->apple.second);
                    apple->setColor(arcade::RED);
                    apple->placeApple();
                    display->draw(apple);
                }
            }

            void drawScore (std::shared_ptr<arcade::interface::IDisplayModule> display)
            {
                display->draw(2, 0, "Score: " + std::to_string(this->score), arcade::interface::Color::White);
            }

            void placeApple ()
            {
                int x = rand() % 40;
                int y = rand() % 40;
                this->apple = {x, y};
            }

        private:
            std::vector<std::pair<int, int>> snake;
            std::pair<int, int> apple;
            char direction;
            bool gameOver;
            int score;

        //sauvegarde de la position lorsque on change de jeu
};

