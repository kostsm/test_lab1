#ifndef SOLVE_H
#define SOLVE_H

typedef struct _solves {
    double result;
    char* message;
} solves;

solves solve (double a, double b, char operation);

#endif // SOLVE_H
