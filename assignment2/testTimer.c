//testTimer.c

#include <stdio.h>
#include "timer.h"


int main(){

  int min, sec;
  ClockType clock;
  printf("How long should the timer run (MM:SS)? ");
  scanf("%d:%d",&min,&sec);
  initTimer(&clock, min, sec);
  runTimer2(&clock);


  return 0;

}
