/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** sdl2Audio
*/

#ifndef SDL2AUDIO_HPP_
    #define SDL2AUDIO_HPP_

#include "../../../Module Interface/IAudioModule.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <memory>

namespace arcade 
{
    class sdl2Audio : public arcade::interface::IAudioModule
    {
        //init some shared_ptr
        Mix_Music *sound;

        public:
            sdl2Audio();
            ~sdl2Audio();
            void setSource(const std::string &source_path);
            void open();
            void play();
            void pause();
            void stop();
            void setVolume(float volume);
    };
}

#endif /* !SDL2AUDIO_HPP_ */
