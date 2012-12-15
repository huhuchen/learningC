#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *lines, int max);

int main(int argc, char *argv[])
{
    char lines[MAXLINE];
    int nlines, found;
    found = 0;

    if(argc != 2){
        printf("\nUsage: .\\grep.c pattern\n");
    }else{
        while((nlines = get_line(lines, MAXLINE))>0)
        {
            if(strstr(lines, argv[1]) != NULL)
            {
                printf("\n%s\n", lines);
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
    if(c == '\0')
    {
        s[i] = '\0';
    }
    return i;
}
