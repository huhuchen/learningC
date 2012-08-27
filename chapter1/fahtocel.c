#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        
        printf("%3.0f %6.1f\n", fahr, ((5.0/9.0)*(fahr-32.0)));
    }
}

//main()
//{
//    float fahr, celsius;
//    int lower, higher, step;
//
//    lower = 0;
//    higher = 300;
//    step = 20;
//    fahr = lower;
//    while(fahr <= higher)
//    {
//        celsius = 5.0 * (fahr - 32.0) / 9.0;
//        printf("%3.0f %6.1f\n", fahr, celsius);
//        fahr+=step; 
//    }
//}
//main()
//{
//    float fahr, celsius;
//    int lower, higher, step;
//
//    lower = 0;
//    higher = 300;
//    step = 20;
//
//    for (fahr = lower; fahr <= higher; fahr = fahr + step)
//    {
//        celsius = 5.0 * (fahr - 32.0) / 9.0;
//        printf("%3.0f %6.1f\n", fahr, celsius);
//    }
//}
