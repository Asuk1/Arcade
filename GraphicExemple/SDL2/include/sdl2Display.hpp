/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** sdl2Display
*/

#pragma once

#ifndef SDL2DISPLAY_HPP_
#define SDL2DISPLAY_HPP_

#include "../../../Module Interface/IDisplayModule.hpp"
#include "sdl2Sprite.hpp"
#include "sdl2Text.hpp"
#include "sdl2Audio.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <map>
#include <memory>

namespace arcade
{
    class sdl2Display : public arcade::interface::IDisplayModule
    {
        public:
            //PROPERTIES:
            std::map<arcade::interface::KeyCode, bool> pressedKeys;
            SDL_Window *window;
            SDL_Renderer *rend;

            sdl2Display();
            ~sdl2Display();
        
            void closeWindow() override;
            void setResolution(unsigned int x, unsigned int y) override;
            void setWindowTitle(const std::string &title) override;
            unsigned int getWindowWidth() const;
            unsigned int getWindowHeight() const;
            bool isOpen();
            void clearWindow() override;
            void displayWindow() override;
            bool isTextMode() const override;
            void setFullscreen(bool fullscreen);
            std::shared_ptr<arcade::interface::ISpriteModule> createSprite() override;
            std::shared_ptr<arcade::interface::ITextModule> createText() override;
            std::shared_ptr<arcade::interface::IAudioModule> createAudio() override;

            //INPUT:
            void fetchInputs() override;
            bool isKeyPressed(arcade::interface::KeyCode key) override;
            unsigned int getMouseXPosition() const override;
            unsigned int getMouseYPosition() const override;
            void setFps(int fps) override;

            ////////////////////////////////////

            // DRAW LOGIC:
            void draw(std::shared_ptr<arcade::interface::ISpriteModule> spriteModule) override;
            void draw(std::shared_ptr<arcade::interface::ITextModule> textModule) override;
    };
}

#endif /* !SDL2DISPLAY_HPP_ */
