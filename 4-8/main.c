#include<stdio.h>

int reverse(int i, char* s1, char* s2);

int main(int argc, char* argv[])
{
    char s2[100];
    char s1[100];

    printf("Enter string to reverse: ");

    scanf("%s", &s1);

    reverse(0, s1, s2);

    printf("s2: %s\n", s2);
}

int reverse(int i, char* s1, char* s2)
{
    static int idx;
    static int length;
    static int j;

    // if not the end of string then call self again and increment string length
    if(s1[i]!='\0')
    {
        reverse(++i, s1, s2);

        s2[length] = s1[j];

        printf("s2[ %d ] = %d, s1[ %d ] = %d\n", length, s2[length], j, s1[j]);

        length--;
        j++;

    } else {

        length = i;

        s2[length] = '\0';

        length--;
        j = 0;
    }
    printf("returned index i %d\n", i);

    return i;
}