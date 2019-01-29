//power.c


#include <stdio.h>
#include <math.h>
#include "power.h"

double power(double a, double b){

  double sum;
  sum = 0;
  
  if (b == 0){
    return 1;
  }
  if (b == 1){
    return a;
  }

  return (pow(a,b));
  
}

int main(){

  double a, b;
  printf("Whats the first number? ");
  scanf("%lf",&a);

  printf("Whats the second number? ");
  scanf("%lf",&b);
  printf("%lf\n",power(a,b));

  return 0;
  
}
