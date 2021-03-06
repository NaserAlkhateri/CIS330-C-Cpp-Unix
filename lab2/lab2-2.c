//lab2 part2

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ROW 2
#define COL 3


bool arrayEqual(int *a[ROW][COL], int *b[ROW][COL], int m, int n)
{
  int i,j;
  for (i=0; i < m - 1; i++){
    for (j=0; j < n - 1; j++){
      if (*a[i][j] != *b[i][j]){
	printf("false\n");
	return false;
      }
    }
  }
  printf("true\n");
  return true;
}

int main()
{
    int** a2;
    int** b2;
    int i,j;
    a2 = (int *) malloc ( ROW * sizeof(int *) );
    b2 = (int *) malloc ( ROW * sizeof(int *) );
    for (i = 0; i < ROW; i++) {
      a2[i] = (int *) malloc ( COL * sizeof(int) );
      b2[i] = (int *) malloc ( COL * sizeof(int) );
      memset(a2[i], 0, COL * sizeof(int));
      memset(b2[i], 0, COL * sizeof(int));
    }


    arrayEqual(a2, b2, ROW, COL);

    for (i=0; i < ROW; i++){
	
	int* curr = a2[i];
	int* curr2 = b2[i];
	free(curr);
	free(curr2);
    }

    free(a2);
    free(b2);
    
    return 0;
}
