#include "tabkey.h"
#define MAXWORD 100

int main()
{
    char bword[MAXWORD];
    int index;

    struct tnode *root;

    root = NULL;

    while((index = getword(bword, MAXWORD)) != EOF)
    {
        root = addtree(root, bword);
    }
    printnode(root);
    return 0;
}


