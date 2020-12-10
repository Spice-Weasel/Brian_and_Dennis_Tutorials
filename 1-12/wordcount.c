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
	int wc, lc;
	int wordlengths[20];

	wc = lc = 0;
	
	for(int i = 0; i < 20; i++)
		wordlengths[i] = 0;

	while((c = getchar())!='\n')
	{
		if(isletter(c) && (inword == NO))
		{
			// Word begins
			inword = YES;
			lc++;
			wc++;

		} else if((c == '\'') || isnum(c) || isletter(c)) 
		{
			// Word continues;
			lc++;

		} else if((inword == YES) && !(isletter(c)||isnum(c)) && (c != '\''))
		{	
			// Word ends
			wordlengths[lc]++;
			lc = 0;
			inword = NO;
		} else
		{
			lc = 0;
		}
	}
	printf("Word Count = %d\n", wc);


	
	for(int i = 0; i <= 19; i++)
	{
		printf("Length %d\t=\t %d\t", i, wordlengths[i]);
		for(int j = 1; j <= wordlengths[i]; j++)
		{
			printf("#");
		}
		putchar('\n');
	}

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
