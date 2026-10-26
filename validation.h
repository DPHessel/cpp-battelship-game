/*
* Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: validation.h
 * Purpose: Part of the C++ II Text-Based Battleship Midterm project.
 */
// Begins the header guard so this header is included only once per translation unit.
#ifndef VALIDATION_H
// Defines the header-guard symbol after the first inclusion.
#define VALIDATION_H

// Makes the declarations from this header/library available in this file.
#include <string>

/*
 * getValidInteger
 * Purpose: Repeatedly prompts until the entire input line contains only
 *          digits and the resulting integer is inside the required range.
 * This prevents mixed input such as 1a, a1, and 2.5 from being accepted.
 */
// Declares an integer variable used for numeric game data.
int getValidInteger(const std::string& prompt, int minimum, int maximum);

/*
 * getValidFileName
 * Purpose: Repeatedly prompts for a safe save-game name.
 * Allowed characters: letters, numbers, underscore, and hyphen.
 * The user does not type the .txt extension; the program adds it.
 */
// Declares a string variable used to store text safely.
std::string getValidFileName(const std::string& prompt);

// Ends the header guard.
#endif
