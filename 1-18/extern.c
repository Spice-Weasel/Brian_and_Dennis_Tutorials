/* use of external variables */

#include<stdio.h>
#include<stdlib.h>

#define	MAXLINE	1000

char line[MAXLINE];
char save[MAXLINE];
int max;

int gtline(void);
void copy(void);

int main(void)
{
	int len;
	extern int max;
	extern char save[];

	max = 0;
	while((len = gtline()) > 0)
	{
		if(len > max)
		{
			max = len;
			copy();
		}
		if(max > 0)
		{
			printf("%s", save);
		}
	}
}

int gtline()
{
	int c, i;
	extern char line[];

	c = getchar();
	
	for(i = 0; i < MAXLINE - 1 && c!= EOF && c!= '\n'; i++)
	{
		line[i] = c;
		c=getchar();
	}
	if(c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

void copy()
{
	int i;
	extern char line[], save[];

	i = 0;
	while((save[i] = line[i]) != '\0')
	{
		i++;
	}
}
