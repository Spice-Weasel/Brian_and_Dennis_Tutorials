#include<stdio.h>

void stringcat(char* s1, char* s2);

void strcopy(char* s1, char* s2);

int main(int argc, char* argv[])
{
    char s1[20], s2[20], s3[20];


    for(int i = 0; i < argc; i++)
    {
        printf("Argument %d : %s\n", i, argv[i]);
    }
    strcopy(argv[1], s1);
    strcopy(argv[2], s2);

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    stringcat(s1, s2);

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    return 0;
}

void stringcat(char* s1, char* s2)
{
    int i = 0;
    int j = 0;

    for(; s1[i]!='\0'; i++);

    for(; s2[j]!='\0'; j++)
    {
        s1[i+j] = s2[j];
    }

    s1[i+j] = '\0';
}

/*
void stringcatrec(char* s1, char* s2)
{
    static int i = 0;
    static int j = 0;

    if(s1[i++] != '\0')
    {
        stringcatrec(s1, s2);

        s2
    }
}
*/

void strcopy(char* s1, char* s2)
{
    static int i = 0;

    s2[i] = s1[i];
    
    if(s2[i] != '\0')
    {
        i++;

        strcopy(s1, s2);
    }
    
    i = 0;
}