#include<stdio.h>
#include<stdlib.h>


uint getbits(uint x, uint p, uint n);

int main(void)
{
  uint x, p, n;

  x=0b00001000;
  p=4;
  n=1;

  printf("Return value: %d\n", getbits(x,p,n));
}

uint getbits(uint x, uint p, uint n)
{
  return ((x >> (7-p)) & ~(~0 << (7-n)));
}
