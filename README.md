# C++ Battleship Game

A two-player, text-based Battleship game developed in C++ as a programming course project. The project demonstrates object-oriented programming, game-state management, input validation, and file handling.

## Features

- Two players take turns playing Battleship in the console.
- Players place ships on their boards.
- The game tracks shots as hits or misses.
- Ships can be identified as sunk when all their positions have been hit.
- Players can view their own board and their tracking view of the opponent's board.
- Save and load game progress using files.

## Programming Concepts

- **Object-oriented programming:** Classes organize the responsibilities of the game.
- **Classes and encapsulation:** `Ship`, `Board`, `Player`, and `Game` represent the core game components.
- **Standard library containers:** Store ship positions and game-related data.
- **Input validation:** Check player choices and game input.
- **File I/O:** Preserve and restore game state.
- **Modular design:** Separate declarations and implementations into header (`.h`) and source (`.cpp`) files, where applicable.

## Project Structure

The project uses the following main class responsibilities:

| Class | Responsibility |
| --- | --- |
| `Ship` | Stores ship information, positions, and hit status |
| `Board` | Manages the playing grid and ships |
| `Player` | Stores player information, their board, and their view of the opponent |
| `Game` | Coordinates setup, turns, and overall gameplay |

See the source files in this repository for the actual filenames and implementation details.

## How to Run

1. Download or clone this repository.
2. Open the project in a C++ IDE such as **CLion**, or configure a C++ compiler for the source files.
3. Build the project using its included project configuration, if provided. Otherwise, compile all required `.cpp` implementation files together.
4. Run the resulting executable and follow the console prompts.

> **Note:** The exact build command depends on the filenames and project configuration uploaded to this repository.

## Example Gameplay

The console interface guides players through ship placement and alternating attacks. After each turn, the game reports whether a shot was a hit or a miss and updates the boards.

## Future Improvements

Potential enhancements include automated tests, more flexible board sizes, and improved on-screen instructions.

## Author

**Deuane Hessel**  
Computer Programming student, Gwinnett Technical College  
GitHub: [DPHessel](https://github.com/DPHessel)
