#include<stdio.h>
#include<stdlib.h>
#include"buffer.h"

int ungets(char* s);

int main(void)
{
  char c;
  char s[12];

  int i, d;

  for(i=0; i<10; i++)
  {
    s[i] = i + '0';
  }
  s[++i] = 'a';
  s[++i] = '\t';
  s[++i] = '\0';

  d = ungets(s);

  printf("number of chars put on buffer: %d\n", d);

  while((c = getch())!='\0')
  {
    putchar(c);
  }
}

// Put a string into the buffer
int ungets(char* s)
{
 int i;

  for(i=0; s[i]!='\0'; i++)
  {
    if(ungetch(s[i]) == EXIT_FAILURE)
    {
      break;
    }
  }
  return i;
}
