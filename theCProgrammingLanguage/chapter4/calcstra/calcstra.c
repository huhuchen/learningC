#include <stdio.h>
#include <stdlib.h>

#include "calcstra.h"

#define MAXDEPTH 100

int main()
{
    char s[MAXDEPTH];
    int type, temp;

    while((type=gettop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break;
            case '/':
                temp = pop();
                if(temp != 0.0)
                    push(pop() / temp);
                else
                    printf("Error! zero divisor\n");
                break;
            case '\n':
                printf("\n the result is %f", pop());
                break;
            default:
                printf("\n the wrong command: %s\n", s);
                break;
        }
    }
    return 0;
}

