#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 100

int rindex2(char* s, char c);


int main(void)
{
  char s[MAXLINE];
  char c;
  int position;

  puts("Enter string to search: ");
  fgets(s, MAXLINE, stdin);

  puts("Enter character to find: ");
  c = getchar();

  position = rindex2(s, c);

  if(position > -1)
  {
    printf("Character found at position %d\n", position);

    return EXIT_SUCCESS;
  } else {

    puts("Character not found.");
  }
  return EXIT_FAILURE;
}

int rindex2(char* s, char c)
{
  int position = -1;

  for(int i = 0; s[i]!='\0'; i++)
  {
    if(c == s[i])
    {
      position = i;
    }
  }


  return position;
}
