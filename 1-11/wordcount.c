/* count word in input, where a word is a sequence of letters, numbers
and apostrophes, begining with a letter */

#include<stdio.h>
#include<stdlib.h>

#define YES	1
#define NO	0


/* FUNCTION DECLARATIONS */

int isletter(char c);
int isnum(char c);


int main()
{
	char inword, c;
	int wc = 0;

	while((c = getchar())!='\n')
	{
		if(isletter(c) && (inword == NO))
		{
			printf("Begin Word\n");
			inword = YES;
			wc++;

		} else if((c == '\'') || isnum(c) || isletter(c)) 
		{
			printf("In Word\n");
		} else
		{
			inword = NO;
		}
	}
	printf("Word Count = %d\n", wc);
	
	return EXIT_SUCCESS;
}



/* FUNCTION DEFINITIONS */

int isletter(char c)
{
	if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	{ 
		return YES;
	}
	return NO;
}

int isnum(char c)
{
	if((c >= 48) && (c <= 57))
	{
		return YES;
	}
	return NO;
}
