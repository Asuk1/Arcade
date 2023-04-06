/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml.Audio
*/

#include "../include/SfmlAudio.hpp"

arcade::SfmlAudio::SfmlAudio()
{
    sound = std::make_shared<sf::Music>();
}

void arcade::SfmlAudio::setSource(const std::string &source_path)
{
    this->sound->openFromFile(source_path);
}
            
void arcade::SfmlAudio::play()
{
    sound->play();
}

void arcade::SfmlAudio::pause()
{
    sound->pause();
}

void arcade::SfmlAudio::stop()
{
    sound->stop();
}

void arcade::SfmlAudio::setVolume(float volume)
{
    this->sound->setVolume(volume);
}