//reversi.cpp
//reversi.cpp

#include <iostream>
#include <string>
#include "reversi.hpp"
using namespace std;

//constructor
Board::Board(int size){
	m_size = size;
	m_isOver = false;
	m_brd = new string * [size];
	int i,j;
	
	for (i = 0; i < size; i++){
		m_brd[i] = new string [size];
		for(j = 0; j < size; j++){
			m_brd[i][j] = ".";
		}
	}
}

void Board::defaultBoard(){
	
	//place default moves

	int indexX = (m_size/2) - 1;
	
	m_brd[indexX][indexX] = "b";
	m_brd[indexX+1][indexX+1] = "b";
	m_brd[indexX][indexX+1] = "w";
	m_brd[indexX+1][indexX] = "w";
	
	
	
}

void Board::printBoard(){
	int i,j,count1 = 0,count2 = 0;
	
	
	cout << '\t';

	for(i = 0; i < m_size; i++){
    
		cout << i << " ";
	  
  }
  cout << endl;
  for(i = 0; i < m_size; i++){
    
    cout << i << "\t";
    for(j = 0; j < m_size; j++){
      cout << m_brd[i][j] << " ";
    }
    cout << endl;
  }	
  //added scores
	for(i = 0; i < m_size; i++){
		for(j =0; j < m_size; j++){
			if (m_brd[i][j] == "b"){
				count1++;
			}else if(m_brd[i][j] == "w"){
				count2++;
			}
			
		}
	}
  cout << "Scores: player1> " << count1 <<" player2> " << count2 << endl;
}
bool Board::isFinished(int playerNum){
	
	//checks all cases where available is a valid move exists
	// if returned false, then there are still possible moves for that player
	int i, j;
	for(i = 0; i < m_size; i++){
		for(j = 0; j< m_size; j++){
			if(checkPlays(i,j,playerNum) == true){
				return false;
			}
		}
		
	}
	cout << "No more possible moves for player " << playerNum << endl;
	m_isOver = true;
	return true;
	
	
}
bool Board::checkPlays(int x, int y, int playerNum){
	// this is a copy of validMovement, but instead only checks
	// if there are any more moves available from either side
	// to determine if the game has ended.
	
	int varX, varY, i;
  string player;
  if (playerNum == 1){
    player = "b";
  }else{player = "w";}
  
  if(m_brd[x][y] != "."){
	  return false;
  }
  
  if (y > 0 && player != m_brd[x][y-1] && m_brd[x][y-1] != "."){
    //left
    //cout << "left " << x << y << endl;
    varY = (m_size-1) - y;

	//cout << "entered\n";
	for(i=1;i<y;i++){
      if(player == m_brd[x][y-i]){	
		return true;
      }
    }
  
  }
  if(y < m_size-1 && player != m_brd[x][y+1] && m_brd[x][y+1] != "."){
    //right
    //cout << "right " << x << y << endl;
    varY = (m_size-1) - y;

    for(i=1;i<varY;i++){
      if(player == m_brd[x][y+i]){

	return true;
      }
    }
  }if(x < m_size-1 && player != m_brd[x+1][y] && m_brd[x+1][y] != "."){
    //down
    //cout << "down " << x << y << endl;
    varX = (m_size-1) - x;
 
      for(i=1;i<varX;i++){
	if(player == m_brd[x+i][y]){

	  return true;
	}
      }
    
  }
  if(x > 0 && player != m_brd[x-1][y] && m_brd[x-1][y] != "."){
    //up
	//cout << "up " << x << y << endl;

      varX = (m_size-1) - x;
      for(i=1;i<x;i++){
		if(player == m_brd[x-i][y]){
	  return true;
	}
      }
    
  }
  if(y > 0 && x < m_size-1 && player != m_brd[x+1][y-1] && m_brd[x+1][y-1] != "."){
    //down-left
    //cout << "down-left " << x << y <<endl;
    i = 1;
	
      varX = (m_size-1) - x;
      for(i=1;i<y || i<varX;i++){
		if(player == m_brd[x+i][y-i]){
			return true;
		}
      }
 
  }if(y > 1 && x > 1 && player != m_brd[x-1][y-1] && m_brd[x-1][y-1] != "."){
    //up-left
    //cout << "up-left " << x << y << endl;
    varX = (m_size-1) - x;

      for(i=1;i<x || i<y;i++){
	if(player == m_brd[x-i][y-i]){
	  return true;
	}
      }
 
  }if(y < m_size-1 && x < m_size-1 && player != m_brd[x+1][y+1] && m_brd[x+1][y+1] != "."){
	//down-right
	//cout << "down-right " << x << y << endl;
    varX = (m_size-1) - x;
    varY = (m_size-1) - y;
      for(i=1;i<varX || i<varY;i++){
	if(player == m_brd[x+i][y+i]){
	  return true;
	}
      }
    
  }if(y < m_size-1 && x > 2 && player != m_brd[x-1][y+1] && m_brd[x-1][y+1] != "."){
    //up-right
    //cout << "up-right " << x << y << endl;
 
	varY = (m_size-1) - y;

      for(i=1;i < x-1 || i < varY;i++){
		if(player == m_brd[x-i][y+i]){
			return true;
		}
      }
    

  }else{return false;}
  
  return false;
  
	
}
void Board::makeMovement(){

  int playerTurn = 1;
  int x, y;
  bool isValid = false;
  while(m_isOver == false){
    printBoard();
	//breaks when no valid moves available
	if (isFinished(playerTurn)){
		break;
	}
    cout << "Player " << playerTurn << " turn, input 2 numbers (0-"<< m_size-1 << ") row col: ";
    cin >> x >> y;
    while(x < 0 || x > m_size - 1 || y < 0 || y > m_size - 1){
      cout << "Invalid input:Player " << playerTurn << " turn, input 2 numbers (0-"<< m_size-1 << ") row col: ";
      cin >> x >> y;
    }
    isValid = validMovement(x, y, playerTurn);
    if (isValid){
      if (playerTurn == 1){
	m_brd[x][y] = "b";
	playerTurn = 2;
      }else{m_brd[x][y] = "w"; playerTurn = 1;}
      
    }else{cout << "invalid choice!" << endl;}
  }
  cout << "Game Over!" << endl;
}

