//testClock.c


#include "clock.h"
#include <stdio.h>
int main(){

  time_t now;
  time(&now);
  ClockType clock;
  initClock(&clock);
  printf("%d:%d:%d\n",clock.hour,clock.min, clock.sec);
  printClock(time(&now), &clock);




  return 0;

}
