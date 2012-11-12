#include <stdio.h>

int power(int x, int y);

main()
{
    int i;
    
    for (i = 0; i <= 10; ++i)
        printf("the %d power of %d is %d \n", i, 2, power(2, i));
    return 0;
}

int power(int base, int n)
{
    int p;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
//    if (n == 1)
//        return base;
//    else
//        return base * power(base, n-1);
}
