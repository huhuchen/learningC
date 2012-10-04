#include <stdio.h>

/*
int main(int argc, char *argv[]) {
    printf("hello world\n");
    puts("hello world\n");

    return 0;
}
*/


int main()
{
    int age = 26;
    int height = 172;
    float power = 12.2f;
    double super_power = 12.21223;
    char initial = 'A';
    char name[] = "chen";

    printf("I'm is %d old.\n", age);
    printf("I'm is %d cm tall.\n", height);
    printf("the power is %f.\n", power);
    printf("the super_power is %f.\n", super_power);
    printf("the initial is %c.\n", initial);
    printf("the initial is %s.\n", name);

    return 0;
}
