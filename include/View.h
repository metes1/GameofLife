/**
 * \file View.h
 * \brief A module for displaying the state of the gameboard using text based graphics and saving the state to a file.
 * \author Seda Mete metes1
 * \date April 9th, 2019
*/

#ifndef VIEW_H
#define VIEW_H

#include "GameBoardTypes.h"
#include "GameBoard.h"

#include <string>
using std::string;

/**
 *  \brief Class containing the functions that both display and save the state of the gameboard
 */
class View {
    private:

    public:
        /**
         *  \brief Display the current state of the game to the cancel using ASCII art
         *  \param game The gameboard
         */
        static void view(GameBoard game);

        /**
         *  \brief Saves the current state of the game to a text file
         *  \param game The gameboard
         *  \param s Name of output file 
         */
        static void save(GameBoard game, string s);
};

#endif