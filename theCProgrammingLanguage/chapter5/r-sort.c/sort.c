#include "sort.h"

#define MAXLINE 1000

char *lines[MAXLINE];

typedef int (*comp)(char *, char *);
/*
void sortlines(char *s[], int start, int end, int (*comp)(void *, void *));
*/
void sortlines(char *s[], int start, int end, comp cmp);

int main(int argc, char *argv[])
{
    int nlines, numeric;

    numeric = 0;

    if(argc > 1 && strcmp(argv[1], "-n") == 0)
    {
        numeric = 1;
    }

    if((nlines = readlines(lines, MAXLINE))>0)
    {
        /*
        sortlines(lines, 0, nlines-1, (int (*)(void *, void *))(numeric? numcmp:strcmp));
        */
        sortlines(lines, 0, nlines-1, (numeric ? numcmp : strcmp));
        writelines(lines, nlines);
    }else{
        printf("\nno inputs\n");
    }
    return 0;

}
/*
void sortlines(char *lines[], int begin, int end, int (*comp)(void *, void *))
*/
void sortlines(char *lines[], int begin, int end, comp cmp)
{
    int i,j, cmpresult;

    for (i=0; i<=end; i++)
    {
        for(j=0; j<end-i; j++)
        {
            /*
            cmpresult = (*comp)(lines[j], lines[j+1]);
            */
            cmpresult = cmp(lines[j], lines[j+1]);
            if(cmpresult==1)
            {
                swap(lines, j, j+1);
            }
        }
    }
}

