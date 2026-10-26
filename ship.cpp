/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: ship.cpp
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * This file defines the member functions declared by the Ship class.
 *
 * Purpose:
 * The functions in this file control ship placement information, hit-point
 * changes, and sunk-status checks.
 
 */

// Includes the Ship class declaration so these member functions can be defined.
// Makes the declarations from this header/library available in this file.
#include "ship.h"

// Creates an empty/default ship.
// Defines or declares this function and its parameters.
Ship::Ship()
    : name("Unknown"), size(0), hitPoints(0)
{
}

// Creates a named ship and starts its hit points at its full size.
// Defines or declares this function and its parameters.
Ship::Ship(const std::string& shipName, int shipSize)
    : name(shipName), size(shipSize), hitPoints(shipSize)
{
}

// Copies the supplied coordinates into the ship's coordinate vector.
// Defines or declares this function and its parameters.
void Ship::placeShip(const std::vector<std::pair<int, int>>& coords)
{
    // Assigns the required value so the object reflects the current game state.
    coordinates = coords;
}

// A ship is sunk when no hit points remain.
bool Ship::isSunk() const
{
    // Returns this result to the calling function and ends the current function.
    return hitPoints == 0;
}

// Removes one hit point, but never allows the value to become negative.
// Defines or declares this function and its parameters.
void Ship::receiveHit()
{
    // Tests this condition so the program can choose the appropriate action.
    if (hitPoints > 0)
    {
        // Completes this declaration or statement.
        --hitPoints;
    }
}

// Returns the ship's name without changing the Ship object.
std::string Ship::getName() const
{
    // Returns this result to the calling function and ends the current function.
    return name;
}

// Returns the number of spaces occupied by the ship.
int Ship::getSize() const
{
    // Returns this result to the calling function and ends the current function.
    return size;
}

// Returns the ship's remaining hit points.
int Ship::getHitPoints() const
{
    // Returns this result to the calling function and ends the current function.
    return hitPoints;
}

// Returns a constant reference to avoid making an unnecessary copy of the coordinate vector.
const std::vector<std::pair<int, int>>& Ship::getCoordinates() const
{
    // Returns this result to the calling function and ends the current function.
    return coordinates;
}

// Restores hit points from a save file while keeping the value within a valid range.
// Defines or declares this function and its parameters.
void Ship::setHitPoints(int points)
{
    // Tests this condition so the program can choose the appropriate action.
    if (points < 0)
    {
        // Assigns the required value so the object reflects the current game state.
        hitPoints = 0;
    }
    // Tests another condition only when the previous condition was false.
    else if (points > size)
    {
        // Assigns the required value so the object reflects the current game state.
        hitPoints = size;
    }
    // Handles the remaining case when earlier conditions were false.
    else
    {
        // Assigns the required value so the object reflects the current game state.
        hitPoints = points;
    }
}
