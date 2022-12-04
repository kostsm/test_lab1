#include "solve.h"
#include <math.h>
#include <stdio.h>

solves solve (double a, double b, char operation)
{
    solves answer;
    answer.result = 0;
    answer.message = "ok";

    if (operation == '+')
        answer.result = a + b;
    if (operation == '-')
        answer.result = a - b;
    if (operation == '*')
        answer.result = a * b;
    if (operation == '/')
    {
        if (b == 0)
            answer.message = "error";
        else
            answer.result = a / b;
    }
    printf("%s", answer.message);
    return answer;
}
