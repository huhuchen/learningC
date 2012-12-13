#include "sort.h"

#define LINELEN 500

int get_line(char s[], int limit);
void strcp(char *s1, char *s2);

int readlines(char *s[], int maxlines)
{
    int len;
    char *p, line[LINELEN];
    int nlines = 0;

    while ((len = get_line(line, LINELEN)) > 0)
    {
        /*
        if(len > LINELEN || (p=(char*)malloc(len*sizeof(char)) == NULL))
        */
        p = malloc(len*sizeof(char));
        if(len > LINELEN || p == NULL)
        {
            return -1;
        }else {
            line[len-1] = '\0';
            strcp(p, line);
            s[nlines++] = p;
        }

    }
    return nlines;
}


void writelines(char *s[], int max)
{
    int i = 0;
    char *temp;

    while(i <= max)
    {
        temp = s[i];
        printf("\n%p", temp);
        i++;
    }

}


int get_line(char s[], int limit)
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

void strcp(char *line1, char *line2)
{
    int i = 0;

    while((*(line1+i) = *(line2 + i)) != '\0')
    {
        i++;
    }

}


int strcmp(char *s1, char *s2)
{
    int i, result;

    for(i=0; s1[i] != '\0' || s2[i] != '\0'; i++)
    {
        if(s1[i] >= s2[i])
        {
            result = 1;
            break;
        }
        else
        {
            result = 0;
            break;
        }
    }
    return 0;
}


void swap(char *line[], int left, int right)
{
    char *temp;

    temp = line[left];
    line[left] = line[right];
    line[right] = temp;

}
