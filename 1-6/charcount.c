/* A program to count tabs, newlines, and blanks */

#include<stdio.h>
#include<stdlib.h>


int main()
{
	int tabs, nl, blanks;	
	char c;	

	tabs=0; nl=0; blanks=0;

	while((c = getchar()) != EOF)
	{
		if(c=='\t')
		{
		tabs++;
		}
		else if(c=='\n')
		{
		nl++;
		}
		else if(c==' ')
		{
		blanks++;
		}
	printf("tabs = %d\n", tabs);
	printf("newline = %d\n", nl);
	printf("blanks = %d\n", blanks);
	}

	return EXIT_SUCCESS;
}
