/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: validation.cpp
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * Defines reusable validation functions for numeric input and save-game names.
 */

// Makes the declarations from this header/library available in this file.
#include "validation.h"

// <cctype> provides std::isdigit and std::isalnum for character validation.
// Makes the declarations from this header/library available in this file.
#include <cctype>

// <iostream> provides console input and output.
// Makes the declarations from this header/library available in this file.
#include <iostream>

// <string> provides std::string and std::stoi.
// Makes the declarations from this header/library available in this file.
#include <string>

// Defines or declares this function and its parameters.
int getValidInteger(const std::string& prompt, int minimum, int maximum)
{
    // Declares a string variable used to store text safely.
    std::string input;

    // Repeats this block while the condition remains true.
    while (true)
    {
        // Displays this message or value in the console for the player.
        std::cout << prompt;

        // getline() reads the entire line so input such as "1a" cannot leave
        // extra characters behind and accidentally be accepted as integer 1.
        // Reads the entire input line so extra characters cannot be silently ignored.
        std::getline(std::cin, input);

        // Tests this condition so the program can choose the appropriate action.
        if (input.empty())
        {
            // Displays this message or value in the console for the player.
            std::cout << "Invalid input. Please enter a number from "
                      // Completes this declaration or statement.
                      << minimum << " to " << maximum << ".\n";
            // Restarts the loop so the user can enter another value.
            continue;
        }

        // Declares a Boolean variable used to track a true/false condition.
        bool digitsOnly = true;

        // Check every character before attempting numeric conversion.
        // Repeats this block for each required item or board position.
        for (char character : input)
        {
            // Tests this condition so the program can choose the appropriate action.
            if (!std::isdigit(static_cast<unsigned char>(character)))
            {
                // Assigns the required value so the object reflects the current game state.
                digitsOnly = false;
                // Exits the current loop after the requested condition is met.
                break;
            }
        }

        // Tests this condition so the program can choose the appropriate action.
        if (!digitsOnly)
        {
            // Displays this message or value in the console for the player.
            std::cout << "Invalid input. Please enter numbers only.\n";
            // Restarts the loop so the user can enter another value.
            continue;
        }

        try
        {
            // stoi() converts the already-validated digit string to an int.
            // Declares an integer variable used for numeric game data.
            int value = std::stoi(input);

            // Tests this condition so the program can choose the appropriate action.
            if (value < minimum || value > maximum)
            {
                // Displays this message or value in the console for the player.
                std::cout << "Invalid choice. Please enter a number from "
                          // Completes this declaration or statement.
                          << minimum << " to " << maximum << ".\n";
                // Restarts the loop so the user can enter another value.
                continue;
            }

            // Returns this result to the calling function and ends the current function.
            return value;
        }
        catch (...)
        {
            // This also protects the program from a number too large for int.
            // Displays this message or value in the console for the player.
            std::cout << "Invalid input. The number is too large. Try again.\n";
        }
    }
}

// Defines or declares this function and its parameters.
std::string getValidFileName(const std::string& prompt)
{
    // Declares a string variable used to store text safely.
    std::string fileName;

    // Repeats this block while the condition remains true.
    while (true)
    {
        // Displays this message or value in the console for the player.
        std::cout << prompt;
        // Reads the entire input line so extra characters cannot be silently ignored.
        std::getline(std::cin, fileName);

        // Tests this condition so the program can choose the appropriate action.
        if (fileName.empty())
        {
            // Displays this message or value in the console for the player.
            std::cout << "File name cannot be empty.\n";
            // Restarts the loop so the user can enter another value.
            continue;
        }

        // Declares a Boolean variable used to track a true/false condition.
        bool valid = true;

        // Repeats this block for each required item or board position.
        for (char character : fileName)
        {
            // Restrict names to portable, easy-to-read characters.
            // Tests this condition so the program can choose the appropriate action.
            if (!std::isalnum(static_cast<unsigned char>(character)) &&
                character != '_' && character != '-')
            {
                // Assigns the required value so the object reflects the current game state.
                valid = false;
                // Exits the current loop after the requested condition is met.
                break;
            }
        }

        // Tests this condition so the program can choose the appropriate action.
        if (!valid)
        {
            // Displays this message or value in the console for the player.
            std::cout << "Invalid file name. Use letters, numbers, underscores, "
                      // Completes this declaration or statement.
                      << "or hyphens only.\n";
            // Restarts the loop so the user can enter another value.
            continue;
        }

        // Returns this result to the calling function and ends the current function.
        return fileName;
    }
}
