/* Copy input to output, replace each string of one or more blanks */
/* with a single blank */

#include<stdio.h>
#include<stdlib.h>

int main()
{	
	char c;
	int sp =0;

	while((c=getchar())!=EOF)
	{
		if(c==' ')
		{
			sp++;
		}
		else if(sp!=0)
		{
			putchar(' ');
			putchar(c);
			sp = 0;
		}
		else
		{
		putchar(c);
		}
	}
}
