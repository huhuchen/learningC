#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int limit);
void copy(char to[], char from[]);

int main()
{
    int max, len;
    char line[MAXLINE];
    char longest[MAXLINE];    
    
    max = 0;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("\n len is :%d", len);
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }

    printf("\n the logest line is : %d \n", max);

    return 0;
}

int get_line(char s[], int limit)
{
    int i, c;
 
    for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    for(i = 0; i != '\0';++i)
    {
        to[i] = from[i];
    }
}


