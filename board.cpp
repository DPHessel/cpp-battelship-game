/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: board.cpp
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * Defines the Board class methods for initialization, ship placement,
 * attack processing, board display, and fleet-status checks.

 */

// Makes the declarations from this header/library available in this file.
#include "board.h"

// <iostream> provides std::cout for displaying the board and messages.
// Makes the declarations from this header/library available in this file.
#include <iostream>

// <iomanip> provides std::setw for aligned row and column output.
// Makes the declarations from this header/library available in this file.
#include <iomanip>

// The constructor immediately creates a clean board.
// Defines or declares this function and its parameters.
Board::Board()
{
    // Calls this function to perform the required operation.
    initializeBoard();
}

// Defines or declares this function and its parameters.
void Board::initializeBoard()
{
    // assign() creates 10 rows, with each row containing 10 water symbols.
    // Fills the container with the required number of initialized elements.
    grid.assign(BOARD_SIZE, std::vector<char>(BOARD_SIZE, 'O'));

    // clear() removes any ships from a previous game before a new game starts.
    // Removes old stored elements so a fresh game state can be created.
    ships.clear();
}

// Defines or declares this function and its parameters.
bool Board::placeShip(Ship& ship)
{
    // A constant reference avoids copying the vector while it is checked.
    // Assigns the required value so the object reflects the current game state.
    const std::vector<std::pair<int, int>>& coords = ship.getCoordinates();

    // A ship must contain exactly as many coordinates as its size requires.
    // Tests this condition so the program can choose the appropriate action.
    if (static_cast<int>(coords.size()) != ship.getSize())
    {
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Validate every coordinate before changing the grid.
    // Repeats this block for each required item or board position.
    for (const std::pair<int, int>& coordinate : coords)
    {
        // Declares an integer variable used for numeric game data.
        int row = coordinate.first;
        // Declares an integer variable used for numeric game data.
        int column = coordinate.second;

        // Reject coordinates outside the 10 x 10 board.
        // Tests this condition so the program can choose the appropriate action.
        if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
        {
            // Returns this result to the calling function and ends the current function.
            return false;
        }

        // Only water can receive a new ship, preventing overlap.
        // Tests this condition so the program can choose the appropriate action.
        if (grid[row][column] != 'O')
        {
            // Returns this result to the calling function and ends the current function.
            return false;
        }
    }

    // All coordinates are valid, so the ship can now be placed safely.
    // Repeats this block for each required item or board position.
    for (const std::pair<int, int>& coordinate : coords)
    {
        // Assigns the required value so the object reflects the current game state.
        grid[coordinate.first][coordinate.second] = 'S';
    }

    // push_back() adds a copy of the completed Ship object to the board's fleet.
    // Adds this object to the end of the vector.
    ships.push_back(ship);
    // Returns this result to the calling function and ends the current function.
    return true;
}

// Defines or declares this function and its parameters.
bool Board::receiveAttack(int row, int column)
{
    // Protect the grid from an invalid index even if this function is called incorrectly.
    // Tests this condition so the program can choose the appropriate action.
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
    {
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Tests this condition so the program can choose the appropriate action.
    if (grid[row][column] == 'S')
    {
        // X represents a successful attack on a ship.
        // Assigns the required value so the object reflects the current game state.
        grid[row][column] = 'X';

        // Search for the Ship object that owns the attacked coordinate.
        // Repeats this block for each required item or board position.
        for (Ship& ship : ships)
        {
            // Repeats this block for each required item or board position.
            for (const std::pair<int, int>& coordinate : ship.getCoordinates())
            {
                // Tests this condition so the program can choose the appropriate action.
                if (coordinate.first == row && coordinate.second == column)
                {
                    // Calls this function to perform the required operation.
                    ship.receiveHit();

                    // Tell the player immediately when this hit sinks a ship.
                    // Tests this condition so the program can choose the appropriate action.
                    if (ship.isSunk())
                    {
                        // Displays this message or value in the console for the player.
                        std::cout << ship.getName() << " has been sunk!\n";
                    }

                    // Returns this result to the calling function and ends the current function.
                    return true;
                }
            }
        }

        // Returns this result to the calling function and ends the current function.
        return true;
    }

    // Tests this condition so the program can choose the appropriate action.
    if (grid[row][column] == 'O')
    {
        // M is an additional display symbol used to remember a missed attack.
        // Assigns the required value so the object reflects the current game state.
        grid[row][column] = 'M';
    }

    // Returns this result to the calling function and ends the current function.
    return false;
}

void Board::displayBoard() const
{
    // Displays this message or value in the console for the player.
    std::cout << "    ";

    // Print the column numbers across the top of the board.
    // Repeats this block for each required item or board position.
    for (int column = 0; column < BOARD_SIZE; ++column)
    {
        // Displays this message or value in the console for the player.
        std::cout << std::setw(2) << column << ' ';
    }

    // Displays this message or value in the console for the player.
    std::cout << '\n';

    // Print each row number followed by the 10 stored board symbols.
    // Repeats this block for each required item or board position.
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        // Displays this message or value in the console for the player.
        std::cout << std::setw(2) << row << "  ";

        // Repeats this block for each required item or board position.
        for (int column = 0; column < BOARD_SIZE; ++column)
        {
            // Displays this message or value in the console for the player.
            std::cout << std::setw(2) << grid[row][column] << ' ';
        }

        // Displays this message or value in the console for the player.
        std::cout << '\n';
    }

    // Displays this message or value in the console for the player.
    std::cout << "Legend: O = Water, S = Ship, X = Hit, M = Miss\n";
}

bool Board::allShipsSunk() const
{
    // An empty board should not be treated as a defeated fleet.
    // Tests this condition so the program can choose the appropriate action.
    if (ships.empty())
    {
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // If even one ship is still afloat, the fleet has not been completely sunk.
    // Repeats this block for each required item or board position.
    for (const Ship& ship : ships)
    {
        // Tests this condition so the program can choose the appropriate action.
        if (!ship.isSunk())
        {
            // Returns this result to the calling function and ends the current function.
            return false;
        }
    }

    // Returns this result to the calling function and ends the current function.
    return true;
}

bool Board::alreadyAttacked(int row, int column) const
{
    // Tests this condition so the program can choose the appropriate action.
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
    {
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Previous attacks are represented by X for hit or M for miss.
    // Returns this result to the calling function and ends the current function.
    return grid[row][column] == 'X' || grid[row][column] == 'M';
}

const std::vector<std::vector<char>>& Board::getGrid() const
{
    // Returns this result to the calling function and ends the current function.
    return grid;
}

const std::vector<Ship>& Board::getShips() const
{
    // Returns this result to the calling function and ends the current function.
    return ships;
}

// Defines or declares this function and its parameters.
void Board::setGrid(const std::vector<std::vector<char>>& newGrid)
{
    // Assigns the required value so the object reflects the current game state.
    grid = newGrid;
}

// Defines or declares this function and its parameters.
void Board::setShips(const std::vector<Ship>& newShips)
{
    // Assigns the required value so the object reflects the current game state.
    ships = newShips;
}
