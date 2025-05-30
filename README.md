# monkeytype_game-SMFL
# NumberOne Typing Game

NumberOne is a dynamic and engaging typing game developed in C++ using the SFML library for graphics and the fmt library for text formatting. Test and improve your typing speed and accuracy as words scroll across the screen!

## Table of Contents

-   [Features](#features)
-   [Screenshots](#screenshots)
-   [Prerequisites](#prerequisites)
-   [Building and Running](#building-and-running)
-   [How to Play](#how-to-play)
-   [Game Controls](#game-controls)
-   [Project Structure](#project-structure)
-   [Dependencies](#dependencies)
-   [Contributing](#contributing)
-   [License](#license)

## Features

*   **Interactive Main Menu:** Easily navigate to Start Game, view High Scores, read Instructions, or Exit.
*   **Engaging Gameplay:** Type words as they move horizontally across the screen.
*   **Dynamic Difficulty:** Word speed subtly increases as your score improves. Manually adjust speed with PageUp/PageDown keys.
*   **Scoring System:** Earn 10 points for each correctly typed word.
*   **Persistent High Scores:** The top 10 scores are saved and displayed on the Records screen.
*   **Instruction Screen:** A dedicated screen with a visual guide on game elements.
*   **In-Game Customization:**
    *   Adjust word speed on the fly.
    *   Pause and resume the game.
    *   Cycle through multiple fonts for the falling words.
*   **Customizable Assets:** Game assets (fonts, textures, word lists) are loaded from an external `Assets` directory, making them easy to modify.

## Screenshots

*(It's highly recommended to add screenshots or GIFs of the game menu, gameplay, records screen, and instruction screen here to make the README more engaging.)*

**Example:**
*Main Menu:*
`[Image of Main Menu]`

*Gameplay:*
`[GIF of Gameplay]`

*Records Screen:*
`[Image of Records Screen]`

## Prerequisites

To build and run NumberOne, you'll need the following:

*   **C++ Compiler:** A compiler that supports C++20 (e.g., GCC, Clang, MSVC).
*   **CMake:** Version 3.31 or higher.
*   **Git:** For cloning the repository and allowing CMake to fetch dependencies.
*   **SFML Dependencies:** On Linux, you might need to install SFML's system dependencies (e.g., `libxrandr-dev`, `libxcursor-dev`, `libudev-dev`, `libfreetype-dev`, `libopenal-dev`, `libflac-dev`, `libvorbis-dev`). CMake's FetchContent will download and build SFML itself.

## Building and Running

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/your-username/numberOne.git # Replace with your repository URL
    cd numberOne
    ```

2.  **Configure the project with CMake:**
    This command will create a `build` directory and prepare the build system. CMake will also automatically fetch and configure SFML and fmt.
    ```bash
    cmake -B build -S .
    ```

3.  **Build the project:**
    ```bash
    cmake --build build
    ```
    On some systems, you might need to specify a configuration, e.g., `cmake --build build --config Release`.

4.  **Run the game:**
    The executable, named `numberOne` (or `numberOne.exe` on Windows), will be located in the `build` directory (or a subdirectory like `build/Debug` or `build/Release` depending on your CMake generator).
    ```bash
    # From the project root directory:
    ./build/numberOne
    ```
    Or, if built in a specific configuration:
    ```bash
    ./build/Release/numberOne # Example for Release configuration
    ```

## How to Play

1.  **Launch the game.** You'll be greeted by the Main Menu.
2.  **Navigate the Menu:**
    *   Click "**StartGame**" to begin playing.
    *   Click "**Records**" to view the top high scores.
    *   Click "**Instruction**" to see a visual guide and key bindings.
    *   Click "**Exit**" to close the game.
3.  **Gameplay:**
    *   Words will start scrolling from the left side of the screen.
    *   Type the words as they appear using your keyboard.
    *   If you type a word correctly, it will "fall" off the screen, and you'll score 10 points.
    *   If a word reaches the right edge of the screen before you type it, the game is over.
4.  **Game Over:** When the game ends, your score is automatically saved if it's among the top scores. You'll see a "Game Over" message. You can then use the back arrow to return to the Main Menu.

## Game Controls

### Menu Navigation:
*   **Mouse Click:** Interact with buttons on the Main Menu, Records, and Instruction screens.
*   **Back Arrow Button (Top-Left of sub-screens):** Returns to the Main Menu from the Game, Records, or Instruction screens.

### In-Game:
*   **Alphabetical Keys (A-Z):** Type the letters of the words.
*   **Backspace:** Delete the last typed character from your current input.
*   **Escape (Esc):** Pause or resume the game.
*   **Page Up (PgUp):** Increase the speed of the falling words.
*   **Page Down (PgDn):** Decrease the speed of the falling words.
*   **Left Control (LCtrl) / Right Control (RCtrl):** Cycle through different fonts for the game words.

## Project Structure
numberOne/
├── Assets/
│ ├── ButtonTextures/ # .png files for button appearances
│ ├── Fonts/ # .ttf font files
│ ├── Images/ # .png background images and other graphics
│ ├── records/
│ │ └── records.txt # Stores high scores
│ └── wordsList/
│ └── wordsList_1.txt # Text file containing words for the game
├── sourceCodes/
│ ├── Menu.cpp
│ ├── Menu.hpp
│ ├── gameStart.cpp
│ ├── gameStart.hpp
│ ├── RecordMng.cpp
│ ├── RecordMng.hpp
│ ├── RecordsMenu.cpp
│ ├── RecordsMenu.hpp
│ ├── wordGenerator.cpp
│ └── wordGenerator.hpp
├── main.cpp # Main entry point of the application
└── CMakeLists.txt # CMake build script


*   `main.cpp`: Entry point of the application, launches the main menu.
*   `sourceCodes/`: Contains all C++ source (`.cpp`) and header (`.hpp`) files, organized by game module (Menu, Game Logic, Record Management, Word Generation).
*   `Assets/`: Contains all external game assets.

## Dependencies

The project uses the following external libraries, which are automatically downloaded and configured by CMake via `FetchContent`:

*   **SFML (Simple and Fast Multimedia Library) version 3.0.1:** Used for graphics, windowing, audio, and input handling.
    *   Repository: `https://github.com/SFML/SFML.git`
*   **fmt (Modern Formatting Library) version 11.2.0:** Used for string formatting, providing a fast and safe alternative to C-style printf or C++ iostreams for certain tasks.
    *   Repository: `https://github.com/fmtlib/fmt`

You do not need to install these libraries manually; CMake handles their inclusion during the build process.

## Contributing

Contributions are welcome! If you have suggestions for improvements or want to report a bug, please feel free to open an issue or submit a pull request.

(If you have specific contribution guidelines, add them here.)

## License

This project is currently not under a specific license. Please specify a license if you intend for others to use, modify, or distribute your code. Consider common open-source licenses like MIT, Apache 2.0, or GPL.
