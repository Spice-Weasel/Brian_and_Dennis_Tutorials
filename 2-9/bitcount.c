#include<stdio.h>

int bitcount(int n);

int main(void)
{
  int number = 21309;
  int result = 0;

  result = bitcount(number);

  printf("Number of 1 bits in number = %d\n", result);

  return 0;
}

int bitcount(int n)
{
  int bits;

  for(bits = 0; n != 0; bits++)
  {
    n = n & (n-1);
  }
  return bits;
}
