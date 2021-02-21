#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

char getch()
{
  char c;

  if(bufp > 0)
  {
    c = buf[--bufp];
  } else {
    c = '\0';
  }
  return c;
}

int ungetch(int c)
{
  if(bufp > BUFSIZE)
  {
    printf("ungetc too many characters\n");

    return EXIT_FAILURE;
  } else {
    buf[bufp++] = c;

    return EXIT_SUCCESS;
  }
}
