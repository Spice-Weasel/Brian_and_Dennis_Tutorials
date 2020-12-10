#include<stdio.h>
#include<stdlib.h>

int invert(int x, int p, int n);

int main(void)
{
  int some_value = 0b10000111;

  printf("inverted value = %d\n", invert(some_value, 2, 4));

  return EXIT_SUCCESS;
}

int invert(int x, int p, int n)
{
  int masked_value = 1;
  int lower_bits = 1;
  int inverted_value ;

  // Create LSB to end of bits mask
  for(int i=0; i<p+n; i++)
  {
    masked_value = (masked_value << 1) + 1;
  }

  // Create mask from LSB to start of inversion
  for(int i=0; i<p; i++)
  {
    lower_bits = (lower_bits << 1) + 1;
  }

  // XOR Operation on both masks, leaving middle of mask high
  masked_value = masked_value ^ lower_bits;

  // Set middle bits equal to inverted bits of x
  inverted_value = (~x & masked_value);

  // Set other bits equal to x
  inverted_value |= (x & ~masked_value);

  return inverted_value;
}
