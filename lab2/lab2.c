//lab2.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COL 4
#define ROW 3

bool arrayEqual(int a[ROW][COL], int b[ROW][COL],int m,int n){

  int i, j;
  for (i=0;i < m; ++i){
    for(j=0; j < n; ++j){
      if (a[i][j] != b[i][j]){
	printf("false\n");
	return false;
      }
    }

  }

  printf("true\n");
  return true;
  
}


int main(){
  //static  
  int a[ROW][COL] = {
    {1,2,3,4},
    {30,80,61,63},
    {13,55,60,33},
  };

  int b[ROW][COL] = {
    {1,2,3,4},
    {30,80,61,63},
    {13,55,60,33},
  };

  arrayEqual(a, b, ROW, COL);
  return 0;
}
