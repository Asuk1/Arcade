# General

The arcade project has a simple goal : create an Arcade station.
For this we must represent a station (**Core**) that can work with any graphical library (**Graphical Wrappers**).
The **core** must display all games leaderboards and be able to run any game (**Game Wrapper**).
In order to do this we have to make sure that each of these **3 different parts** can be built individually.
We also must be able to **share** any **Game Wrapper** or **Graphical Wrapper** with each other.
So here are some ideas (thoses are the files we will use together even if we change them before starting developping)

# Graphical Wrapper

Go into **ModuleWrappers/** directory to see Module ideas
Go into **Graphic Exemple/** directory to see an implementation exemple
We must aggree on a **symbol signature** to load our classes, I propose the following for **Graphical modules**:

- For IDisplayModule:
  ```cpp
      extern "C" std::shared_ptr<IDisplayModule> createDisplay();
      extern "C" std::string getType(void)
  ```
- For ISpriteModule:
  ```cpp
      extern "C" std::shared_ptr<ISpriteModule> createSprite();
      extern "C" std::string getType(void)
  ```
- For ITextModule:
  ```cpp
      extern "C" std::shared_ptr<ITextModule> createText();
      extern "C" std::string getType(void)
  ```
- For IAudioModule:
  ```cpp
      extern "C" std::shared_ptr<IAudioModule> createAudio();
      extern "C" std::string getType(void)
  ```

- [ ] Game Wrapper

Go into **IGameModule.hpp** to see a wrapper Idea
Go into **Game Exemple/** directory to see an implementation exemple
We must aggree on a **symbol signature** to load our classes, I propose the following for **Game Module**:

- For IGameModule:
  ```cpp
      extern "C" std::shared_ptr<IGameModule> createGame();
      extern "C" std::string getType(void)
  ```

# Updates

1.0) First Idea

- These documentation/Interfaces files are not finished yet (they are still on mockup)
- We ask anybody to add new ideas in the chat and we will update it for sure :)
  2.0) Added Modules
- Added IAudioModule
- Added all key codes for inputs
- Slowly getting to usable code instead of pseudo code
- Didn't touched exemples
  2.1) Added exemples
- Specified exemples in sfml wrapper
  2.2) Discussed things
- Documented file types management
- Removed getType from IDisplayModule

# To Discuss

- Do we want to be able to pass arguments at module construction ? If yes it must be the case at all time ! Result : NO
- File types ? Result : Give filepath without extention, must have all file types in directory
- throw or noexept ?  : Throw a specific class
