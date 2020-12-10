/* convert hex digits to integer value */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int htoi(char* s);
int ishex(char c);
int isshex(char* s);
int power(int i, int j);
int length(char* s);

int main(void)
{
	char s1[MAX];
	int d;

	// Copy input string to s1
	scanf("%s", s1);

	// Check if string is all hex
	if(isshex(s1)==EXIT_FAILURE)
	{
		puts("Not Hex");

		return EXIT_FAILURE;
	}

	// convert hex string to ints
	d = htoi(s1);

	printf("DECIMAL = %d\n", d);

	return EXIT_SUCCESS;
}


int ishex(char c)
{
	char hex[] = {'0','1','2','3','4','5','6','7','8'\
	,'9','a','b','c','d','e','f'}; // Array of allowable Hex char

	for(int i=0; hex[i]!='\0'; i++)
	{
		if(c == hex[i])
		{
			return EXIT_SUCCESS;
		}
	}
	return EXIT_FAILURE;
}


int isshex(char* s)
{
	int error = 0;

	for(int i=0; s[i]!='\0' && error==0; i++)
	{
		if(ishex(s[i])==EXIT_FAILURE)
		{
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int htoi(char* s1)
{
	int i,j, len;
	int sum=0;
	int ints[MAX];
	int pwrs[MAX];

	char hex[] = {'0','1','2','3','4','5','6','7','8'\
        	,'9','a','b','c','d','e','f'}; // Array of allowable Hex char

	// get string length
	len = length(s1);

	// Index through string backwards (from LSB), reduce index by 1 to skip null
	// char at end of string?
	for(i=0; i<len; i++)
	{
		// find hex match with string char - return char/int match using hex array
		for(j = 0; hex[j]!=s1[i]; j++);

		// assign int value to int Array
		ints[len-i] = j;

		pwrs[len-i] = power(16, len-1-i);
		printf("(16^%d)*%d=%d\n", len-1-i, ints[len-i], pwrs[len-i]);

		sum += pwrs[len-i]*ints[len-i];
	}
	return sum;
}

int power(int base, int exponent)
{
	int s=1;

	for(int i=exponent; i>0; i--)
	{
		s = s*base;
	}

	return s;
}

int length(char* str)
{
	int len;
	// get index of incoming string
	for(len=0; str[len]!='\0'; len++);

	return len;
}
