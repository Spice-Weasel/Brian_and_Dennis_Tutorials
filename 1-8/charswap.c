/* replace tabs wit >, backspace, -*/

#include<stdio.h>
#include<stdlib.h>


int main()
{	
	char c;

	while((c=getchar())!=EOF)
	{
		if(c=='\t')
		{
		printf("\u2192");
		}
		else if(c=='\b')
		{
		printf("\u2190");
		}
	}
	return EXIT_SUCCESS;
}
