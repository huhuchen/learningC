#include "tabkey.h"
#include <string.h>
#define MAXWORD 100

/*
use struct pointer instead of struct array
*/
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

struct key *bsearch(char *, struct key *, int );

int main()
{
    char bword[MAXWORD];
    int count;

    struct key *keyword;

    int nkey;
    nkey = sizeof(keytab) / sizeof(keytab[0]);

    while((count = getword(bword, MAXWORD)) != EOF)
    {
        if((keyword = bsearch(bword, keytab, nkey)) != NULL)
        {
            keyword->count++;
        }
    }
    for(keyword=keytab; keyword < keytab + nkey; keyword++)
    {
        printf("\n%s : %d", keyword->word, keyword->count);
    }
    return 0;
}


struct key *bsearch(char *word, struct key tab[], int n)
{
    /*
    int lower = 0 , middle, upper = n - 1, cmp;
    */

    struct key *lower = &tab[0];
    struct key *upper = &tab[n-1];
    struct key *middle;
    int cmp;

    while(lower<=upper)
    {
        middle = lower + (upper - lower) / 2;

        cmp = strcmp(word, middle->word);

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

    return NULL;
}

