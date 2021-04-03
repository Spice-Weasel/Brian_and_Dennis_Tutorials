#include<stdio.h>

#define SWAP(a, b) swap_ints(a, b)

void swap_ints(int *x, int *y);

int main(void)
{
    int a = 5;
    int b = 36;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf("Value at x = %d, value at y = %d\n", *pa, *pb);

    SWAP(pa, pb);

    printf("Value at x = %d, value at y = %d\n", *pa, *pb);
}

// This function is used in the function-like macro swap
void swap_ints(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;

    return;
}