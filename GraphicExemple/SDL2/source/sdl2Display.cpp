/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** sdl2Display
*/

#include "../include/sdl2Display.hpp"

arcade::sdl2Display::~sdl2Display()
{
    closeWindow();
}

void arcade::sdl2Display::closeWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
    SDL_Quit();
}

arcade::sdl2Display::sdl2Display()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Arcade SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void arcade::sdl2Display::setResolution(unsigned int x, unsigned int y)
{
    SDL_SetWindowSize(window, x, y);
}

void arcade::sdl2Display::setWindowTitle(const std::string &title)
{
    SDL_SetWindowTitle(window, title.c_str());
}

unsigned int arcade::sdl2Display::getWindowWidth() const
{
    int w;

    SDL_GetWindowSize(window, &w, NULL);
    return w;
}

unsigned int arcade::sdl2Display::getWindowHeight() const
{
    int h;

    SDL_GetWindowSize(window, NULL, &h);
    return h;
}

bool arcade::sdl2Display::isOpen()
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void arcade::sdl2Display::clearWindow()
{
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);
}

void arcade::sdl2Display::displayWindow()
{
    SDL_RenderPresent(rend);
}

bool arcade::sdl2Display::isTextMode() const
{
    return false;
}

void arcade::sdl2Display::setFullscreen(bool fullscreen)
{
    if (fullscreen == true)
        setResolution(1920, 1080);
}

std::shared_ptr<arcade::interface::ISpriteModule> arcade::sdl2Display::createSprite()
{
    return std::make_shared<sdl2Sprite>(window, rend);
}

std::shared_ptr<arcade::interface::ITextModule> arcade::sdl2Display::createText()
{
    return std::make_shared<sdl2Text>(rend);
}

std::shared_ptr<arcade::interface::IAudioModule> arcade::sdl2Display::createAudio()
{
    return std::make_shared<sdl2Audio>();
}

//INPUT:
void arcade::sdl2Display::fetchInputs()
{
    SDL_Event event;
    const Uint8* state = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            closeWindow();
        state = SDL_GetKeyboardState(NULL);

        // // Mouse Input
        pressedKeys[arcade::interface::KeyCode::MouseButton1] = state[SDL_BUTTON_LEFT];
        pressedKeys[arcade::interface::KeyCode::MouseButton2] = state[SDL_BUTTON_RIGHT];
        pressedKeys[arcade::interface::KeyCode::MouseButton3] = state[SDL_BUTTON_MIDDLE];

        // // keyboard inputs
        for (int i = 0; i < arcade::interface::KeyCount; ++i)
            pressedKeys[(arcade::interface::KeyCode)i] = state[(SDL_Scancode)i];
    }
    
}

bool arcade::sdl2Display::isKeyPressed(arcade::interface::KeyCode key)
{
    return pressedKeys[key];
}

unsigned int arcade::sdl2Display::getMouseXPosition() const
{
    int x = 0;
    SDL_GetMouseState(&x, NULL);
    return x;
}

unsigned int arcade::sdl2Display::getMouseYPosition() const
{
    int y = 0;
    SDL_GetMouseState(NULL, &y);
    return y;
}

void arcade::sdl2Display::setFps(int fps)
{
    // window->setFramerateLimit(fps);
}

////////////////////////////////////

// DRAW LOGIC:
void arcade::sdl2Display::draw(std::shared_ptr<arcade::interface::ISpriteModule> spriteModule)
{
    std::pair<float, float> posRect = spriteModule.get()->getPosition();
    SDL_Rect position = {(int)posRect.first, (int)posRect.second};
    SDL_RenderCopy(rend, reinterpret_cast<SDL_Texture *>(spriteModule.get()->getSprite()), NULL, &position);
}

void arcade::sdl2Display::draw(std::shared_ptr<arcade::interface::ITextModule> textModule)
{
    std::pair<float, float> posRect = textModule.get()->getPosition();
    SDL_Rect position = {(int)posRect.first, (int)posRect.second};
    SDL_RenderCopy(rend, reinterpret_cast<SDL_Texture *>(textModule.get()->getText()), NULL, &position);
}