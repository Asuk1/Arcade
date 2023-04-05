/*
** EPITECH PROJECT, 2022
** NCurse
** File description:
** NCurseText
*/

#pragma once

#include <ncurses.h>
#include <map>
#include "../../../Module Interface/IDisplayModule.hpp"
#include "NCurseSprite.hpp"
#include "NCurseText.hpp"
#include <memory>

namespace arcade
{
    class NcurseDisplay : public arcade::interface::IDisplayModule
    {
        public:
            std::shared_ptr<WINDOW> window;
            char **map;
            std::map<arcade::interface::KeyCode, bool> pressedKeys;

            NcurseDisplay()
            {
                window = std::make_shared<WINDOW>(newwin(LINES, COLS, 0, 0));
                noecho();
                curs_set(0);
                keypad(stdscr, TRUE);
                nodelay(stdscr, TRUE);
                start_color();
                init_pair(1, COLOR_RED, COLOR_BLACK);
                init_pair(2, COLOR_GREEN, COLOR_BLACK);
                init_pair(3, COLOR_YELLOW, COLOR_BLACK);
                init_pair(4, COLOR_BLUE, COLOR_BLACK);
                init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
                init_pair(6, COLOR_CYAN, COLOR_BLACK);
                init_pair(7, COLOR_WHITE, COLOR_BLACK);
            }
            
            void displayWindow() override
            {
                for (int i = 0; i < LINES; i++)
                    for (int j = 0; j < COLS; j++)
                        mvwprintw(window.get(), i, j, "%c", map[i][j]);
            }

            void closeWindow() override
            {
                endwin();
            }
        
            void setResolution(unsigned int x, unsigned int y) override
            {
                window = std::make_shared<WINDOW>(newwin(y, x, 0, 0));
            }

            void setWindowTitle(std::string title)  override
            {
                // Ignored in ncurses
            }
            
            unsigned int getWindowWidth() override
            {
                return COLS;
            }
            
            unsigned int getWindowHeight() override
            {
                return LINES;
            }
            
            void clearWindow()  override
            {
                clear();
            }
            
            void refreshWindow()
            {
                wrefresh(window.get());
            }

            void draw(std::shared_ptr<arcade::interface::ISpriteModule> sprite) override
            {
                NcurseSprite *spritePtr = dynamic_cast<NcurseSprite *>(sprite.get());
                if (spritePtr == nullptr)
                    return;
                attron(COLOR_PAIR(spritePtr->color));
                mvwprintw(window.get(), spritePtr->pos.second, spritePtr->pos.first, "%c", spritePtr->sprite);
                attroff(COLOR_PAIR(spritePtr->color));
            }

            void draw(std::shared_ptr<arcade::interface::ITextModule> text) override
            {
                NcurseText *textPtr = dynamic_cast<NcurseText *>(text.get());
                if (textPtr == nullptr)
                    return;
                attron(COLOR_PAIR(textPtr->color));
                mvwprintw(window.get(), textPtr->pos.second, textPtr->pos.first, "%s", textPtr->text.c_str());
                attroff(COLOR_PAIR(textPtr->color));
            }

            void fetchInputs() override
            {
                int ch = getch();
                switch (ch) {
                    case KEY_UP:
                        pressedKeys[arcade::interface::KeyCode::Up] = true;
                        break;
                    case KEY_DOWN:
                        pressedKeys[arcade::interface::KeyCode::Down] = true;
                        break;
                    case KEY_LEFT:
                        pressedKeys[arcade::interface::KeyCode::Left] = true;
                        break;
                    case KEY_RIGHT:
                        pressedKeys[arcade::interface::KeyCode::Right] = true;
                        break;
                    case 10:
                        pressedKeys[arcade::interface::KeyCode::Enter] = true;
                        break;
                    case 27:
                        pressedKeys[arcade::interface::KeyCode::Escape] = true;
                        break;
                }
            }

            bool isKeyPressed(arcade::interface::KeyCode key) override
            {
                int ch = getch();
                switch (key) {
                    case arcade::interface::KeyCode::Up:
                        return ch == KEY_UP;
                    case arcade::interface::KeyCode::Down:
                        return ch == KEY_DOWN;
                    case arcade::interface::KeyCode::Left:
                        return ch == KEY_LEFT;
                    case arcade::interface::KeyCode::Right:
                        return ch == KEY_RIGHT;
                    case arcade::interface::KeyCode::Enter:
                        return ch == 10;
                    case arcade::interface::KeyCode::Escape:
                        return ch == 27;
                    default:
                        return false;
                }
            }

            unsigned int getMouseXPosition() const override
            {
                return 0;
            }

            unsigned int getMouseYPosition() const override
            {
                return 0;
            }


            void setFps(int fps) override
            {
                timeout(1000 / fps);
            }

            void setFullScreen(bool fullscreen) override
            {
                // Ignored in ncurses
            }

            bool isOpen() override
            {
                return true;
            }

            bool isTextMode() override
            {
                return false;
            }

            std::shared_ptr<arcade::interface::ISpriteModule> createSprite() override
            {
                return std::make_shared<NcurseSprite>();
            }

            std::shared_ptr<arcade::interface::ITextModule> createText() override
            {
                return std::make_shared<NcurseText>();
            }

            std::shared_ptr<arcade::interface::IAudioModule> createAudio() override
            {
                throw std::exception();
            }

    };
}
