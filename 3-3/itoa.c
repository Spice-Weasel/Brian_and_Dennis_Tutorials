#include<stdio.h>

#define MAX 100

char s[MAX];

void itoa(int n, char* s);
void reverse(char* s);


int main(void)
{
  itoa(-2147483648, s);
  //itoa(-1, s);

  puts(s);
}

void itoa(int n, char* s)
{
  int i, sign;

  i = 0;

  //if negative number then find 1's compliment and get "LSB char"
  if((sign = n) < 0)
  {
    n = (~n);

    // 1's compliment adds one so use '1' char to make this up
    s[i++] = n % 10 +'1';
  }

  while((n /= 10) > 0)
  {
    s[i++] = n % 10 + '0';
  }

  if(sign < 0)
  {
    s[i++] = '-';
  }
  s[i] = '\0';

  reverse(s);
}


void reverse(char* s)
{
  int i, j;
  char temp[MAX];

  // Get string length i
  puts("getting string length!");

  for(i=0; s[i]!='\0'; i++)
  {
    putchar(s[i]);
  }

  // Copy to reverse to temporary string

  puts("\nreversing to temp string!");
  for(j=0; j<=i; j++)
  {
    temp[j] = s[i-(j+1)];

    putchar(temp[j]);
  }

  temp[j] = '\0';

  // Copy reversed string back to original

  puts("\nCopying reversed string! ");
  for(i=0; temp[i]!='\0'; i++)
  {
    s[i] = temp[i];

    putchar(s[i]);
  }
  puts("\nFunction finished!");
}
