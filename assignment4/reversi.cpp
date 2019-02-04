//reversi.cpp
//reversi.cpp

#include <iostream>
#include <string>
#include "reversi.hpp"
using namespace std;

//constructor
Board::Board(int size){
	m_size = size;
	m_brd = new string * [size];
	int i,j;
	
	for (i = 0; i < size; i++){
		m_brd[i] = new string [size];
		for(j = 0; j < size; j++){
			m_brd[i][j] = ". ";
		}
	}
}

void Board::defaultBoard(){
	
	//place default moves

	int indexX = (m_size/2) - 1;
	
	m_brd[indexX][indexX] = "b ";
	m_brd[indexX+1][indexX+1] = "b ";
	m_brd[indexX][indexX+1] = "w ";
	m_brd[indexX+1][indexX] = "w ";
	
	
	
}

void Board::printBoard(){
	int i,j;
	
	
	int size = m_size;
	cout << '\t';

	for(i = 0; i < m_size; i++){
    
		cout << i << " ";
	  
  }
  cout << endl;
  for(i = 0; i < m_size; i++){
    
    cout << i << "\t";
    for(j = 0; j < m_size; j++){
      cout << m_brd[i][j];
    }
    cout << endl;
  }	
}

Board::~Board(){
	
	int i;
	for (i = 0; i<m_size;i++){
		delete [] m_brd[i];
		
	}
	delete [] m_brd;
}
int main(){
	
	int size;
	cout << "Please enter the size of the board 4 - 16: " << endl;
	cin >> size;
	/*
	while(size < 4 || size > 16){
		cout << "Please enter the size of the board 4 - 16: " << endl;
		cin >> size;
  }
  */
  Board board(size);
  board.defaultBoard();
  board.printBoard();
	return 0;
}
