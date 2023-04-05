/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IAudioModule
*/

#ifndef IAUDIOMODULE_HPP_
    #define IAUDIOMODULE_HPP_
    #include <string>

namespace arcade {

        namespace interface {

            class IAudioModule {
                public:
                    /**
                     * @brief Destroy the IAudioModule object
                     * 
                     */
                    virtual ~IAudioModule() = default;
        
                    /**
                     * @brief Set the Source object
                     * 
                     * @attention all file types must be at the path specified
                     * @param source_path is the path to the source
                     */
                    virtual void setSource(const std::string &source_path) = 0;
        
                    /**
                     * @brief Play the audio source
                     * 
                     */
                    virtual void play() = 0;
        
                    /**
                     * @brief Pause the audio source
                     * 
                     */
                    virtual void pause() = 0;
        
                    /**
                     * @brief Stop the audio source
                     * 
                     */
                    virtual void stop() = 0;
        
                    /**
                     * @brief Set the Volume object
                     * 
                     * @param volume is the volume to set
                     */
                    virtual void setVolume(float volume) = 0;
        
            };
    }
}

#endif /* !IAUDIOMODULE_HPP_ */
