/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: game.h
 * Purpose: Part of the C++ II Text-Based Battleship Midterm project.
 */
// Begins the header guard so this header is included only once per translation unit.
#ifndef GAME_H
// Defines the header-guard symbol after the first inclusion.
#define GAME_H

// Makes the declarations from this header/library available in this file.
#include "board.h"
// Makes the declarations from this header/library available in this file.
#include <fstream>
// Makes the declarations from this header/library available in this file.
#include <string>

// Declares a class that groups related data and behavior into one object type.
class Game
{
// Controls which class members are hidden internally or accessible to other code.
private:
    // Stores Player 1’s complete board and fleet state.
    Board player1Board;
    // Stores Player 2’s complete board and fleet state.
    Board player2Board;
    // Tracks whose turn is active so turns can be restored when loading.
    int currentPlayer;

    // Calls this function to perform the required operation.
    void setupShips(Board& board, int playerNumber);
    // Calls this function to perform the required operation.
    void playGame();
    // Declares a Boolean variable used to track a true/false condition.
    bool checkWinner() const;
    // Opens a file for output so the current game state can be saved.
    void saveBoard(std::ofstream& outputFile, const Board& board) const;
    // Declares a Boolean variable used to track a true/false condition.
    bool loadBoard(std::ifstream& inputFile, Board& board);

// Controls which class members are hidden internally or accessible to other code.
public:
    // Calls this function to perform the required operation.
    Game();

    // Displays the main menu and controls new-game/load/exit choices.
    // Calls this function to perform the required operation.
    void startGame();

    // Changes the active player from 1 to 2 or from 2 to 1.
    // Calls this function to perform the required operation.
    void switchPlayer();

    /* saveGame
     * Saves the complete game under a user-selected name inside saved_games.
     * The .txt extension is added automatically.
     */
    // Declares a function interface so other code can call this behavior.
    void saveGame(const std::string& fileName) const;

    /* loadGame
     * Loads one specifically named saved game from saved_games.
     * Returns false if the file is missing or invalid.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool loadGame(const std::string& fileName);

    /* displaySavedGames
     * Lists the names of all .txt save files currently available.
     * Returns true if at least one saved game exists.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool displaySavedGames() const;
};

// Ends the header guard.
#endif
