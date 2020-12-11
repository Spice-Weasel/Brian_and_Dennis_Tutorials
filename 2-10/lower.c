// Use expression to lower case of char instead of using an
// if statement

#include<stdio.h>

char lower(char c);

int main(void)
{
  char c;

  c = getchar();

  putchar(lower(c));
  putchar('\n');

  return 0;
}

char lower(char c)
{
  c = (c >= 65 && c <= 90 ) ? c + 32 : c;

  return c;
}
