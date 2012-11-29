#include <stdio.h>
#include "calcstra.h"

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
