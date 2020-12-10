/* This is the function program squeeze which takes two strings
as args and deletes and and char that appears in string two is
deleted from string one */


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100


int main(void)
{
	int k = 0;
	int rmchar = 0;

	char s1[MAXSIZE];
	char s2[MAXSIZE];
	char s3[MAXSIZE];

	puts("Enter string to squeeze:");
	gets(s1);

	puts("Enter string to compare");
	gets(s2);

	printf("String to squeeze: %s\n", s1);
	printf("Search chars: %s\n", s2);

	for(int i=0; s1[i]!='\0'; i++)
	{
		rmchar = 0;

		for(int j=0; s2[j]!='\0'; j++)
		{
			if (s1[i]==s2[j])
			{
				rmchar = 1;
			}
		}
		if(!rmchar)
		{
			s3[k]=s1[i];
			k++;
		}
	}

	puts("String has been squozen:");
	puts(s3);

	return EXIT_SUCCESS;
}
