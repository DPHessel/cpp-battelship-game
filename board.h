/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: board.h
 * Purpose: Part of the C++ II Text-Based Battleship Midterm project.
 */
// Begins the header guard so this header is included only once per translation unit.
#ifndef BOARD_H
// Defines the header-guard symbol after the first inclusion.
#define BOARD_H

/*
 * File: board.h
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * This file declares the Board class. A Board object stores a 10 x 10 grid
 * and the Ship objects belonging to one player.
 *
 * Purpose:
 * The Board class keeps board-related responsibilities together, including
 * initialization, ship placement, attacks, display, and fleet-status checks.
 */

// Includes Ship because Board stores a vector of Ship objects.
// Makes the declarations from this header/library available in this file.
#include "ship.h"

// <vector> provides the two-dimensional grid and the collection of ships.
// Makes the declarations from this header/library available in this file.
#include <vector>

// Declares a class that groups related data and behavior into one object type.
class Board
{
// Controls which class members are hidden internally or accessible to other code.
private:
    // A Battleship board contains 10 rows and 10 columns.
    // Defines one shared constant used to keep the board size consistent.
    static const int BOARD_SIZE = 10;

    // The two-dimensional vector stores the character displayed at each board location.
    // Stores the 10 x 10 board as rows and columns of display symbols.
    std::vector<std::vector<char>> grid;

    // This vector stores all ships belonging to this board.
    // Stores the Ship objects that belong to this board.
    std::vector<Ship> ships;

// Controls which class members are hidden internally or accessible to other code.
public:
    /*
     * Constructor.
     * Purpose: Creates a Board and initializes every location as empty water.
     */
    // Calls this function to perform the required operation.
    Board();

    /*
     * initializeBoard
     * Purpose: Resets all 100 locations to water and removes old ships.
     * Parameters: None.
     * Return value: None.
     */
    // Calls this function to perform the required operation.
    void initializeBoard();

    /*
     * placeShip
     * Purpose: Validates and places a prepared Ship object on the board.
     * Parameter:
     *   ship - the Ship object whose stored coordinates will be placed.
     * Return value: true if placement succeeds; false if a coordinate is invalid.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool placeShip(Ship& ship);

    /*
     * receiveAttack
     * Purpose: Processes an attack at one row and column.
     * Parameters:
     *   row - board row to attack.
     *   column - board column to attack.
     * Return value: true for a hit; false for a miss or invalid location.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool receiveAttack(int row, int column);

    /*
     * displayBoard
     * Purpose: Prints the board with row/column labels and a symbol legend.
     * Parameters: None.
     * Return value: None.
     */
    // Declares a function interface so other code can call this behavior.
    void displayBoard() const;

    /*
     * allShipsSunk
     * Purpose: Determines whether every ship on this board is sunk.
     * Return value: true only when all stored ships are sunk.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool allShipsSunk() const;

    /*
     * alreadyAttacked
     * Purpose: Prevents the same location from being attacked more than once.
     * Parameters: row and column identify the location to check.
     * Return value: true if the location contains a previous hit or miss.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool alreadyAttacked(int row, int column) const;

    // Getters provide data needed by the save-game functions.
    // Declares a function interface so other code can call this behavior.
    const std::vector<std::vector<char>>& getGrid() const;
    // Declares a function interface so other code can call this behavior.
    const std::vector<Ship>& getShips() const;

    // Setters restore saved board data when loading a game.
    // Calls this function to perform the required operation.
    void setGrid(const std::vector<std::vector<char>>& newGrid);
    // Calls this function to perform the required operation.
    void setShips(const std::vector<Ship>& newShips);
};

// Ends the header guard.
#endif
