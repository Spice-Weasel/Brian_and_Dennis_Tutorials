/* remove tabs and replace with blanks to the next tab stop */

#include<stdio.h>
#include<stdlib.h>

#define	SPACES	4
#define MAX	200


char line[MAX];

int gtline(void);

int main(void)
{
	extern char line[];
	int len;	

	len = gtline();

	printf("LINE: %s, LEN: %d\n", line, len);

	return EXIT_SUCCESS;
}



int gtline(void)
{
	int i;
	extern char line[];

	while((line[i]=getchar())!='\n')
	{		
		if(line[i]=='\t')
		{
			for(int n = 0; n < SPACES; n++)
			{
				i++;
				line[i] = ' ';
			}
		}
		i++;
	}

	return i;
}	
