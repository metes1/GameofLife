#include "GameBoard.h"
#include "GameBoardTypes.h"
#include "Exceptions.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void GameBoard::init(string s){
    vector<cellT> row; // vector to hold a row
    cellT cell; // holds the state of a cell
    int num; // holds cell state that is read from the file

    ifstream file(s);
    if (file.is_open())
    {
      string line;
      while ( getline(file,line) )
      { 
        istringstream ss(line);
        string token;
        row.clear();
        while ( getline(ss, token, ',') ) {
            num = stoi(token);
            if(num == 0)
                cell = DEAD;
            else if (num == 1)
                cell = ALIVE;
            row.push_back(cell);
        }
        b.push_back(row);
      }
      file.close();
    }
    else
      throw invalid_file();
}

void GameBoard::next(){
    boardT tempB; // holds new state of game temporarily
    vector<cellT> tempRow; // holds new row temporarily
    cellT cell = DEAD; // holds new state of cell
    int neighbours; // holds number of live neighbour

    for (int row = 0; row < SIZE; row++){
        tempRow.clear();
        for (int col = 0; col < SIZE; col++){
            neighbours = liveNeighbours(row,col);
            if (b[row][col] == DEAD)
                if (neighbours == 3)
                    cell = ALIVE;
                else
                    cell = DEAD;
            else if (b[row][col] == ALIVE)
                if (neighbours <= 1)
                    cell = DEAD;
                else if (neighbours >= 4)
                    cell = DEAD;
                else if (neighbours == 2 || neighbours == 3)
                    cell = ALIVE;
            tempRow.push_back(cell);
        }
        tempB.push_back(tempRow);
    }
    b = tempB; // set state of gameboard to the newly transitioned state
}

cellT GameBoard::getb(int i, int j){
    if (validPosition(i, j))
        return b[i][j];
    else
        throw out_of_bounds();       
}

//private methods

int GameBoard::liveNeighbours(int i, int j){
    int alive = 0; // holds number of live neighbours

    if (validPosition(i-1,j-1))
        if (b[i-1][j-1] == ALIVE) alive++;

    if (validPosition(i-1,j))
        if (b[i-1][j] == ALIVE) alive++;

    if (validPosition(i-1,j+1))
        if (b[i-1][j+1] == ALIVE) alive++;

    if (validPosition(i,j-1))
        if (b[i][j-1] == ALIVE) alive++;

    if (validPosition(i,j+1))
        if (b[i][j+1] == ALIVE) alive++;

    if (validPosition(i+1,j-1))
        if (b[i+1][j-1] == ALIVE) alive++;

    if (validPosition(i+1,j))
        if (b[i+1][j] == ALIVE) alive++;

    if (validPosition(i+1,j+1))
        if (b[i+1][j+1] == ALIVE) alive++;

    return alive;
}

bool GameBoard::validPosition(int i, int j){
    return ((i >= 0 && i < SIZE) && (j >= 0 && j < SIZE));
}