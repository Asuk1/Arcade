/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SfmlAudio
*/

#ifndef SFMLAUDIO_HPP_
    #define SFMLAUDIO_HPP_
    #include "IAudioModule.hpp"
    #include <SFML/Audio/Music.hpp>
    #include <memory>

namespace arcade
{
    class SfmlAudio : public arcade::interface::IAudioModule
    {
        public:
            /**
             * @brief Construct a new Sfml Audio object 
             * 
             */
            SfmlAudio()
            {
                sound = std::make_shared<sf::Music>();
            }

            /**
             * @brief Destroy the Sfml Audio object
             * 
             */
            ~SfmlAudio() = default; 

            /**
             * @brief Set the Source object
             * 
             * @param source_path is the path to the music 
             */
            void setSource(const std::string &source_path)
            {
                this->sound->openFromFile(source_path);
            }
            
            /**
             * @brief Play the music
             * 
             */
            void play()
            {
                sound->play();
            }

            /**
             * @brief Pause the music
             * 
             */
            void pause()
            {
                sound->pause();
            }

            /**
             * @brief Stop the music
             * 
             */
            void stop()
            {
                sound->stop();
            }

            /**
             * @brief Set the Volume object
             * 
             * @param volume is the volume to set
             */
            void setVolume(float volume)
            {
                this->sound->setVolume(volume);
            }

        private:
            std::shared_ptr<sf::Music> sound;
            
    };  
}



#endif /* !SFMLAUDIO_HPP_ */
