#include<stdio.h>

// TODO: Fix the processing of the exponent so that e & E are used
// as scientific notation, currently they are just treated as a decimal
// place.

void getfloat(float *pn);

int main(void)
{
    float n = 0;
    float *pn;

    pn = &n;

    getfloat(pn);

    printf("Number = %f\n", *pn);
}

void getfloat(float *pn)
{
    int c;
    int mantissa_sign = 1;
    int exp_sign = 1;
    int mantissa = 0;
    int exponent = 0;
    int divisor = 1;

    // Skip whitespace at the start of number
    while((c=getchar())== ' ' || c == '\n' || c == '\t')
    {
        ;
    }

    // Record the sign of the number here
    if(c == '+' || c == '-')
    {
        if(c == '-')
        {
            mantissa_sign = -1;
        }
    } else {
    // push last read character back onto buffer as it is not whitespace
    // and needs to be considered.
        ungetc(c, stdin);
    }

    // get the number here, this will be the mantissa.
    while((c=getchar()) >= 48 && c <= 57)
    {
        mantissa *= 10;
        mantissa += (c - 48);
    }

    printf("Mantissa = %d\n", mantissa);

    if(c == 'e' || c == 'E')
    {
        puts("Getting decimal");

    } else if(c == '.')
    {
        exp_sign = -1;

    } else {
        ungetc(c, stdin);
        return;
    }

    // get the fractional portion here
    if((c=getchar()) == '+' || c == '-')
    {
        if(c == '-')
        {
            exp_sign = -1;
        }
    } else 
    {
        ungetc(c, stdin);
    }

    // build the "decimel" part of the number here and create a divisor/multiplier
    while((c=getchar()) != '\n')
    {
        divisor *= 10;
        exponent *= 10;
        exponent += (c - 48);   
    }

    if(exp_sign != 1)
    {
        *pn = (mantissa_sign * mantissa) - (exponent * 1.0 / divisor);
    } else {
        *pn = ((mantissa_sign * mantissa) + (exponent)) * divisor;
    }

    printf("%d, %d, %d, %d, %d\n", mantissa_sign, mantissa, exp_sign, exponent, divisor);

    return;
}