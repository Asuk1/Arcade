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

            bool operator==(const Color &other) const
            {
                return (r == other.r && g == other.g && b == other.b && a == other.a);
            }
    };

    const Color RED = Color(255, 0, 0, 255);
    const Color GREEN = Color(0, 255, 0, 255);
    const Color BLUE = Color(0, 0, 255, 255);
    const Color WHITE = Color(255, 255, 255, 255);
    const Color BLACK = Color(0, 0, 0, 255);
    const Color YELLOW = Color(255, 255, 0, 255);
    const Color MAGENTA = Color(255, 0, 255, 255);
    const Color CYAN = Color(0, 255, 255, 255);
}

#endif /* !COLOR_HPP_ */
