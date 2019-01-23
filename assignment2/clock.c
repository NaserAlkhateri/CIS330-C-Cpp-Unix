#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clock.h"

void initClock( ClockType *clock){
  
  int hours,mins,secs;
  time_t now;
  time(&now);
  printf("today is : %s", ctime(&now));
  struct tm *local = localtime(&now);
  hours = local->tm_hour;
  mins = local->tm_min;
  secs = local->tm_sec;
  clock->hour = hours;
  clock->min = mins;
  clock->sec = secs;
}
void printClock(const time_t cur_time, const ClockType *clock){


  int hr, mn ,sc, hr1, mn1, sc1;
  hr = clock->hour;
  mn = clock->min;
  sc = clock->sec;
  hr1 = hr / 10;
  mn1 = mn / 10;
  sc1 = sc / 10;
  hr = hr % 10;
  mn = mn % 10;
  sc = sc % 10;
  char numbers[12][12][12] =
    {{" @@@ ", "  @ ", " @@@ ",  "@@@@@", "   @ ", "@@@@@", " @@@ ", "@@@@@", " @@@ ", " @@@ ", "   "},
     {"@   @", " @@ ", "@   @",  "    @", "  @@ ", "@    ", "@   @", "    @", "@   @", "@   @", "   "},
     {"@   @", "  @ ", "    @",  "    @", " @ @ ", "@    ", "@    ", "   @ ", "@   @", "@   @", " @ "},
     {"@   @", "  @ ", "    @",  "@@@@@", "@@@@@", "@@@@ ", "@@@@ ", "  @  ", " @@@ ", "@   @", "   "},
     {"@   @", "  @ ", "   @ ",  "    @", "   @ ", "    @", "@   @", "  @  ", "@   @", " @@@@", "   "},
     {"@   @", "  @ ", "  @  ",  "    @", "   @ ", "    @", "@   @", "  @  ", "@   @", "    @", " @ "},
     {"@   @", "  @ ", " @   ",  "    @", "   @ ", "@   @", "@   @", "  @  ", "@   @", "@   @", "   "},
     {" @@@ " ," @@@ ","@@@@@",  "@@@@@", "  @  ", " @@@ ", " @@@ ", "  @  ", " @@@ ", " @@@ ", "   "}};

  int i;
  
  for(i = 0; i < 10; i++){

    printf("%s %s %s %s %s %s %s %s", numbers[i][hr1], numbers[i][hr],
	   numbers[i][10], numbers[i][mn1],numbers[i][mn],
	   numbers[i][10],  numbers[i][sc1],numbers[i][sc]);
    printf("\n");
  }
  
}
void cleanClock( ClockType *clock){}

