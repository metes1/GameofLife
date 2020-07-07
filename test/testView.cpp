#include "catch.h"
#include "GameBoard.h"
#include "GameBoardTypes.h"
#include "View.h"
#include "Exceptions.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

TEST_CASE( "tests for View" , "[View]" ) {
    GameBoard gameboard;
    gameboard.init("input.txt");

    SECTION("test save()"){
        gameboard.next();
        View::save(gameboard, "outputTest.txt");
        int num; // holds cell state that is read from the file
        int row = 0;
        int col = 0;
        ifstream file("outputTest.txt");

        //check if game board state was saved properly
        if (file.is_open())
        {
        string line;
        while ( getline(file,line) )
        { 
            istringstream ss(line);
            string token;
            col = 0;
            while ( getline(ss, token, ',') ) {
                num = stoi(token);
                REQUIRE(gameboard.getb(row, col) == num);
                col++;
        }
            row++;
        }
        file.close();
        }
        else
        throw invalid_file();
    }
}