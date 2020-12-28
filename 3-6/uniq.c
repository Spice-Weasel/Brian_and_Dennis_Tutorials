#include<stdio.h>
#include<stdlib.h>

#define MAX 100

char s[MAX];
char uniq[MAX];

int count_char(char* s, char c);
int add_char(char* s, char c);

int main(void)
{
  // initialize uniq array to null
  for(int i=0;i<MAX; i++)
  {
    uniq[i] = '\0';
  }

  // get input string from the terminal
  fgets(s, MAX, stdin);


  for(int i = 0; i<MAX; i++)
  {
     if(count_char(uniq, s[i])==EXIT_SUCCESS)
     {
       add_char(uniq, s[i]);
     }
     continue;
  }

  puts(uniq);
}

int count_char(char* s, char c)
{
  int count = 0;
  int found = 0;

  for(int i = 0; s[i]!='\0'; i++)
  {
    if(s[i]==c)
    {
      found = 1;

      break;
    }
  }

  return found;
}

int add_char(char* s, char c)
{
  int i = 0;

  for(i = 0; s[i]!='\0' && i < MAX; i++);

  if(i < MAX)
  {
    s[i] = c;

    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
