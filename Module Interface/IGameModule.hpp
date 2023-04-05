/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
    #define IGAMEMODULE_HPP_
    #include <string>
    #include <vector>
    #include <memory>
    #include "IDisplayModule.hpp"
    #include "UserModule.hpp"
    #include <exception>


namespace arcade {
    namespace interface {

    class GameException : public std::exception {
        public:
            /**
             * @brief Construct a new Game Exception object
             * 
             * @param message is the message to display
             */
            GameException(const std::string &message) : _message(message) {;}

            /**
             * @brief Destroy the Game Exception object
             * 
             */
            ~GameException() = default;

            /**
             * @brief Get the Message object
             * 
             * @return const char* is the message
             */
            const char *what() const noexcept override {return this->_message.c_str();};
        protected:
        private:
            std::string _message;
    };

    class IGameModule {
        public:

            /**
             * @brief Destroy the IGameModule object
             * 
             */
            IGameModule() = default;

            /**
             * @brief Destroy the IGameModule object
             * 
             */
            virtual ~IGameModule() {;};

            /**
             * @brief Get the Name object
             * 
             * @param display is the display module
             * @param user is the user module, i store the name and the score
             * @param _gameLibs is the vector of game libs
             * @param _graphLibs is the vector of graph libs
             * @param _menuLibs is the vector of menu libs
             * @param _pathToGraphLib is the index to the graph lib
             * @param _pathtoGameLib is the index to the game lib
             * @param _pathToMenuLib is the index to the menu lib
             * 
             * @return 0 if the game is not over
             * @return 1 to go to the next game
             * @return -1 to go to the previous game
             * @return 2 to go to the next graph lib
             * @return -2 to go to the previous graph lib
             * @return 3 to go to the next menu lib
             * @return -3 to go to the previous menu lib
             * @return 69 to quit the game and go to the menu
             */
            virtual size_t update(std::shared_ptr<arcade::interface::IDisplayModule> display, arcade::User_data &user,
            std::vector<std::string> &_gameLibs, 
            std::vector<std::string> &_graphLibs, 
            std::vector<std::string> &_menuLibs, 
            size_t &_pathToGraphLib, 
            size_t &_pathtoGameLib, 
            size_t &_pathToMenuLib) = 0;

            /**
             * @brief Get the Name object
             * 
             * @return const std::string& is the name of the game
             */
            virtual std::string getName() const = 0;

            /**
             * @brief initialisation of the game
             * 
             * @param display is the display module
             * @return true if the initialisation is a success
             * @return false if the initialisation is a failure
             */
            virtual bool Initialisation(std::shared_ptr<arcade::interface::IDisplayModule> display) = 0;
    };
    }
}

#endif /* !IGAMEMODULE_HPP_ */
