/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** CLock
*/

#ifndef MALEK_ENGINE_CLOCK_HPP
    #define MALEK_ENGINE_CLOCK_HPP
    #include <chrono>
    
namespace arcade
{
    namespace tools
    {
        class Clock {
            public:
                /**
                 * @brief Construct a new Clock object
                 * 
                 */
                Clock() {
                    restart();
                }

                /**
                 * @brief Destroy the Clock object
                 * 
                 */
                ~Clock() = default;

                /**
                 * @brief Restart the clock
                 * 
                 */
                void restart() {
                    start_time_ = std::chrono::high_resolution_clock::now();
                    paused_ = false;
                    paused_duration_ = std::chrono::duration<double>(0);
                }

                /**
                 * @brief Pause the clock
                 * 
                 */
                void pause() {
                    if (!paused_) {
                        paused_ = true;
                        pause_start_time_ = std::chrono::high_resolution_clock::now();
                    }
                }

                /**
                 * @brief Resume the clock
                 * 
                 */
                void resume() {
                    if (paused_) {
                        paused_ = false;
                        std::chrono::duration<double> pause_duration = std::chrono::high_resolution_clock::now() - pause_start_time_;
                        paused_duration_ += pause_duration;
                    }
                }

                /**
                 * @brief Get the elapsed time
                 * 
                 * @return double return the elapsed time in seconds
                 */
                double elapsed_time() const {
                    if (paused_) {
                        return std::chrono::duration_cast<std::chrono::duration<double>>(pause_start_time_ - start_time_).count() - paused_duration_.count();
                    } else {
                        return std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time_).count() - paused_duration_.count();
                    }
                }

            private:
                std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
                std::chrono::time_point<std::chrono::high_resolution_clock> pause_start_time_;
                std::chrono::duration<double> paused_duration_;
                bool paused_;
        };
    }

}

#endif //MALEK_ENGINE_CLOCK_HPP
