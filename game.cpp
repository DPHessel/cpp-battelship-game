/*
 * Deuane Hessel
 * CIST 2362 C++
 * Fall 2026 Midterm
 * File: game.cpp
 * Project: C++ II Midterm - Text-Based Battleship Game
 *
 * Description:
 * Defines the Game class methods. This file contains the main menu, gameplay
 * loop, player switching, demonstration ship setup, and save/load algorithms.
 
 */

// Makes the declarations from this header/library available in this file.
#include "game.h"
// Makes the declarations from this header/library available in this file.
#include "validation.h"

// <iostream> provides console output.
// Makes the declarations from this header/library available in this file.
#include <iostream>

// <filesystem> lets the program create the save folder and list saved games.
// Makes the declarations from this header/library available in this file.
#include <filesystem>

// <string> provides save-game names and file paths.
// Makes the declarations from this header/library available in this file.
#include <string>

// <vector> is used when building ship-coordinate collections and loading saved boards.
// Makes the declarations from this header/library available in this file.
#include <vector>

// Defines or declares this function and its parameters.
Game::Game()
    : currentPlayer(1)
{
}

// Defines or declares this function and its parameters.
void Game::setupShips(Board& board, int playerNumber)
{
    // Three ships provide enough variety to demonstrate different ship sizes.
    // Calls this function to perform the required operation.
    Ship carrier("Carrier", 5);
    // Calls this function to perform the required operation.
    Ship battleship("Battleship", 4);
    // Calls this function to perform the required operation.
    Ship cruiser("Cruiser", 3);

    // Tests this condition so the program can choose the appropriate action.
    if (playerNumber == 1)
    {
        // std::vector stores all coordinates occupied by each ship.
        // Calls this function to perform the required operation.
        carrier.placeShip({{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}});
        // Calls this function to perform the required operation.
        battleship.placeShip({{2, 0}, {2, 1}, {2, 2}, {2, 3}});
        // Calls this function to perform the required operation.
        cruiser.placeShip({{4, 0}, {4, 1}, {4, 2}});
    }
    // Handles the remaining case when earlier conditions were false.
    else
    {
        // Player 2 uses different locations so both boards can be demonstrated.
        // Calls this function to perform the required operation.
        carrier.placeShip({{1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}});
        // Calls this function to perform the required operation.
        battleship.placeShip({{3, 5}, {3, 6}, {3, 7}, {3, 8}});
        // Calls this function to perform the required operation.
        cruiser.placeShip({{6, 1}, {6, 2}, {6, 3}});
    }

    // Board::placeShip validates coordinates before marking them with S.
    // Calls this function to perform the required operation.
    board.placeShip(carrier);
    // Calls this function to perform the required operation.
    board.placeShip(battleship);
    // Calls this function to perform the required operation.
    board.placeShip(cruiser);
}

