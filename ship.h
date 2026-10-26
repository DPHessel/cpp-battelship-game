/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: ship.h
 * Purpose: Part of the C++ II Text-Based Battleship Midterm project.
 */
// Begins the header guard so this header is included only once per translation unit.
#ifndef SHIP_H
// Defines the header-guard symbol after the first inclusion.
#define SHIP_H

/*
 * File: ship.h
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * This file declares the Ship class. A Ship object stores the information
 * needed to represent one ship in the Battleship game, including its name,
 * size, board coordinates, and remaining hit points.
 *
 * Purpose:
 * Keeping ship information inside a class allows the Board and Game classes
 * to work with complete Ship objects instead of managing separate pieces of
 * ship data throughout the program.
 */

// <string> provides std::string, which is used to store a ship's name.
// Makes the declarations from this header/library available in this file.
#include <string>

// <utility> provides std::pair, which keeps a row and column together as one coordinate.
// Makes the declarations from this header/library available in this file.
#include <utility>

// <vector> provides std::vector, which stores a ship's collection of coordinates.
// Makes the declarations from this header/library available in this file.
#include <vector>

/*
 * Class: Ship
 * Purpose:
 * Represents one ship placed on a Battleship board. The class is necessary
 * because each ship must remember where it is located and how many hit points
 * it has remaining.
 */
// Declares a class that groups related data and behavior into one object type.
class Ship
{
// Controls which class members are hidden internally or accessible to other code.
private:
    // Stores the ship's descriptive name, such as Carrier or Battleship.
    // Declares a string variable used to store text safely.
    std::string name;

    // Stores the number of board positions occupied by the ship.
    // Declares an integer variable used for numeric game data.
    int size;

    // Stores every row/column coordinate occupied by this ship.
    // Completes this declaration or statement.
    std::vector<std::pair<int, int>> coordinates;

    // Stores how many undamaged positions remain on the ship.
    // Declares an integer variable used for numeric game data.
    int hitPoints;

// Controls which class members are hidden internally or accessible to other code.
public:
    /*
     * Default constructor.
     * Purpose: Creates an empty Ship object when a default object is needed.
     * Parameters: None.
     * Return value: Constructors do not return a value.
     */
    // Calls this function to perform the required operation.
    Ship();

    /*
     * Constructor.
     * Purpose: Creates a ship with a name and size and gives it full hit points.
     * Parameters:
     *   shipName - the descriptive name of the ship.
     *   shipSize - the number of board positions occupied by the ship.
     * Return value: Constructors do not return a value.
     */
    // Calls this function to perform the required operation.
    Ship(const std::string& shipName, int shipSize);

    /*
     * placeShip
     * Purpose: Stores the board coordinates occupied by this ship.
     * Parameter:
     *   coords - the row/column coordinates assigned to the ship.
     * Return value: None.
     */
    // Calls this function to perform the required operation.
    void placeShip(const std::vector<std::pair<int, int>>& coords);

    /*
     * isSunk
     * Purpose: Determines whether this ship has lost all hit points.
     * Parameters: None.
     * Return value: true when hitPoints is zero; otherwise false.
     */
    // Declares a Boolean variable used to track a true/false condition.
    bool isSunk() const;

    /*
     * receiveHit
     * Purpose: Reduces the ship's remaining hit points after a successful attack.
     * Parameters: None.
     * Return value: None.
     */
    // Calls this function to perform the required operation.
    void receiveHit();

    // The following getter functions safely provide read access to private data.
    // Declares a string variable used to store text safely.
    std::string getName() const;
    // Declares an integer variable used for numeric game data.
    int getSize() const;
    // Declares an integer variable used for numeric game data.
    int getHitPoints() const;
    // Declares a function interface so other code can call this behavior.
    const std::vector<std::pair<int, int>>& getCoordinates() const;

    /*
     * setHitPoints
     * Purpose: Restores saved hit-point information when a game is loaded.
     * Parameter:
     *   points - the saved number of remaining hit points.
     * Return value: None.
     */
    // Calls this function to perform the required operation.
    void setHitPoints(int points);
};

// Ends the header guard.
#endif
