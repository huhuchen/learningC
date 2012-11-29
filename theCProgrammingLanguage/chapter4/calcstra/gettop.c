#include <ctype.h>
#include "calcstra.h"

int gettop(char s[])
{
    int c, i;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(!isdigit(c) && c != '.')
        return c;

    i = 1;
    if(isdigit(c))
        while(isdigit(s[i++] = c = getch()))
            ;

    if(c=='.')
        while(isdigit(s[i++] =c = getch()))
            ;
    s[--i] = '\0';
    if(c != EOF)
        ungetch(c);

    return NUMBER;
}
