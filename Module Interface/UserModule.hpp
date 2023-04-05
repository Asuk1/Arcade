/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** User_data
*/

#ifndef USER_DATA_HPP_
    #define USER_DATA_HPP_
    #include <string>

namespace arcade
{
    class User_data
    {
        public:
            User_data()
            {
                this->_name = "Guest";
                this->_score = 0;
            }
            ~User_data() = default;

            /**
             * @brief Set the Name object
             * 
             * @param name is the name to set
             */
            void setName(const std::string &name)
            {
                this->_name = name;
            }

            /**
             * @brief Get the Name object
             * 
             * @return const std::string& is the name
             */
            const std::string &getName() const
            {
                return this->_name;
            }

            /**
             * @brief Set the Score object to Zero
             * 
             */
            void setScoreToZero()
            {
                this->_score = 0;
            }

            /**
             * @brief Set the Score object
             * 
             * @param score is the score to set
             */
            void addScore(std::size_t score)
            {
                this->_score += score;
            }

            /**
             * @brief Get the Score object
             * 
             * @return std::size_t is the score
             */
            std::size_t getScore() const
            {
                return this->_score;
            }

        protected:
        private:
            std::string _name;
            std::size_t _score;
    };
}

#endif /* !USER_DATA_HPP_ */
