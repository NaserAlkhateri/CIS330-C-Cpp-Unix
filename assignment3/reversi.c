//reversi.c

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "reversi.h"

//initialize board
void boardInit(int size, Board *board){

	

	board->size = size;
  char ***x;
  int i,j,k,n;
  //malloc array and fill with dots according to the size
  x = (char ***) malloc(size * sizeof(char *));
  for (i = 0; i < size; i++) {
    x[i] = (char **) malloc (size * sizeof(char *));
    for (j = 0; j < size; j++) {
      x[i][j] = (char *) malloc (size * sizeof(char *));
      for(k = 0; k < size; k++){
	x[i][j] = ". ";
      }
    }
  }
  
  board->array = x;
}

void printBoard(Board *board){
 //prints numbers for the coordinates, then prints board and a number for each line


	int i,j;
	
	char ***x = board->array;
	int size = board->size;
	printf("\t");

	for(i = 0; i < size; i++){
    
    printf("%d ",i);
	  
  }
  printf("\n");
  for(i = 0; i < size; i++){
    
    printf("%d\t",i);
    for(j = 0; j < size; j++){
      printf("%s",x[i][j]);
    }
    printf("\n");
  }	
}
void defaultBoard(Board *board){
	
	//place default moves
	int size = board->size;
	int indexX = (size/2) - 1;
	char ***x = board->array;
	x[indexX][indexX] = "b ";
	x[indexX+1][indexX+1] = "b ";
	x[indexX][indexX+1] = "w ";
	x[indexX+1][indexX] = "w ";
}
//checks if move is valid
bool validMovement(Board *board,int x, int y, int playerNum){
	
	char ***array = board->array;
	int size = board->size;
	char *player;
	int varX, varY, i, j;
	if (playerNum == 1){
		player = "b ";
	}else{player = "w ";}
	
	/*
		checks each case from the chosen coordinate, then if something that is not 
		equal to the symbol was found, it will enter the statement then iterate in the 
		direction it found the oppisite player's symbol until it reaches the current
		player to check if its a valid move, if it was valid, iterate again replacing symbols on the way
	*/

	//tried to restrict code from entering if statement on a specified edge
	// to avoid seg fault and yet failed
	if (player != array[x][y-1] && array[x][y-1] != ". "){
		//left
		//printf("left\n");

		varY = size - y;
		for(i=2;i<varY;i++){
			if(player == array[x][y-i]){
				for(j=1;j<size;j++){
					
					if(array[x][y-j] == ". "){
						return true;
						}
					array[x][y-j] = player;
				}
				
				return true;
			}
		}
		
	}if(player != array[x][y+1] && array[x][y+1] != ". "){
	//right
		//printf("right\n");
		varY = size - y;
		if (x == (size - 1)){}
		for(i=2;i<varY;i++){
			if(player == array[x][y+i]){
				for(j=1;j<size;j++){
					
					if(array[x][y+j] == ". "){
						return true;
						}
					array[x][y+j] = player;
				}
				
				return true;
			}
		}
	}if(player != array[x+1][y] && array[x+1][y] != ". "){
	//down
		//printf("down\n");
		varX = size - x;
		if (y == (size - 1)){printf("\n");
		}else{
		for(i=2;i<varX;i++){
			if(player == array[x+i][y]){
				for(j=1;j<size;j++){
					
					if(array[x+j][y] == ". "){
						return true;
						}
					array[x+j][y] = player;
				}
				
				return true;
			}
		}
		}
	}if(player != array[x-1][y] && array[x-1][y] != ". "){
	//up
		//printf("up\n");
		if (y == 0){printf("\n");
		}else{
		varX = size - x;
		for(i=2;i<varX;i++){
			if(player == array[x-i][y]){
				for(j=1;j<size;j++){
					
					if(array[x-j][y] == ". "){
						return true;
						}
					array[x-j][y] = player;
				}
				printf("found the ting ma dude\n");
				return true;
			}
		}
		}
	}if(player != array[x+1][y-1] && array[x+1][y-1] != ". "){
	//down-left
		//printf("d-left\n");
		if (y == (size - 1) || x == 0 ){printf("\n");
		}else{
		varX = size - x;
		for(i=2;i<varX;i++){
			if(player == array[x+i][y-i]){
				for(j=1;j<size;j++){
					
					if(array[x+j][y-j] == ". "){
						return true;
						}
					array[x+j][y-j] = player;
				}
				
				return true;
			}
		}
		}
	}if(player != array[x-1][y-1] && array[x-1][y-1] != ". "){
	//up-left
	//printf("u-left\n");
		varX = size - x;
		if (x == 0 || y == 0){printf("\n");
		}else{
		for(i=2;i<varX;i++){
			if(player == array[x-i][y-i]){
				for(j=1;j<size;j++){
					
					if(array[x-j][y-j] == ". "){
						return true;
						}
					array[x-j][y-j] = player;
				}
				
				return true;
			}
		}
		}
	}if(player != array[x+1][y+1] && array[x+1][y+1] != ". "){
	//down-right
	//printf("d-right\n");
		varX = size - x;
		if (x == (size - 1) || y == (size - 1)){printf("\n");
		}else{
		for(i=2;i<varX;i++){
			if(player == array[x+i][y+i]){
				for(j=1;j<size;j++){
					
					if(array[x+j][y+j] == ". "){
						return true;
						}
					array[x+j][y+j] = player;
				}
				
				return true;
			}
		}
		}
	}if(player != array[x-1][y+1] && array[x-1][y+1] != ". "){
	//up-right
	//printf("u-right\n");
			varX = size - x;
			if (y == 0 || x == (size - 1)){printf("\n");
		}else{
		for(i=2;i<varX;i++){
			if(player == array[x-i][y+i]){
				for(j=1;j<size;j++){
					
					if(array[x-j][y+j] == ". "){
						return true;
						}
					array[x-j][y+j] = player;
				}
				
				return true;
			}
		}
	}
	}else{return false;}
	
	
	
	
	return false;
	

}
void makeMovement(Board *board){

	//incomplete
	//logic is to keep getting choices and swap turns when choice is valid
	int playerTurn = 1;
	int size = board->size;
	char ***array = board->array;
	int x, y;
	bool isOver, isValid = false;
	while(!isOver){
		printBoard(board);
		printf("Player %d turn, input 2 numbers (0-%d) row col: ",playerTurn, size - 1);
		scanf("%d %d",&x,&y);
		  while(x < 0 || x > size - 1 || y < 0 || y > size - 1){
		printf("Player %d turn, input 2 numbers (0-%d) row col: ",playerTurn, size - 1);
		scanf("%d %d",&x,&y);
		  }
		isValid = validMovement(board, x , y, playerTurn);
		if (isValid){
			if (playerTurn == 1){
				array[x][y] = "b ";
				playerTurn = 2;
			}else{array[x][y] = "w ";playerTurn = 1;}
			
		}else{printf("invalid choice!\n");}
	}
	//when supposed to be done, so free the memory
	free(board);
}
int main(){

  int size;
  bool isOver = true;
  printf("Please enter the size of the board 4 - 16: ");
  scanf("%d",&size);
  while(size < 4 || size > 16){
	printf("Please enter the size of the board 4 - 16: ");
	scanf("%d",&size);
  }
	Board board;
	boardInit(size,&board);
	defaultBoard(&board);
	//printBoard(&board);
	makeMovement(&board);


  return 0;

}
