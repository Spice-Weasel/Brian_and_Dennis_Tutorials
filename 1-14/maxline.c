#include<stdio.h>

#define MAXLINE 1000

int gtline(char *s, int lim);
void copy(char *s1, char *s2);

int main ()
{
	int len;
	int max;
	char line[MAXLINE];
	char save[MAXLINE];

	max = 0;
	while((len=(gtline(line, MAXLINE))) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(line, save);
		}
	
		if(max > 0) // there was a line
		{
			printf("%s", save);
		}
	}
}


int gtline(char *s, int lim)
{
	int c, i;

	for(i = 0; i < (lim - 1) &&  (c = getchar())!=EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	return i;
}

void copy(char *s1, char *s2)
{
	int i;

	i = 0;
	
	while((s2[i] = s1[i]) != '\0')
	{
		i++;
	}
}
