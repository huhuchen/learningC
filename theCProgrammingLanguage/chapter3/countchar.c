#include <stdio.h>

int main(){

    int c, i;
    int ndigit[10], nwhite, nother;

    nwhite = nother = 0;
    
    for (i = 0; i < 9; ++i){
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ++ndigit[c - '0'];
                break;
            case '\t':
            case '\n':
            case ' ':
                ++nwhite;
                break;
            default : 
            {
                ++nother;
                break;
            }
    
        }
    }

    printf("\ncount of white is %d", nwhite);
    printf("\ncount of nother is %d", nother);
   
    for (i = 0; i < 9; ++i){
        printf("\nthe count of %d is %d", i, ndigit[i]);
    } 
    return 0;
}
