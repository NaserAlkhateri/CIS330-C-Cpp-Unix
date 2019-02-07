//reversi.hpp


#ifndef __REVERSI_HPP
#define __REVERSI_HPP


#include <string>
using namespace std;

class Board {
	
public:
  Board(int size);
  void printBoard();
  void makeMovement();
  bool validMovement(int x, int y, int playerNum);
  bool checkPlays(int x, int y, int playerNum);
  bool isFinished(int playerNum);
  void defaultBoard();
  ~Board();
private:
  int m_size;
  int m_posX;
  int m_posY;
  bool m_isOver;
  string **m_brd;
  
};


#endif
