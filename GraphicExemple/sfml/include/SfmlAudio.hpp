/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlAudio
*/

#pragma once


#include "../../../Module Interface/IAudioModule.hpp"
#include <SFML/Audio/Music.hpp>
#include <memory>

namespace arcade
{
    class SfmlAudio : public arcade::interface::IAudioModule
    {
        public:
            std::shared_ptr<sf::Music> sound;
            
            SfmlAudio()
            {
                sound = std::make_shared<sf::Music>();
            }

            ~SfmlAudio() = default; 

            void setSource(const std::string &source_path)
            {
                this->sound->openFromFile(source_path);
            }
            
            void play()
            {
                sound->play();
            }

            void pause()
            {
                sound->pause();
            }

            void stop()
            {
                sound->stop();
            }

            void setVolume(float volume)
            {
                this->sound->setVolume(volume);
            }
    };  
}

