#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define MAXCHARNUM 32

char get_line(char line[], int maxline);
double atof(char *line);

int main()
{
    double num, result = 0;
    char line[MAXCHARNUM];
    int length;


    while((length = get_line(line, MAXCHARNUM)) > 0)
    {
        num = atof(line);
        result += num;
        printf("\n the result is %f\n", result);
    }
    return 0;
}

char get_line(char s[], int limit)
{
    int c;
    int i = 0;
    while(--limit>0 && (c=getchar()) !=EOF && c != '\n')
    {
        s[i++] = c;
    }

    if(c == '\n')
        s[i++] = '\n';
    s[i] = '0';
    return i;
}

double atof(char *s)
{
    double result;
    int i, sign, power;

    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1: 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for(result=0; isdigit(s[i]); i++)
    {
        result = result * 10 + s[i] - '0';
    }
    if(s[i] == '.')
        i++;

    for(power=1; isdigit(s[i]); i++)
    {
        result = result * 10 + s[i] - '0';
        power *= 10;
    }

    result = sign * result / power;
    return result;
}
