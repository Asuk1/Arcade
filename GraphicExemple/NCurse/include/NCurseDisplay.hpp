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
#include "../../../Module Interface/Color.hpp"
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
                window = std::make_shared<WINDOW>(newwin(LINES, COLS, 10, 10));
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
            
            void displayWindow() 
            {
                for (int i = 0; i < LINES; i++)
                    for (int j = 0; j < COLS; j++)
                        mvwprintw(window.get(), i, j, "%c", map[i][j]);
            }

            void closeWindow() 
            {
                endwin();
            }
        
            void setResolution(unsigned int x, unsigned int y) 
            {
                window = std::make_shared<WINDOW>(newwin(y, x, 10, 10));
            }

            void setWindowTitle(const std::string &title) 
            {
                wprintw(window.get(), title.c_str());
            }
            
            unsigned int getWindowWidth() const
            {
                return COLS;
            }

            unsigned int getWindowHeight() const
            {
                return LINES;
            }

            void clearWindow()
            {
                clear();
            }
            
            void refreshWindow()
            {
                wrefresh(window.get());
            }

            void draw(std::shared_ptr<arcade::interface::ISpriteModule> sprite)
            {
                NcurseSprite *spritePtr = dynamic_cast<NcurseSprite *>(sprite.get());
                if (spritePtr == nullptr)
                    return;
                attron(COLOR_PAIR(spritePtr->color));
                mvwprintw(window.get(), spritePtr->pos.second, spritePtr->pos.first, "%c", spritePtr->sprite);
                attroff(COLOR_PAIR(spritePtr->color));
            }

            void draw(std::shared_ptr<arcade::interface::ITextModule> text)
            {
                NcurseText *textPtr = dynamic_cast<NcurseText *>(text.get());
                if (textPtr == nullptr)
                    return;
                attron(COLOR_PAIR(textPtr->color));
                mvwprintw(window.get(), textPtr->pos.second, textPtr->pos.first, "%s", textPtr->text.c_str());
                attroff(COLOR_PAIR(textPtr->color));
            }

            void fetchInputs()
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

            bool isKeyPressed(arcade::interface::KeyCode key) 
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

            unsigned int getMouseXPosition() const 
            {
                return 0;
            }

            unsigned int getMouseYPosition() const 
            {
                return 0;
            }


            void setFps(int fps) 
            {
                timeout(1000 / fps);
            }

            void setFullScreen(bool fullscreen) 
            {
                // Ignored in ncurses
            }

            bool isOpen() const 
            {
                return true;
            }

            bool isTextMode() const 
            {
                return false;
            }

            std::shared_ptr<arcade::interface::ISpriteModule> createSprite() 
            {
                return std::make_shared<NcurseSprite>();
            }

            std::shared_ptr<arcade::interface::ITextModule> createText() 
            {
                return std::make_shared<NcurseText>();
            }

            std::shared_ptr<arcade::interface::IAudioModule> createAudio() 
            {
                throw std::exception();
            }

    };
}
