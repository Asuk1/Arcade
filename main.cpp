/*
** EPITECH PROJECT, 2023
** Arcade-Interfaces
** File description:
** main
*/

#include "core/include/Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    else {
        try {
            code::Core core(av[1]);
        } catch (const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return 84;
        }
    }
    return 0;
}