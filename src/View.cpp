#include "GameBoardTypes.h"
#include "GameBoard.h"
#include "View.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void View::view(GameBoard game){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            if (game.getb(row, col) == DEAD)
                cout << "| ";
            else if (game.getb(row, col) == ALIVE)
                cout << "|O";
        }
        cout << "|";
        cout << endl;
    }
    cout << endl;
}

void View::save(GameBoard game, string s){
	ofstream file;
    file.open(s);
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            if (game.getb(row, col) == DEAD)
                file << "0";
            else if (game.getb(row, col) == ALIVE)
                file << "1";
            if (col != SIZE-1)
                file << ",";
        }
        file << endl;
    }
    file.close();
}