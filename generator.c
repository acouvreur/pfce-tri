#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "generator.h"

long *initializeArray(long n)
{
    return (long *)malloc(sizeof(long) * n);
}

long *generateSortedArray(long n)
{
    long *array = initializeArray(n);

    for (long i = 0; i < n; i++)
    {
        array[i] = i;
    }

    return array;
}

long *generateReverseSortedArray(long n)
{
    long *array = initializeArray(n);

    for (long i = 1; i <= n; i++)
    {
        array[i-1] = n - i;
    }

    return array;
}

long *generateRandomizedArrayRangeN(long n)
{
    long *array = initializeArray(n);

    time_t t;
    srand((unsigned)time(&t));

    for (long i = 0; i < n; i++)
    {
        array[i] = rand() % n;
    }

    return array;
}

long *generateRandomizedArrayRangeLogN(long n)
{
    long *array = initializeArray(n);

    time_t t;
    srand((unsigned)time(&t));

    double dn = (double)n;

    for (long i = 0; i < n; i++)
    {
        array[i] = rand() % (long)log(dn);
    }

    return array;
}

long *generateRandomizedArrayRangeNSquare(long n)
{
    long *array = initializeArray(n);

    time_t t;
    srand((unsigned)time(&t));

    long ns = n * n;

    for (long i = 0; i < n; i++)
    {
        array[i] = rand() % ns;
    }

    return array;
}

long *generateConstantArray(long n, long constant)
{
    long *array = initializeArray(n);

    for (long i = 0; i < n; i++)
    {
        array[i] = constant;
    }

    return array;
}