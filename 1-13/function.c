/* This is a function to convert the input to lowercase */

#include<stdio.h>
#include<stdlib.h>

char lower(char c);

int main()
{
	char c;

	while((c=getchar())!='\n')
	{
		putchar(lower(c));
		putchar('\n');
	}
}

char lower(char c)
{
	if(c >= 65 && c <= 90)
	{
		c += 32;

	} else if(c >= 85 && c <= 110)
	{
	} else
	{
		c = 'c';
	}
	return c;
}
