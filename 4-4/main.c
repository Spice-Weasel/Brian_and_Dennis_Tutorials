#include<stdio.h>
#include<stdlib.h>
#include"buffer.h"

void ungets(char* s);

int main(void)
{
  char c;
  char s[10];

  int i;

  for(i=0; i<10; i++)
  {
    s[i] = i + '0';
  }
  s[++i] = '\0';


  ungetch('\n');
  ungetch('o');
  ungetch('l');
  ungetch('l');
  ungetch('e');
  ungetch('h');

  ungets(s);

  while((c = getch())!='\0')
  {
    putchar(c);
  }
}

// Put a string into the buffer
void ungets(char* s)
{
  for(int i=0; s[i]!='\0'; i++)
  {
    if(ungetch(s[i]) == EXIT_FAILURE)
    {
      break;
    }
  }
}
