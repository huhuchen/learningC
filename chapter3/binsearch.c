#include <stdio.h>

char num[13] = {1, 3, 5, 6, 7, 8, 12, 16, 19, 20, 23, 27, 29};
int binsearch(int x, char s[], int n);

int main()
{
    extern char num[];
    int result;

    result = binsearch(2, num, 13);

    if (result == -1)
        printf("found nothing\n");
    else
        printf("find result is : %d\n", result);
    return 0;
}


int binsearch(int x, char s[], int n)
{
    int lower, middle, upper;
    lower = 0;
    upper = n - 1;

    while(lower <= upper){
        middle = (lower + upper) / 2;
        if (s[middle] < x ){
            lower = middle + 1;
        } else if (s[middle] > x){
            upper = middle - 1;
        } else 
            return middle;
    }
    
    return -1;
}
