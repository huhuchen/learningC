#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *lines, int max);

int main(int argc, char *argv[])
{
    char lines[MAXLINE];
    int nlines, found, c;
    long lineno = 0;
    int number = 0, except = 0;
    found = 0;

    while(--argc>0 && (*++argv)[0] == '-')
    {
        c = *++argv[0];
        switch(c)
        {
            case 'n':
                number=1;
                break;
            case 'x':
                except = 1;
                break;
            default:
                printf("\ngrep: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
        }
    }


    if(argc != 1 ){
        printf("\nUsage: .\\grep.c -x -n pattern\n");
    }else{
        while((nlines = get_line(lines, MAXLINE))>0)
        {

            if((strstr(lines, *argv) != NULL) != except)
            {
                lineno++;
                if(number)
                {
                    printf("%ld:", lineno);
                }
                printf("%s\n", lines);
                found++;
            }
        }

    }
    return found;
}

int get_line(char *s, int max)
{
    int c;
    int i = 0;

    while(--max>0 && (c = getchar())!= EOF && c != '\n')
    {
        s[i] = c;
        i++;
    }
    if(c == '\n')
    {
        s[i] = '\0';
    }
    return i;
}
