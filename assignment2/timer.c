//timer.c
#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void initTimer(ClockType *clock, int minutes, int seconds){

  clock->min = minutes;
  clock->sec = seconds;


}

void runTimer(){

  int min = 2;
  int sec = 13;
  printf("%.2d:%.2d\n", min,sec);
  while(min != 0  || sec != 0){
    if(sec == 0){
      sec = 59;

      min--;
    }
    sec--;
    sleep(1);
    printf("%.2d:%.2d\n", min,sec);
  }
  

}

void runTimer2(ClockType *clock){


  int mn,sc,mn0 ,sc0, mn1, sc1;

  mn = clock->min;
  sc = clock->sec;
  mn1 = mn / 10;
  sc1 = sc / 10;
  mn0 = mn % 10;
  sc0 = sc % 10;

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
     printf("%s %s %s %s %s",numbers[i][mn1],numbers[i][mn0],numbers[i][10],
	    numbers[i][sc1],numbers[i][sc0]);
     printf("\n");

   }
   while(mn != 0  || sc != 0){
     if(sc == 0){
       sc = 59;

       mn--;
     }
     sc--;
     mn1 = mn / 10;
     sc1 = sc / 10;
     mn0 = mn % 10;
     sc0 = sc % 10;
     sleep(1);
     for(i = 0; i < 10; i++){
       printf("%s %s %s %s %s",numbers[i][mn1],numbers[i][mn0],numbers[i][10],
	      numbers[i][sc1],numbers[i][sc0]);
       printf("\n");

     }
   }

  

}

void cleanTimer(ClockType  *clock){}
