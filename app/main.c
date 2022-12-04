#include <stdio.h>

#include "solve.h"

int main()
{
    solves s = solve (1, 2, '+');
    printf("%f \n", s.result);
}
