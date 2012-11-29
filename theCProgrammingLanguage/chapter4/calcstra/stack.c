#include "calcstra.h"

#define DEPTH 100

int p = 0;
double val[DEPTH];

void push(double num)
{
    if(p < DEPTH)
    {
        val[p++] = num;
    }
    else
    {
        printf("ERROR: stack has beed filled, can not push!");
    }
}

double pop(void)
{
    if(p > 0)
    {
        return val[--p];
    }
    else
    {
        return 0.0;
    }
}