// Defines or declares this function and its parameters.
void Game::startGame()
{
    // Repeats this block while the condition remains true.
    while (true)
    {
        // Displays this message or value in the console for the player.
        std::cout << "\n========================================\n";
        // Displays this message or value in the console for the player.
        std::cout << "       TEXT-BASED BATTLESHIP GAME\n";
        // Displays this message or value in the console for the player.
        std::cout << "========================================\n";
        // Displays this message or value in the console for the player.
        std::cout << "1. Create a New Game\n";
        // Displays this message or value in the console for the player.
        std::cout << "2. Load Saved Game\n";
        // Displays this message or value in the console for the player.
        std::cout << "3. Exit\n\n";

        // Declares an integer variable used for numeric game data.
        int choice = getValidInteger("Enter your choice: ", 1, 3);

        // Tests this condition so the program can choose the appropriate action.
        if (choice == 1)
        {
            // Calls this function to perform the required operation.
            player1Board.initializeBoard();
            // Calls this function to perform the required operation.
            player2Board.initializeBoard();
            // Assigns the required value so the object reflects the current game state.
            currentPlayer = 1;

            // Calls this function to perform the required operation.
            setupShips(player1Board, 1);
            // Calls this function to perform the required operation.
            setupShips(player2Board, 2);

            // Displays this message or value in the console for the player.
            std::cout << "\nNew game created. Ship locations are visible for evaluation.\n";
            // Calls this function to perform the required operation.
            playGame();
        }
        // Tests another condition only when the previous condition was false.
        else if (choice == 2)
        {
            // Show available names before asking which game the user wants.
            // Tests this condition so the program can choose the appropriate action.
            if (!displaySavedGames())
            {
                // Displays this message or value in the console for the player.
                std::cout << "Returning to the main menu.\n";
                // Restarts the loop so the user can enter another value.
                continue;
            }

            // Declares a Boolean variable used to track a true/false condition.
            bool loaded = false;

            // Repeats this block while the condition remains true.
            while (!loaded)
            {
                std::string fileName = getValidFileName(
                    // Calls this function to perform the required operation.
                    "\nEnter the name of the game you want to load: ");

                // Assigns the required value so the object reflects the current game state.
                loaded = loadGame(fileName);

                // Tests this condition so the program can choose the appropriate action.
                if (!loaded)
                {
                    // Displays this message or value in the console for the player.
                    std::cout << "\n1. Try Again\n";
                    // Displays this message or value in the console for the player.
                    std::cout << "2. Return to Main Menu\n";

                    // Declares an integer variable used for numeric game data.
                    int loadChoice = getValidInteger("Enter your choice: ", 1, 2);

                    // Tests this condition so the program can choose the appropriate action.
                    if (loadChoice == 2)
                    {
                        // Exits the current loop after the requested condition is met.
                        break;
                    }

                    // Re-display the list before the next attempt.
                    // Calls this function to perform the required operation.
                    displaySavedGames();
                }
            }

            // Tests this condition so the program can choose the appropriate action.
            if (loaded)
            {
                // Calls this function to perform the required operation.
                playGame();
            }
        }
        // Handles the remaining case when earlier conditions were false.
        else
        {
            // Displays this message or value in the console for the player.
            std::cout << "Thank you for playing Battleship.\n";
            // Completes this declaration or statement.
            return;
        }
    }
}

// Defines or declares this function and its parameters.
void Game::playGame()
{
    // Repeats this block while the condition remains true.
    while (true)
    {
        // Displays this message or value in the console for the player.
        std::cout << "\n========================================\n";
        // Displays this message or value in the console for the player.
        std::cout << "PLAYER " << currentPlayer << " TURN\n";
        // Displays this message or value in the console for the player.
        std::cout << "========================================\n";

        // Displays this message or value in the console for the player.
        std::cout << "\nPlayer 1 Board:\n";
        // Calls this function to perform the required operation.
        player1Board.displayBoard();

        // Displays this message or value in the console for the player.
        std::cout << "\nPlayer 2 Board:\n";
        // Calls this function to perform the required operation.
        player2Board.displayBoard();

        // Displays this message or value in the console for the player.
        std::cout << "\n1. Make a Move\n";
        // Displays this message or value in the console for the player.
        std::cout << "2. Save Game\n";
        // Displays this message or value in the console for the player.
        std::cout << "3. Return to Main Menu\n";

        // Declares an integer variable used for numeric game data.
        int choice = getValidInteger("Enter your choice: ", 1, 3);

        // Tests this condition so the program can choose the appropriate action.
        if (choice == 1)
        {
            // Assigns the required value so the object reflects the current game state.
            Board& opponentBoard = (currentPlayer == 1) ? player2Board : player1Board;

            // Declares an integer variable used for numeric game data.
            int row = getValidInteger("Enter attack row (0-9): ", 0, 9);
            // Declares an integer variable used for numeric game data.
            int column = getValidInteger("Enter attack column (0-9): ", 0, 9);

            // Tests this condition so the program can choose the appropriate action.
            if (opponentBoard.alreadyAttacked(row, column))
            {
                // Displays this message or value in the console for the player.
                std::cout << "That location has already been attacked. Try again.\n";
                // Restarts the loop so the user can enter another value.
                continue;
            }

            // Declares a Boolean variable used to track a true/false condition.
            bool hit = opponentBoard.receiveAttack(row, column);

            // Tests this condition so the program can choose the appropriate action.
            if (hit)
            {
                // Displays this message or value in the console for the player.
                std::cout << "HIT!\n";
            }
            // Handles the remaining case when earlier conditions were false.
            else
            {
                // Displays this message or value in the console for the player.
                std::cout << "MISS!\n";
            }

            // Displays this message or value in the console for the player.
            std::cout << "\nUpdated opponent board:\n";
            // Calls this function to perform the required operation.
            opponentBoard.displayBoard();

            // Tests this condition so the program can choose the appropriate action.
            if (checkWinner())
            {
                // Displays this message or value in the console for the player.
                std::cout << "\nPlayer " << currentPlayer
                          // Completes this declaration or statement.
                          << " wins! All opponent ships have been sunk.\n";
                // Completes this declaration or statement.
                return;
            }

            // Calls this function to perform the required operation.
            switchPlayer();
        }
        // Tests another condition only when the previous condition was false.
        else if (choice == 2)
        {
            // The user chooses the name instead of overwriting one fixed save file.
            std::string fileName = getValidFileName(
                // Calls this function to perform the required operation.
                "Enter a name for this saved game: ");
            // Calls this function to perform the required operation.
            saveGame(fileName);
        }
        // Handles the remaining case when earlier conditions were false.
        else
        {
            // Completes this declaration or statement.
            return;
        }
    }
}

