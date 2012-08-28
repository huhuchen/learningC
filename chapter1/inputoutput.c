#include <stdio.h>


//code 1
//count the count of char in input stream
//main()
//{
//    int count;
//
//    count = 0;
//    while (getchar() != EOF)
//    {
//        ++count;
//    }
//    printf("count : %d ", count);
//}



//code 2
//count the count of line , word and char in input stream
#define IN 0  /* inside word */
#define OUT 1 /* outside word */

main()
{
    int line, word, nc;
    int status;
    char c;
    
    line = word = nc = 0;
    status = OUT;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++line;
        if (c == '\n' || c == ' ' || c == '\t')
            status = OUT;
        else if (status == OUT)
        {
            status = IN;
            ++word;
        }    
    }
        
    printf("\nline : %d \nword : %d \nchar : %d\n", line, word, nc);
}

