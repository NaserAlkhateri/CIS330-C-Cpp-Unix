//smarTimer.c
#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>




//compile using:
// gcc -std=c11 -o smartTimer.exe smartTimer.c  -lncurses 

void initTimer(ClockType *clock, int minutes, int seconds){
  //place values in struct
  clock->min = minutes;
  clock->sec = seconds;
}


void runTimer(){

  
  WINDOW * mainwin;
  ClockType *clock;
  int mn,sc,mn0 ,sc0, mn1, sc1;

  if ( (mainwin = initscr()) == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }

  //get time and seperate each individual number
  mn = clock->min;
  sc = clock->sec;
  mn1 = mn / 10;
  sc1 = sc / 10;
  mn0 = mn % 10;
  sc0 = sc % 10;

   char numbers[12][12][12] =
     {{" @@@ ", "  @  ", " @@@ ",  "@@@@@", "   @ ", "@@@@@", " @@@ ", "@@@@@", " @@@ ", " @@@ ", "   "},
      {"@   @", " @@  ", "@   @",  "    @", "  @@ ", "@    ", "@   @", "    @", "@   @", "@   @", "   "},
      {"@   @", "  @  ", "    @",  "    @", " @ @ ", "@    ", "@    ", "   @ ", "@   @", "@   @", " @ "},
      {"@   @", "  @  ", "    @",  "@@@@@", "@@@@@", "@@@@ ", "@@@@ ", "  @  ", " @@@ ", "@   @", "   "},
      {"@   @", "  @  ", "   @ ",  "    @", "   @ ", "    @", "@   @", "  @  ", "@   @", " @@@@", "   "},
      {"@   @", "  @  ", "  @  ",  "    @", "   @ ", "    @", "@   @", "  @  ", "@   @", "    @", " @ "},
      {"@   @", "  @  ", " @   ",  "    @", "   @ ", "@   @", "@   @", "  @  ", "@   @", "@   @", "   "},
      {" @@@ ", " @@@ ","@@@@@" ,  "@@@@@", "   @ ", " @@@ ", " @@@ ", "  @  ", " @@@ ", " @@@ ", "   "}};

   //print start time
   int i;
   for(i = 0; i < 10; i++){
     printw("%s %s %s %s %s",numbers[i][mn1],numbers[i][mn0],numbers[i][10],
	    numbers[i][sc1],numbers[i][sc0]);
     printw("\n");

   }
   refresh();
   erase();
   //loop until reachs 00:00
   while(mn != 0  || sc != 0){
     //if seconds reach 0 while minute is not 0,
     //set sec to 59 and take a min off
     if(sc == 0){
       sc = 59;

       mn--;
     }
     //take a second off and update all values
     sc--;
     mn1 = mn / 10;
     sc1 = sc / 10;
     mn0 = mn % 10;
     sc0 = sc % 10;
     //wait 1 second before printing
     sleep(1);
     for(i = 0; i < 10; i++){
       printw("%s %s %s %s %s",numbers[i][mn1],numbers[i][mn0],numbers[i][10],
	      numbers[i][sc1],numbers[i][sc0]);
       printw("\n");
     }
     refresh();
     erase();
   }
   sleep(2);//so that 00:00 could be seen too
   delwin(mainwin);
   endwin();
   refresh();
  
}

void cleanTimer(ClockType  *clock){}

int main(){

  int min, sec;
  ClockType clock;
  printf("How long should the timer run (MM:SS)? ");
  scanf("%d:%d",&min,&sec);
  initTimer(&clock, min, sec);
  runTimer();

  return 0;
}
