//reversi.h

#ifndef REVERSI_H_
#define REVERSI_H_


typedef struct {
	int size;
	char ***array;
} Board;
typedef enum {b,w} Player;

void makeMovement(Board *board);
bool validMovement(Board *board,int x, int y, int playerNum);
void defaultBoard(Board *board);
void printBoard(Board *board);
#endif