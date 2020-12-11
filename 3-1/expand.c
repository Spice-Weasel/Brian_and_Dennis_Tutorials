// Use a switch case to convert newline and tab characters to visible chars


#include<stdio.h>
#include<stdlib.h>

#define MAX 100



void expand(char* s, char* t);

int main(void)
{
  char s[MAX];
  char t[MAX];

  //Get input string from stdin
  fgets(s, MAX, stdin);

  expand(s, t);

  puts(t);

}

void expand(char* s, char* t)
{
  int j = 0;
  char c;

  for(int i = 0; s[i]!='\0'; i++)
  {
    switch (c = s[i]) {
      case '\n':
        t[i+j]='\\';
        j++;
        t[i+j]='n';
        break;
      case '\t':
        t[i+j]='\\';
        j++;
        t[i+j]='t';
        break;
      default:
        t[i+j]= c;
        break;
    }
  }
}
