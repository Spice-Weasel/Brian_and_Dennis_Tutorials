/* Fold long lines of input text */

#include<stdio.h>
#include<stdlib.h>

#define FOLDCOLUMN 20
#define MAXLINE	1000

char s1[MAXLINE];
char s2[MAXLINE];

int len;

void col(void);
int gtstr(void);
int fold(int);
void print(int);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Enter correct number of arguments\n");
		
		return EXIT_FAILURE;
	}

	extern int len;

	col();

	print(fold(gtstr()));

	printf("\nlength %d\n", len);

}

int gtstr(void)
{
	extern char s1[];
	char c;
	int i;

	for(i=0; (c=getchar())!='\n'; i++)
        {
                s1[i] = c; 
        }
	return i;
}

int fold(int len)
{
	extern char s1[];
	extern char s2[];
	
	int fold;
	int j = 0;

	s2[j] = ' ';
	j++;

	for(int i = len; i>=0; i--)
	{
		
		if(i!=0 && (i % FOLDCOLUMN) == 0)
		{
			fold = 1;
		}
		if(fold == 1 && s1[i]==' ' && s1[i+1]!=' ')
		{
			//putchar('\n');
			s2[j] = '\n';
			fold = 0;
			j++;
		}
		//putchar(s1[i]);

		s2[j] = s1[i];

		j++;
	}
	return j;
}

void print(int len)
{
	extern char s2[];
	
	for(int i=len; i>=0; i--)
	{
		putchar(s2[i]);
	}
}


void col(void)
{
	for(int i = 0; i <= FOLDCOLUMN; i++)
	{
		putchar('#');
	}
	putchar('\n');
}
