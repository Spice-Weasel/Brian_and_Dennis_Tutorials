/* reverse the characters in a char string */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

int main()
{
	char s1[SIZE];

	int len;

	char c;

	for(int i=0; (c=getchar())!='\n' && i < SIZE ; i++)
	{
		s1[i] = c;

		len = i;
	}

	for(int i=len; i>=0; i--)
	{
		putchar(s1[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;

}
