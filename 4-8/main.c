#include<stdio.h>


void reverse(char* s1, char* s2);


int main(int argc, char* argv[])
{
    char s2[100];
    char s1[100];

    printf("Enter string to reverse: ");

    scanf("%s", &s1);

    reverse(s1, s2);

    printf("s2: %s\n", s2);
}

// reverse takes string s1 and puts the reversed string into s2
void reverse(char* s1, char* s2)
{
    static int i;
    static int length;
    static int j;

<<<<<<< HEAD
    // if not the end of string then call self again and increment string length
=======
    // If the end of the string s1 has not been reached then call self and increment
    // counter.
>>>>>>> 4254afa6e137397e1d656b7ce13d6afc483f3a28
    if(s1[i]!='\0')
    {
        i++;
        reverse(s1, s2);

        s2[length--] = s1[j++];

    // End of string has been reached, set length equal to counter value and
    // set put null char at end of string.
    } else {

<<<<<<< HEAD
        length = i;

        s2[length] = '\0';

        length--;
=======
        // assign values to static variables used for reversal
>>>>>>> 4254afa6e137397e1d656b7ce13d6afc483f3a28
        j = 0;
        length = i;

        s2[length--] = '\0';
    }
    return;
}