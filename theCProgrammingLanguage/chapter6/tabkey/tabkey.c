#include "tabkey.h"
#include <string.h>
#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"void", 0},
    {"while", 0}
};

int bsearch(char *, struct key *, int );

int main()
{
    char bword[MAXWORD];
    int i, index, count;

    int nkey;
    nkey = sizeof(keytab) / sizeof(keytab[0]);

    while((count = getword(bword, MAXWORD)) != EOF)
    {
        if((index = bsearch(bword, keytab, nkey)) >= 0)
        {
            keytab[index].count++;
        }
    }
    for(i=0; i< nkey; i++)
    {
        printf("\n%s : %d", keytab[i].word, keytab[i].count);
    }
    return 0;
}


int bsearch(char *word, struct key tab[], int n)
{
    int lower = 0 , middle, upper = n - 1, cmp;


    while(lower<=upper)
    {
        middle = (lower + upper) / 2;

        cmp = strcmp(word, tab[middle].word);

        if(cmp==0)
        {
            return middle;
        }
        else if (cmp > 0)
        {
            lower = middle + 1;
        }
        else{
            upper = middle - 1;
        }
    }

    return -1;
}

