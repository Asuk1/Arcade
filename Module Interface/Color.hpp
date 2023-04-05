/*
** EPITECH PROJECT, 2023
** Arcade-Interface
** File description:
** Color
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_

namespace arcade
{
    class Color {
        public:
            Color() {r = 0;g = 0;b = 0;a = 255;}
            Color(int r, int g, int b, int a) {this->r = r;this->g = g;this->b = b;this->a = a;}
            ~Color() = default;
            int r;
            int g;
            int b;
            int a;
    };

    const Color RED = Color(255, 0, 0, 255);
    const Color GREEN = Color(0, 255, 0, 255);
    const Color BLUE = Color(0, 0, 255, 255);
    const Color WHITE = Color(255, 255, 255, 255);
    const Color BLACK = Color(0, 0, 0, 255);
    const Color YELLOW = Color(255, 255, 0, 255);
    const Color PURPLE = Color(255, 0, 255, 255);
    const Color CYAN = Color(0, 255, 255, 255);
    const Color ORANGE = Color(255, 165, 0, 255);
    const Color PINK = Color(255, 192, 203, 255);
    const Color BROWN = Color(165, 42, 42, 255);
    const Color GRAY = Color(128, 128, 128, 255);
    const Color TRANSPARENT = Color(0, 0, 0, 0);
}

#endif /* !COLOR_HPP_ */
