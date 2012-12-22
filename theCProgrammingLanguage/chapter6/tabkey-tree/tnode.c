#include "tabkey.h"
#include <stdlib.h>

struct tnode *talloc();
char *strdups(char *);


struct tnode *addtree(struct tnode *p, char *w)
{
    int cmp;

    if(p == NULL){
        p = talloc();
        p->word = strdups(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    } else if ((cmp = strcmp(p->word, w))==0){
        p->count++;
    } else if (cmp > 0){
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }

    return p;
}

struct tnode *talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdups(char *s)
{
    char *w;

    w = (char *)malloc(sizeof(strlen(s)+1));

    if(w != NULL);
        strcpy(w, s);
    return w;
}

void printnode(struct tnode *p)
{
    if(p != NULL){
        printnode(p->left);
        printf("\n %s : %d", p->word, p->count);
        printnode(p->right);
    }
}
