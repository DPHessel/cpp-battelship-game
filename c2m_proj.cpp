/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: c2m_proj.cpp
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * This file contains the program's main function.
 *
 * Purpose:
 * main() creates the Game object and transfers control to the Game class.
 * Keeping main() small allows the object-oriented classes to handle the
 * responsibilities that belong to the Battleship game itself.

 */

// Includes the Game class declaration so main() can create a Game object.
// Makes the declarations from this header/library available in this file.
#include "game.h"

/*
 * Function: main
 * Purpose: Serves as the starting point of the program.
 * Parameters: None.
 * Return value: 0 indicates that the program ended normally.
 */
// Defines or declares this function and its parameters.
int main()
{
    // Creates the object that manages both boards, player turns, and file operations.
    // Completes this declaration or statement.
    Game battleshipGame;

    // Starts the main menu and keeps the program running until the user exits.
    // Calls this function to perform the required operation.
    battleshipGame.startGame();

    // Returning zero tells the operating system that execution completed successfully.
    // Returns this result to the calling function and ends the current function.
    return 0;
}
