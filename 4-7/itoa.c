#include<stdio.h>

void itoa(int n, char* s2);

int main(void)
{
 int number;
 char string[10];

 puts("Enter an integer to convert to a string: ");
 
 scanf("%d", &number);

 itoa(number, string);

 printf("String = %s\n", string);
}


void itoa(int n, char* s2)
{
 int k = 0;
 int t, t_old, last_no;
 char s[10];

 t_old = n;

 for(int i=0; t>=1; i++)
 {
  int pwr = 1;
  char c;

  // Get next power of 10 here
  for(int j=0; j<=i; j++)
  {
      pwr = 10*pwr;
  }
  
  // divide number by power of 10
  t = n / pwr;

  // get least significant decimal position 
  last_no = t_old - (t*10);

  // last_no SHOULD be less than 10, store this in a char array with ascii code offset.
  if(last_no < 10)
  {
      int j;

      c = last_no + 48;

      s[k++] = c;
  }
  t_old = t;
 }

 // add null to end of string here
 s[k--] = '\0';

 // reverse the string here as it is stored in s backwards. Index through s
 // until a null char is found.
 for(int i=0; s[i]!='\0'; i++)
 {   
     s2[k-i] = s[i];
 }
 
 // add null char to the end of the string here.
 s2[++k] = '\0';
}
