#ifndef SOLVE_H
#define SOLVE_H

typedef struct _solves {
    double x1;
    double x2;
    int count;
} solves;

solves solve (double a, double b, double c);

#endif // SOLVE_H
