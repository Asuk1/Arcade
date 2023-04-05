/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_
    #include <string>
    #include "ISpriteModule.hpp"
    #include "ITextModule.hpp"
    #include "IAudioModule.hpp"
    #include <memory>

namespace arcade
{
    namespace interface
    {

        /**
         * @brief The Enum KeyCode is used to represent the key pressed
         * 
         */
        enum KeyCode
        {
            A,              //     The A key.
            B,              //     The B key.
            C,              //     The C key.
            D,              //     The D key.
            E,              //     The E key.
            F,              //     The F key.
            G,              //     The G key.
            H,              //     The H key.
            I,              //     The I key.
            J,              //     The J key.
            K,              //     The K key.
            L,              //     The L key.
            M,              //     The M key.
            N,              //     The N key.
            O,              //     The O key.
            P,              //   The P key.
            Q,              //   The Q key.
            R,              //   The R key.
            S,              //   The S key.
            T,              //   The T key.
            U,              //   The U key.
            V,              //   The V key.
            W,              //   The W key.
            X,              //   The X key.
            Y,              //   The Y key.
            Z,              //     The Z key.
            Num0,           //    The 0 key.
            Num1,           //    The 1 key.
            Num2,           //    The 2 key.
            Num3,           //    The 3 key.
            Num4,           //    The 4 key.
            Num5,           //    The 5 key.
            Num6,           //    The 6 key.
            Num7,           //    The 7 key.
            Num8,           //    The 8 key.
            Num9,           //    The 9 key.
            Escape,         //      The Escape key.
            LControl,       //    The left Control key.
            LShift,         //      The left Shift key.
            LAlt,           //    The left Alt key.
            LSystem,        //   The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
            RControl,       //    The right Control key.
            RShift,         //      The right Shift key.
            RAlt,           //    The right Alt key.
            RSystem,        //   The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
            Menu,           //    The Menu key.
            LBracket,       //    The [ key.
            RBracket,       //    The ] key.
            Semicolon,      //     The ; key.
            Comma,          //     The , key.
            Period,         //  The . key.
            Quote,          //     The ' key.
            Slash,          //     The / key.
            Backslash,      //     The \ key.
            Tilde,          //     The ~ key.
            Equal,          //     The = key.
            Hyphen,         //    The - key (hyphen)
            Space,          //     The Space key.
            Enter,          //     The Enter/Return keys.
            Backspace,      //     The Backspace key.
            Tab,            //  The Tabulation key.
            PageUp,         //     The Page up key.
            PageDown,       //    The Page down key.
            End,            //  The End key.
            Home,           //   The Home key.
            Insert,         //     The Insert key.
            Delete,         //     The Delete key.
            Add,            //  The + key.
            Subtract,       //    The - key (minus, usually from numpad)
            Multiply,       //    The * key.
            Divide,         //     The / key.
            Left,           //   Left arrow.
            Right,          //    Right arrow.
            Up,             //     Up arrow.
            Down,           //   Down arrow.
            Numpad0,        //   The numpad 0 key.
            Numpad1,        //   The numpad 1 key.
            Numpad2,        //   The numpad 2 key.
            Numpad3,        //   The numpad 3 key.
            Numpad4,        //   The numpad 4 key.
            Numpad5,        //   The numpad 5 key.
            Numpad6,        //   The numpad 6 key.
            Numpad7,        //   The numpad 7 key.
            Numpad8,        //   The numpad 8 key.
            Numpad9,        //   The numpad 9 key.
            F1,             //     The F1 key.
            F2,             //     The F2 key.
            F3,             //     The F3 key.
            F4,             //     The F4 key.
            F5,             //     The F5 key.
            F6,             //     The F6 key.
            F7,             //     The F7 key.
            F8,             //     The F8 key.
            F9,             //     The F9 key.
            F10,            //    The F10 key.
            F11,            //    The F11 key.
            F12,            //    The F12 key.
            F13,            //    The F13 key.
            F14,            //  The F14 key.
            F15,            //  The F15 key.
            Pause,          //    The Pause key.
            KeyCount,       //    Keep last – the total number of keyboard keys.
            MouseButton1,   //    Left Click
            MouseButton2,   //    RightClick
            MouseButton3,   //    MiddleClick

        };