bool Board::validMovement(int x, int y, int playerNum){

  int varX, varY, i, j;
  string player;
  if (playerNum == 1){
    player = "b";
  }else{player = "w";}
  //if not empty choice return
  if(m_brd[x][y] != "."){
	  return false;
  }
  if (y > 0 && player != m_brd[x][y-1] && m_brd[x][y-1] != "."){
    //left
    //cout << "left" << endl;
    varY = m_size - y;

	//cout << "entered\n";
	for(i=1;i<y;i++){
      if(player == m_brd[x][y-i]){
		for(j=1;j<y;j++){
	  
			if(m_brd[x][y-j] == "."){
				return true;
			}
			m_brd[x][y-j] = player;
		}
	
		return true;
      }
    }
  
  }
  if(y < m_size-1 && player != m_brd[x][y+1] && m_brd[x][y+1] != "."){
    //right
    //cout << "right" << endl;
    varY = m_size - y;

    for(i=1;i<varY;i++){
      if(player == m_brd[x][y+i]){
	for(j=1;j<varY;j++){
	  
	  if(m_brd[x][y+j] == "."){
	    return true;
	  }
	  m_brd[x][y+j] = player;
	}
	
	return true;
      }
    }
  }if(x < m_size-1 && player != m_brd[x+1][y] && m_brd[x+1][y] != "."){
    //down
    //cout << "down" << endl;
    varX = m_size - x;
 
      for(i=1;i<varX;i++){
	if(player == m_brd[x+i][y]){
	  for(j=1;j<varX;j++){
	    
	    if(m_brd[x+j][y] == "."){
	      return true;
	    }
	    m_brd[x+j][y] = player;
	  }
	  return true;
	}
      }
    
  }
  if(x > 0 && player != m_brd[x-1][y] && m_brd[x-1][y] != "."){
    //up
	//cout << "up" << endl;

      varX = m_size - x;
      for(i=1;i<x;i++){
		if(player == m_brd[x-i][y]){
			for(j=1;j<=x;j++){
	    
				if(m_brd[x-j][y] == "."){
					return true;
	    }
				m_brd[x-j][y] = player;
	  }
	  return true;
	}
      }
    
  }
  if(y > 0 && x < m_size-1 && player != m_brd[x+1][y-1] && m_brd[x+1][y-1] != "."){
    //down-left
    //cout << "down-left" << endl;
    
      varX = m_size - x;
      for(i=1; i < varX || i < y;i++){
		if(player == m_brd[x+i][y-i]){
			for(j=1;j<varX || j<y;j++){
	    
				if(m_brd[x+j][y-j] == "."){
					return true;
	    }
				m_brd[x+j][y-j] = player;
	  }
	  
	  return true;
	}
      }
    
  }if(y > 0 && x > 0 && player != m_brd[x-1][y-1] && m_brd[x-1][y-1] != "."){
    //up-left
    //cout << "up-left" << endl;


      for(i=1;i<x || i<y;i++){
		if(player == m_brd[x-i][y-i]){
			for(j=1;j<x || j<y;j++){
	    
				if(m_brd[x-j][y-j] == "."){
					return true;
				}
				m_brd[x-j][y-j] = player;
			}
	  
			return true;
		}
      }
 
  }if(y < m_size-1 && x < m_size-1 && player != m_brd[x+1][y+1] && m_brd[x+1][y+1] != "."){
	//down-right
	//cout << "down-right" << endl;
    varX = m_size - x;
    varY = m_size - y;
      for(i=1;i<varX || i<varY;i++){
	if(player == m_brd[x+i][y+i]){
	  for(j=1;j<varX || j<varY;j++){
				  
	    if(m_brd[x+j][y+j] == "."){
	      return true;
	    }
	    m_brd[x+j][y+j] = player;
	  }
	  
	  return true;
	}
      }
    
  }if(y < m_size-1 && x > 0 && player != m_brd[x-1][y+1] && m_brd[x-1][y+1] != "."){
    //up-right
    //cout << "up-right" << endl;
    varX = m_size - x;
	varY = m_size - y;
      for(i=1;i<=x || i<varY;i++){
		if(player == m_brd[x-i][y+i]){
			for(j=1;j<=x || j<varY;j++){
	    
				if(m_brd[x-j][y+j] == "."){
					return true;
				}
				m_brd[x-j][y+j] = player;
			}
	  
			return true;
		}
      }
    
  }else{return false;}
  
  return false;
  

}
       

Board::~Board(){
	
  int i;
  for (i = 0; i<m_size;i++){
    delete [] m_brd[i];
    
  }
  delete [] m_brd;
}
