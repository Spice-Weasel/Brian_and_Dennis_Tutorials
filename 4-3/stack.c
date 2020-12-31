#include<stdio.h>
#include<stdlib.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void clear();

double pop()
{
  puts("Pop!");
  if(sp > 0)
  {
    return(val[--sp]);
  } else {
    printf("error: stack full\n");
    clear();
    return 0;
  }
}

double push(double f)
{
  puts("Push!");
  if(sp < MAXVAL)
  {
    return(val[sp++] = f);
  } else {
    printf("error: stack full\n");
    clear();
    return 0;
  }
}

void clear()
{
  puts("Clear");
  sp = 0;
}
