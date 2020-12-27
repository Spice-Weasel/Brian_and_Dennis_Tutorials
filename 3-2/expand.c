#include<stdio.h>

#define MAX 1000

void expand(char *s1, char *s2);

int main(void)
{
  char s1[MAX];
  char s2[MAX];

  fgets(s1, MAX, stdin);

  expand(s1, s2);

  return 0;
}

void expand(char *s1, char *s2)
{
  int i = 0;
  int j = 0;
  char c, cn;

  printf("%d: %d\n", i, s1[i]);
  // skip any leading whitespace
  for(; s1[i]==' '|| s1[i]=='\t' || s1[i]=='\n'; i++)
  {
    ;
  }

  // Get first char before expression up to hyphen
  for(; s1[i]!='-'; i++)
  {
    ;
  }

  // assign start & end char, skippin the hyphen.
  c = s1[i-1];
  cn = s1[i+1];

  // Iterate through chars in c-cn
  for(; c<=cn; c++, j++)
  {
    s2[j] = c;
  }

  printf("%d\n", i);

  puts(s2);

}
