/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** sdl2Audio
*/

#include "../include/sdl2Audio.hpp"

arcade::sdl2Audio::sdl2Audio() : sound(nullptr)
{
}

arcade::sdl2Audio::~sdl2Audio()
{
    // Clean up resources
    Mix_FreeMusic(sound);
    Mix_CloseAudio();
}

void arcade::sdl2Audio::setSource(const std::string &source_path)
{
    // Load the audio file
    if ((sound = Mix_LoadMUS(source_path.c_str())) == NULL)
    {
        // Handle error
        std::cout << "ERROR setSource: " << Mix_GetError() << std::endl;
        return;
    }
}

void arcade::sdl2Audio::open()
{
    // Initialize SDL2 and SDL2_mixer
    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);

    // Set up the audio device
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        // Handle error
        std::cout << "ERROR sdl_open" << std::endl;
        return;
    }
}

void arcade::sdl2Audio::play()
{
    // Play the audio file
    if (Mix_PlayMusic(sound, -1) == -1)
    {
        // Handle error
        std::cout << "ERROR sdlPlay" << std::endl;
        return;
    }
}

void arcade::sdl2Audio::pause()
{
    Mix_PauseMusic();
}

void arcade::sdl2Audio::stop()
{
    Mix_HaltMusic();
}

void arcade::sdl2Audio::setVolume(float volume)
{
    Mix_VolumeMusic(static_cast<int>(volume * MIX_MAX_VOLUME));
}