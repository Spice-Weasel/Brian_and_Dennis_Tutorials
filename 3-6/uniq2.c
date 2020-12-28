#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

char line[MAX];
char copy[MAX];

int gtline(char* line);
void copyline(char* line, char* copy);
int isidentical(char* line, char* copy);


int main(void)
{
  int linecount = 0;
  int charcount = 0;
  int match = 0;

  while(charcount = gtline(line))
  {
    match = isidentical(line, copy);

    if(!match)
    {
      puts(line);
    }

    copyline(line, copy);

    linecount++;
  }
}

int gtline(char* line)
{
  char c;
  int i = 0;

  // Clear line from last time
  for(int j = 0; j<=MAX; j++)
  {
    line[j] = '\0';
  }

  while((c = getchar())!='\n')
  {
    line[i] = c;

    i++;
  }

  return i;
}

void copyline(char* line, char* copy)
{
  for(int j = 0; j<=MAX; j++)
  {
    copy[j] = '\0';
  }

  for(int j = 0; j<=MAX; j++)
  {
    copy[j] = line[j];
  }
}

// check whether the lines match
int isidentical(char* line1, char* line2)
{
  int match = 1;

  for(int i = 0; line1[i] != '\0'; i++)
  {
    if(line1[i] != line2[i])
    {
      match = 0;

      break;
    }
  }
  return match;
}
