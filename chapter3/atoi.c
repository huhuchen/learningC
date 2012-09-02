#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int atoi(char s[]);

int main()
{
    char a[MAXLINE], c;
    int i, num;


    i = 0;
    while ((c = getchar()) != '\n')
    {
        a[i] = c;
        ++i;
    }

    if (c == '\n'){
        a[i+1] = '\0';
    }

    num = atoi(a);

    printf("\nthe num is %d\n", num);
    return 0;
}


int atoi(char s[])
{
    int i, num, sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    
    for (num = 0; isdigit(s[i]); i++)
        num = 10 * num + (s[i] - '0');  //so good
    return sign * num;
}

