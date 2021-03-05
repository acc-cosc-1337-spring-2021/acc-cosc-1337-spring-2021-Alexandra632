//cpp
#include "loops.h"

int factorial(int num)
{
    int total = 1;
    int count = 1;

    while(count <= num)
    {
        total = total * count++;
    }

    return total;
}