// Defines or declares this function and its parameters.
void Game::switchPlayer()
{
    // Tests this condition so the program can choose the appropriate action.
    if (currentPlayer == 1)
    {
        // Assigns the required value so the object reflects the current game state.
        currentPlayer = 2;
    }
    // Handles the remaining case when earlier conditions were false.
    else
    {
        // Assigns the required value so the object reflects the current game state.
        currentPlayer = 1;
    }
}

bool Game::checkWinner() const
{
    // Returns this result to the calling function and ends the current function.
    return player1Board.allShipsSunk() || player2Board.allShipsSunk();
}

// Opens a file for output so the current game state can be saved.
void Game::saveBoard(std::ofstream& outputFile, const Board& board) const
{
    // Assigns the required value so the object reflects the current game state.
    const std::vector<std::vector<char>>& boardGrid = board.getGrid();

    // Write each row as 10 characters so the visual board state can be restored exactly.
    // Repeats this block for each required item or board position.
    for (const std::vector<char>& row : boardGrid)
    {
        // Repeats this block for each required item or board position.
        for (char location : row)
        {
            // Completes this declaration or statement.
            outputFile << location;
        }
        // Completes this declaration or statement.
        outputFile << '\n';
    }

    // Assigns the required value so the object reflects the current game state.
    const std::vector<Ship>& boardShips = board.getShips();
    // Declares a function interface so other code can call this behavior.
    outputFile << boardShips.size() << '\n';

    // Save the logical Ship data in addition to the visible grid.
    // Repeats this block for each required item or board position.
    for (const Ship& ship : boardShips)
    {
        outputFile << ship.getName() << ' '
                   << ship.getSize() << ' '
                   << ship.getHitPoints() << ' '
                   // Declares a function interface so other code can call this behavior.
                   << ship.getCoordinates().size() << '\n';

        // Repeats this block for each required item or board position.
        for (const std::pair<int, int>& coordinate : ship.getCoordinates())
        {
            // Completes this declaration or statement.
            outputFile << coordinate.first << ' ' << coordinate.second << '\n';
        }
    }
}

