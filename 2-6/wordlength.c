#include<stdio.h>
#include<stdlib.h>


int main(void)
{

  // ~n = -(n-1)

  char x = 1;
  char tmp = 0;
  for(int i=0; x>tmp; i++)
  {

    printf("index = %d\t", i);
    tmp = x;
    x = x<<1;
  }
  return EXIT_SUCCESS;
}
