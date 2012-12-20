#include <ctype.h>
#include "tabkey.h"

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp > 0)
    {
        printf("\n too many characters!\n");
    }
    else
    {
        buf[bufp++] = c;
    }

}

int getword(char *word, int max)
{
    int c;
    char *w = word;

    while(isspace(c = getch()))
        ;

    if((c != '\n') & (c != EOF))
    {
        *w++ = c;
    }

    if(!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for(; --max>0; w++)
    {
        if(!isalnum(*w=getch()))
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return 1;
}