void Game::saveGame(const std::string& fileName) const
{
    // Assigns the required value so the object reflects the current game state.
    const std::string saveFolder = "saved_games";

    // Create the folder automatically the first time the user saves a game.
    // Uses the C++17 filesystem library to work with the save-game folder or files.
    std::filesystem::create_directories(saveFolder);

    // The user enters only a game name; the program builds the complete path.
    // Assigns the required value so the object reflects the current game state.
    const std::string filePath = saveFolder + "/" + fileName + ".txt";
    // Opens a file for output so the current game state can be saved.
    std::ofstream outputFile(filePath);

    // Tests this condition so the program can choose the appropriate action.
    if (!outputFile)
    {
        // Displays this message or value in the console for the player.
        std::cout << "Unable to save the game. The file could not be opened.\n";
        // Completes this declaration or statement.
        return;
    }

    // Completes this declaration or statement.
    outputFile << "BATTLESHIP_SAVE_V1\n";
    // Completes this declaration or statement.
    outputFile << currentPlayer << '\n';

    // Calls this function to perform the required operation.
    saveBoard(outputFile, player1Board);
    // Calls this function to perform the required operation.
    saveBoard(outputFile, player2Board);

    // Closes the file explicitly after all required data has been processed.
    outputFile.close();
    // Displays this message or value in the console for the player.
    std::cout << "Game successfully saved as \"" << fileName << "\".\n";
}

