#include<stdio.h>
#include<stdlib.h>

#define MAX 100


double atof2(char* s);

char s[MAX];


int main(void)
{
  double value;


  fgets(s, MAX, stdin);

  value = atof2(s);

  printf("the value is %f\n", value);

}

double atof2(char* s)
{
  double val, power, pwr, multiplier;
  int i;
  int sign = 1;
  int exponent = 0;
  int power_sign = 0;

  for(i = 0; s[i]==' '|| s[i]=='\n' || s[i]=='\t'; i++);

  // First sign for floating point numer
  if(s[i]=='+'||s[i]=='-')
  {
    sign = (s[i++]=='+') ? 1 : -1;
  }

  // Index through any numbers before the decimal point
  for(val = 0; s[i]>='0' && s[i] <= '9'; i++)
  {
    val = 10 * val + s[i] - '0';
  }

  // Check whether there is a decimal point
  if(s[i] == '.')
  {
    i++;
  }

  // This is skipped if there is no decimal point
  // this gets the value of the fractional portion
  // of the number.
  for(power = 1; s[i] >= '0' && s[i] <= '9'; i++)
  {
    val = 10 * val + s[i] - '0';
    power *= 10;
  }

  // optionally seach for the exponent character
  if(s[i]== 'e'||'E')
  {
    i++;
  }

  if(s[i]=='-')
  {
    power_sign = 1;
    i++;
  } else if (s[i]=='+')
  {
    power_sign = 0;
    i++;
  }

  // get the exponent sign there
  for(exponent = 0; s[i] >= '0' && s[i] <= '9'; i++)
  {
    exponent = 10 * exponent + s[i] - '0';
  }

  // Get exponent multipler here
  if(power_sign)
  {
    multiplier = 0.1;
  } else
  {
    multiplier = 10;
  }

  pwr = 1;

  for(int i = 1; i<=exponent; i++)
  {
    pwr *= multiplier;
  }

  printf("The exponent is %f\n", pwr);

  return ((sign * val / power)*pwr);
}
