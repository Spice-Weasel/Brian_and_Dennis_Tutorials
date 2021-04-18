#include<stdio.h>

#define MAXLINE 200

int gtline(char* s, int lim);
int gtline_p(char* s, int lim);

int main(int argc, char* argv[])
{
    char s[100];

    gtline_p(s, MAXLINE);

    puts(s);
}

int gtline(char *s, int lim)
{
	int c, i;

	for(i = 0; i < (lim - 1) && (c = getchar())!=EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	return i;
}

int gtline_p(char *s, int lim)
{
	int c, i;

	for(i = 0; i < (lim - 1) && (c = getchar())!=EOF && c != '\n'; i++, s++)
	{
		*s = c;
	}
	if(c == '\n')
	{
		*(s++) = c;
	}
	*s = '\0';

	return i;
}