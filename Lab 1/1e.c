/*
Create two pointer called PS1 and PS2 to two strings, Read the contents
using pointers and also write a function StrCat (PS1, PS2) which
concatenates second string to the end of first string using pointers PS1
and PS2.
*/


#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 25


void StrCat(char *, char *);


int main()
{
    char string1[MAX_SIZE], string2[MAX_SIZE];
    
    printf("Enter string string 1: ");
    scanf("%s", string1);
    printf("Enter string string 2: ");
    scanf("%s", string2);

    char *PS1 = string1;
    char *PS2 = string2;

    StrCat(PS1, PS2);
    printf("%s\n", PS1);

    return 0;
}


void StrCat(char *PS1, char* PS2)
{
    while(*PS1 != '\0')
    {
        PS1++;
    }
    while(*PS2 != '\0')
    {
        *PS1 = *PS2;
        PS1++;
        PS2++;
    }
    *PS1 = '\0';
}