/*
Code to test the itoa function.
This is my solultion to Exercise 3-3 of "The C Programming Language"
by Brian W. Kernighan and Dennis M. Ritchie.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define LOWLIMIT -2147483648
#define HIGHLIMIT 2147483647

char s[MAX];

// Function declaration
int itoa(int n, int width, char* s);
void reverse(char* s);
void pad(char* s, int width);


int main(void)
{
  int width = 20;
  // Convert an integer to a string representation
  for(int i = LOWLIMIT; i <= HIGHLIMIT; i++)
  {
    itoa(i, width, s);

    puts(s);
  }

  return EXIT_SUCCESS;
}


// Integer argument is converted to a string representation
int itoa(int n, int width, char* s)
{
  int i, sign;
  int max = 1;
  int temp = 1;

  // Left shift to get max possible size for input int
  for(i=0 ; temp>0; i++)
  {
    max = temp;
    temp = (temp << 1) + 1;
  }

  // Check if input is greater in magnitude than max value for positive
  // integer. If so, then return max negative.
  if(((sign = n) < 0) && ((-max) > n))
  {
    sprintf(s, "-2147483648");

    return EXIT_SUCCESS;

  } else if((sign = n) < 0)
  {
    n = -n;
  }

  i = 0;

  // Find remainder of division by 10 and add to ASCII code offset for
  // numeric symbols.
  // While there is still another order of magnitude, repeat the loop.
  do
  {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);

  // If the number was negative, then add a hyphen to the array.
  if(sign < 0)
  {
    s[i++] = '-';
  }
  // Add end of string character.
  s[i] = '\0';

  pad(s, width);

  reverse(s);

  return EXIT_SUCCESS;
}

// Reverse a string of input chars
void reverse(char* s)
{
  int i, j;
  char temp[MAX];

  // Get length of input string
  for(i=0; s[i]!='\0'; i++);

  // Copy to reverse to temporary string
  for(j=0; j<=i; j++)
  {
    temp[j] = s[i-(j+1)];
  }

  temp[j] = '\0';

  // Copy reversed string back to original
  for(i=0; temp[i]!='\0'; i++)
  {
    s[i] = temp[i];
  }
}

void pad(char* s, int width)
{
  int i;

  // Get length up to end of string char
  for(i = 0; s[i]!='\0' && i < MAX; i++);

  for(; i<MAX && i<width; i++)
  {
    s[i] = '!';
  }

  s[i] = '\0';
}
