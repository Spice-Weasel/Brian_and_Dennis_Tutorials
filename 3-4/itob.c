#include<stdio.h>

#define MAX 1000

char s[MAX];

void itoh(int n, char* s);
void itob(unsigned n, char* s);
void reverse(char* s);


int main(void)
{
  itoh(-2147483648, s);
  puts(s);
}

void itob(unsigned n, char* s)
{
  int i;

  i = 0;

  do
  {
    s[i++] = n % 2 + '0';
  } while(((n /= 2) > 0));

  s[i] = '\0';

  reverse(s);
}

void itoh(int n, char* s)
{
  int i, sign;

  i = 0;

  if((sign = n) < 0)
  {
    n = (~n);

    s[i++] = n % 16 + '0' + 1;
  }

  while((n /= 16) > 0)
  {
    s[i++] = n % 16 + '0';
  }

  if(sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);

  // Replace ascii codes over 57 with A-F
  for(int i=0; s[i]!='\0'; i++)
  {
    if(s[i] > 57)
    {
      s[i] += 7;
    }
  }
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
