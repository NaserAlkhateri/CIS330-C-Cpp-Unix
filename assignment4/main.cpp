//main.cpp

#include "reversi.hpp"
#include <iostream>
using namespace std;


int main(){

  int size;
  cout << "Please enter the size of the board 4 - 16: " << endl;
  cin >> size;

  while(size < 4 || size > 16){
    cout << "Please enter the size of the board 4 - 16: " << endl;
    cin >> size;
  }
  Board board(size);
  board.defaultBoard();
  board.makeMovement();
  return 0;
}
