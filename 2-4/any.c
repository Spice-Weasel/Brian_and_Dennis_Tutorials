#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

int any(char s1[], char s2[]);

int main(void)
{
	char s1[MAXSIZE];
	char s2[MAXSIZE];

	int pos;

	puts("Enter string to search: ");
	gets(s1);

	puts("Enter chars to search for: ");
	gets(s2);

	pos = any(s1,s2);	

	printf("Char match at: %d\n", pos);

	return EXIT_SUCCESS;
}


int any(char s1[], char s2[])
	{
		int match = -1;

		for(int i=0; s1[i]!='\0' && i<MAXSIZE && match < 0; i++)
		{
			for(int j=0; s2[j]!='\0' && j<MAXSIZE; j++)
			{
				if(s1[i]==s2[j]) match = i;
			}
		}
		return match;
	}

