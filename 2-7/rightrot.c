
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int places_to_rotate = 1;
  int some_value = 8;

  some_value = some_value >> places_to_rotate;

  printf("%d\n", some_value);

  return EXIT_SUCCESS;
}
