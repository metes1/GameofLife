/**
 * \file GameBoard.h
 * \brief A module for representing the state of the game.
 * \author Seda Mete metes1
 * \date April 9th, 2019
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameBoardTypes.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 *  \brief Class representing the gameboard
 */
class GameBoard {
    private:
        // type definition for gameboard
        typedef vector<vector<cellT>> boardT;

        // gameboard
        boardT b;

        // counts the number of live neighbours a cell has
        int liveNeighbours(int i, int j);

        // checks if cell index is in the range of the board
        bool validPosition(int i, int j);

    public:
        /**
         *  \brief Initializes inital state of the game through a text file.
         *  \param s Input file name
         *  \throw invalid_file The specified input does not exist
         */
        void init(string s);

        /**
         *  \brief Transition to the next state.
         */
        void next();

        /**
         *  \brief Returns the state of the specified cell.
         *  \param i Row index
         *  \param j Column index
         *  \return The state of the specified cell.
         *  \throw out_of_bounds The specified cell is out of the gameboard's bounds.
         */
        cellT getb(int i, int j);
};

#endif