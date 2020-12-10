/*print words in input on each line*/

#include<stdio.h>
#include<stdlib.h>

#define YES	1
#define NO	0

int main()
{
	char c;
	char inword = NO;

	while((c=getchar())!='\n')
	{
		// Scan input for spaces, tabs or newlines
		if(c == ' ' || c == '\t' )
		{
			if(inword == YES)
			{
				printf("\n\r");
				inword = NO;
			}
		} else {
			putchar(c);
			inword = YES;
		}
	}
	putchar('\n');
	return EXIT_SUCCESS;
}