        class IDisplayModule {
            public:
                /**
                 * @brief Destroy the IDisplayModule object
                 * 
                 */
                virtual ~IDisplayModule() = default;

                /**
                 * @brief return true if the key is pressed
                 * 
                 * @attention if held down must only tell once
                 * @param Code is the key code to check if pressed
                 * @return true if the key is pressed
                 * @return false if the key is not pressed
                 */
                virtual bool isKeyPressed(KeyCode Code) = 0;

                /**
                 * @brief Get the Mouse X Position object
                 * 
                 * @return unsigned int the x position of the mouse
                 */
                virtual unsigned int getMouseXPosition() const = 0;

                /**
                 * @brief Get the Mouse Y Position object
                 * 
                 * @return unsigned int the y position of the mouse
                 */
                virtual unsigned int getMouseYPosition()const  = 0;

                /**
                 * @brief Stores inputs
                 * 
                 * @attention must be called once per frame, ex: before any logic calls to use them of course
                 * @example a map of key codes that says if they are pressed or not
                 */
                virtual void fetchInputs() = 0;

                /**
                 * @brief Set the Resolution object
                 *
                 * @param x if x is 0, the window will be fullscreen
                 * @param y if y is 0, the window will be fullscreen
                 */
                virtual void setResolution(unsigned int x, unsigned int y) = 0;

                /**
                 * @brief Get the Window Width object
                 * 
                 * @return unsigned int the width of the window
                 */
                virtual unsigned int getWindowWidth() = 0;

                /**
                 * @brief Get the Window Height object
                 * 
                 * @return unsigned int the height of the window
                 */
                virtual unsigned int getWindowHeight() = 0;

                /**
                 * @brief Set the Fps object
                 * 
                 * @param fps the fps to set
                 */
                virtual void setFps(int fps) = 0;

                /**
                 * @brief Set the Window Title object
                 * 
                 * @param title the title to set to the window
                 */
                virtual void setWindowTitle(std::string title) = 0;

                /**
                 * @brief Set the Full Screen object
                 * 
                 * @param fullScreen if true, the window will be fullscreen
                 */
                virtual void setFullScreen(bool fullScreen) = 0;

                /**
                 * @brief tell if the window / program is still running
                 * 
                 * @return true if the window is still running
                 * @return false if the window is not running
                 */
                virtual bool isOpen() = 0;

                /**
                 * @brief tell if the display is text mode or not
                 * 
                 * @return true if the display is text mode
                 * @return false if the display is not text mode
                 */
                virtual bool isTextMode() = 0;

                /**
                 * @brief clear the window
                 * 
                 */
                virtual void clearWindow() = 0;

                /**
                 * @brief display the window
                 * 
                 */
                virtual void displayWindow() = 0;

                /**
                 * @brief close the window
                 * 
                 */
                virtual void closeWindow() = 0;

                /**
                 * @brief draw a sprite module
                 * 
                 * @param sprite the sprite to draw
                 */
                virtual void draw(std::shared_ptr<arcade::interface::ISpriteModule> sprite) = 0;

                /**
                 * @brief draw a text module
                 * 
                 * @param text the text to draw
                 */
                virtual void draw(std::shared_ptr<arcade::interface::ITextModule> text) = 0;

                /**
                 * @brief Create a Sprite object
                 * 
                 * @return return a sprite module 
                 */
                virtual std::shared_ptr<arcade::interface::ISpriteModule> createSprite() = 0;
                /**
                 * @brief Create a Text object
                 * 
                 * @return return a text module 
                 */
                virtual std::shared_ptr<arcade::interface::ITextModule> createText() = 0;

                /**
                 * @brief Create a Audio object
                 * 
                 * @return return a audio module
                 */
                virtual std::shared_ptr<arcade::interface::IAudioModule> createAudio() = 0;

                /////////////////////////////////////////////////////////
        };
    }
}   

#endif /* !IDIPSPLAYMODULE_HPP_ */