// Opens a file for input so a previously saved game can be restored.
bool Game::loadBoard(std::ifstream& inputFile, Board& board)
{
    // Assigns the required value so the object reflects the current game state.
    const int boardSize = 10;
    std::vector<std::vector<char>> loadedGrid(
        // Calls this function to perform the required operation.
        boardSize, std::vector<char>(boardSize, 'O'));

    // Read the 10 saved rows and verify that each row has the expected length.
    // Repeats this block for each required item or board position.
    for (int row = 0; row < boardSize; ++row)
    {
        // Declares a string variable used to store text safely.
        std::string rowData;
        // Completes this declaration or statement.
        inputFile >> rowData;

        // Tests this condition so the program can choose the appropriate action.
        if (!inputFile || static_cast<int>(rowData.length()) != boardSize)
        {
            // Returns this result to the calling function and ends the current function.
            return false;
        }

        // Repeats this block for each required item or board position.
        for (int column = 0; column < boardSize; ++column)
        {
            // Assigns the required value so the object reflects the current game state.
            loadedGrid[row][column] = rowData[column];
        }
    }

    // Declares an integer variable used for numeric game data.
    int shipCount;
    // Completes this declaration or statement.
    inputFile >> shipCount;

    // Tests this condition so the program can choose the appropriate action.
    if (!inputFile || shipCount < 0)
    {
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Completes this declaration or statement.
    std::vector<Ship> loadedShips;

    // Repeats this block for each required item or board position.
    for (int index = 0; index < shipCount; ++index)
    {
        // Declares a string variable used to store text safely.
        std::string name;
        // Declares an integer variable used for numeric game data.
        int size;
        // Declares an integer variable used for numeric game data.
        int hitPoints;
        // Declares an integer variable used for numeric game data.
        int coordinateCount;

        // Completes this declaration or statement.
        inputFile >> name >> size >> hitPoints >> coordinateCount;

        // Tests this condition so the program can choose the appropriate action.
        if (!inputFile || size < 1 || coordinateCount < 1)
        {
            // Returns this result to the calling function and ends the current function.
            return false;
        }

        // Completes this declaration or statement.
        std::vector<std::pair<int, int>> coordinates;

        // Repeats this block for each required item or board position.
        for (int coordinateIndex = 0; coordinateIndex < coordinateCount; ++coordinateIndex)
        {
            // Declares an integer variable used for numeric game data.
            int row;
            // Declares an integer variable used for numeric game data.
            int column;
            // Completes this declaration or statement.
            inputFile >> row >> column;

            // Tests this condition so the program can choose the appropriate action.
            if (!inputFile || row < 0 || row >= boardSize || column < 0 || column >= boardSize)
            {
                // Returns this result to the calling function and ends the current function.
                return false;
            }

            // Adds this object to the end of the vector.
            coordinates.push_back({row, column});
        }

        // Calls this function to perform the required operation.
        Ship ship(name, size);
        // Calls this function to perform the required operation.
        ship.placeShip(coordinates);
        // Calls this function to perform the required operation.
        ship.setHitPoints(hitPoints);
        // Adds this object to the end of the vector.
        loadedShips.push_back(ship);
    }

    // Calls this function to perform the required operation.
    board.setGrid(loadedGrid);
    // Calls this function to perform the required operation.
    board.setShips(loadedShips);
    // Returns this result to the calling function and ends the current function.
    return true;
}

// Defines or declares this function and its parameters.
bool Game::loadGame(const std::string& fileName)
{
    // Assigns the required value so the object reflects the current game state.
    const std::string saveFolder = "saved_games";
    // Assigns the required value so the object reflects the current game state.
    const std::string filePath = saveFolder + "/" + fileName + ".txt";

    // Opens a file for input so a previously saved game can be restored.
    std::ifstream inputFile(filePath);

    // Tests this condition so the program can choose the appropriate action.
    if (!inputFile)
    {
        // A name can pass character validation but still refer to a file that does not exist.
        // Displays this message or value in the console for the player.
        std::cout << "Saved game \"" << fileName << "\" was not found.\n";
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Declares a string variable used to store text safely.
    std::string fileHeader;
    // Completes this declaration or statement.
    inputFile >> fileHeader;

    // Tests this condition so the program can choose the appropriate action.
    if (fileHeader != "BATTLESHIP_SAVE_V1")
    {
        // Displays this message or value in the console for the player.
        std::cout << "The save file is not in the expected Battleship format.\n";
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Declares an integer variable used for numeric game data.
    int loadedPlayer;
    // Completes this declaration or statement.
    inputFile >> loadedPlayer;

    // Tests this condition so the program can choose the appropriate action.
    if (!inputFile || (loadedPlayer != 1 && loadedPlayer != 2))
    {
        // Displays this message or value in the console for the player.
        std::cout << "The saved current-player value is invalid.\n";
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Completes this declaration or statement.
    Board loadedPlayer1Board;
    // Completes this declaration or statement.
    Board loadedPlayer2Board;

    // Tests this condition so the program can choose the appropriate action.
    if (!loadBoard(inputFile, loadedPlayer1Board) ||
        !loadBoard(inputFile, loadedPlayer2Board))
    {
        // Displays this message or value in the console for the player.
        std::cout << "The saved game data is incomplete or invalid.\n";
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Replace the active game only after the entire file passes validation.
    // Assigns the required value so the object reflects the current game state.
    player1Board = loadedPlayer1Board;
    // Assigns the required value so the object reflects the current game state.
    player2Board = loadedPlayer2Board;
    // Assigns the required value so the object reflects the current game state.
    currentPlayer = loadedPlayer;

    // Closes the file explicitly after all required data has been processed.
    inputFile.close();
    // Displays this message or value in the console for the player.
    std::cout << "Game \"" << fileName << "\" loaded successfully.\n";
    // Returns this result to the calling function and ends the current function.
    return true;
}

bool Game::displaySavedGames() const
{
    // Assigns the required value so the object reflects the current game state.
    const std::string saveFolder = "saved_games";

    // Tests this condition so the program can choose the appropriate action.
    if (!std::filesystem::exists(saveFolder))
    {
        // Displays this message or value in the console for the player.
        std::cout << "\nNo saved games were found.\n";
        // Returns this result to the calling function and ends the current function.
        return false;
    }

    // Displays this message or value in the console for the player.
    std::cout << "\n========== SAVED GAMES ==========\n\n";

    // Declares a Boolean variable used to track a true/false condition.
    bool gameFound = false;
    // Declares an integer variable used for numeric game data.
    int number = 1;

    // directory_iterator examines each entry in the save folder.
    // Repeats this block for each required item or board position.
    for (const auto& file : std::filesystem::directory_iterator(saveFolder))
    {
        // Tests this condition so the program can choose the appropriate action.
        if (file.is_regular_file() && file.path().extension() == ".txt")
        {
            // Assigns the required value so the object reflects the current game state.
            gameFound = true;

            // stem() displays the friendly save name without the .txt extension.
            // Displays this message or value in the console for the player.
            std::cout << number << ". " << file.path().stem().string() << '\n';
            // Completes this declaration or statement.
            ++number;
        }
    }

    // Tests this condition so the program can choose the appropriate action.
    if (!gameFound)
    {
        // Displays this message or value in the console for the player.
        std::cout << "No saved games were found.\n";
    }

    // Returns this result to the calling function and ends the current function.
    return gameFound;
}
