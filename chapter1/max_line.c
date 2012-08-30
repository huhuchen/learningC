#include <stdio.h>
#define MAXLINE 1000

//int get_line(char line[], int limit);
//void copy(char to[], char from[]);
//
//int main()
//{
//    int max, len;
//    char line[MAXLINE];
//    char longest[MAXLINE];    
//    
//    max = 0;
//
//    while ((len = get_line(line, MAXLINE)) > 0)
//    {
//        printf("\n len is :%d", len);
//        if (len > max){
//            max = len;
//            copy(longest, line);
//        }
//    }
//
//    printf("\n the logest line is : %d \n", max);
//
//    return 0;
//}
//
//int get_line(char s[], int limit)
//{
//    int i, c;
// 
//    for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
//        s[i] = c;
//
//    if(c == '\n'){
//        s[i] = c;
//        ++i;
//    }
//    s[i] = '\0';
//    return i;
//}
//
//void copy(char to[], char from[])
//{
//    int i;
//    for(i = 0; i != '\0';++i)
//    {
//        to[i] = from[i];
//    }
//}
//
//
//



int max;
char line[MAXLINE], longest[MAXLINE];

int get_line(void);
void copy(void);

int main()
{
    int len;
    extern int max;
    extern char longest[];

    while ((len = get_line()) > 0)
    {
        if(len > max){
            max = len;
            copy();
        }
    }
    printf("\nthe length of longest line is: %d\n", max);    
    printf("\nthe longest line is \n%s", longest);
    return 0;
}


int get_line(void)
{
    int i, c; 
    extern int max;
    extern char line[];

    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}


void copy(void)
{
    int i = 0;
    extern char line[], longest[];
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
