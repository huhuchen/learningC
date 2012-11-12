#include <stdio.h>
#include <string.h>
#define MAXLINE 1000    

void reverse(char s[]);

int main()
{
    char a[MAXLINE], c;
    int i;

    i = 0;
    while ((c = getchar()) != EOF)
    {
        a[i] = c;
        ++i;
    }

    if (c == EOF){
        a[i+1] = '\0';
    }

    reverse(a);
   
    printf("\n"); 
    for (i = 0; a[i] != '\0'; i++)
        putchar(a[i]);

    return 0;
}

void reverse(char s[])
{
    int i, j, temp;

    for (i = 0, j = strlen(s) - 1; j >= i; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}



