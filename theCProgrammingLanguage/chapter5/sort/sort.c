#include "sort.h"

#define MAXLINE 1000

char *lines[MAXLINE];

void sortlines(char *s[], int start, int end);

int main()
{
    int nlines;

    if((nlines = readlines(lines, MAXLINE))>0)
    {
        sortlines(lines, 0, nlines-1);
        writelines(lines, nlines);
    }else{
        printf("\nno inputs\n");
    }


}

void sortlines(char *lines[], int begin, int end)
{
    int i,j, cmp;

    for (i=0; i<=end; i++)
    {
        for(j=0; j<end-i; j++)
        {
            cmp = strcmp(lines[j], lines[j+1]);
            if(cmp==1)
            {
                swap(lines, j, j+1);
            }
        }

    }

}

