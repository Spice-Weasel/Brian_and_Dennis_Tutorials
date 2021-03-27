#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// getch checks whether the buffer size is greater than 0.
// if buffer size is greater than 0 then return a char else
// a null char is returned.
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


// ungetch puts chars onto the buffer if there is space in the buffer.
int ungetch(int c)
{
  if(bufp > BUFSIZE)
  {
    printf("ungetc too many characters\n");

    return EXIT_FAILURE;
  } else if(c==EOF){
    return EXIT_FAILURE;
  } else {
    buf[bufp++] = c;

    return EXIT_SUCCESS;
  }
}
