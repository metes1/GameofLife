#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "GameBoard.h"
#include "View.h"
#include "GameBoardTypes.h"
#include "Exceptions.h"

int main() {
  std::cout << "'make experiment' will run this main" << std::endl;

  GameBoard test;
  test.init("input.txt");
  View::view(test);
  for (int i = 0; i < 30; i++)
    test.next();

  View::view(test);
  View::save(test, "output.txt");
  return 0;
}