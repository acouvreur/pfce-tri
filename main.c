#include "tri.h"
#include "test.h"
#include "generator.h"

#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        int err;
        if ((err=testTriInsertion()))
        {
            fprintf(stderr, "Erreur testTriInsertion (%d)\n", err);
        }
        if ((err=testTriFusion()))
        {
            fprintf(stderr, "Erreur testTriFusion (%d)\n", err);
        }
        if ((err=testTriRapidePivotArbitraire()))
        {
            fprintf(stderr, "Erreur testTriRapidePivotArbitraire (%d)\n", err);
        }
        if ((err=testTriRapidePivotAleatoire()))
        {
            fprintf(stderr, "Erreur testTriRapidePivotAleatoire (%d)\n", err);
        }
        if ((err=testTriRapidePivotOptimal()))
        {
            fprintf(stderr, "Erreur testTriRapidePivotOptimal (%d)\n", err);
        }
        if ((err=testTriParTas()))
        {
            fprintf(stderr, "Erreur testTriParTas (%d)\n", err);
        }
		if ((err=testQSort()))
        {
            fprintf(stderr, "Erreur testQSort (%d)\n", err);
        }
		if ((err=testSmoothSort()))
        {
            fprintf(stderr, "Erreur testSmoothSort (%d)\n", err);
        }
    }
    else if (argc != 4)
    {
        return 1;
    }
    else
    {
        int sortingAlgo = atoi(argv[1]);
        int generatorAlgo = atoi(argv[2]);
        long n = atol(argv[3]);
        long *array = NULL;
        struct timespec t1, t2;

        switch (generatorAlgo)
        {
        case 1:
            array = generateSortedArray(n);
            break;
        case 2:
            array = generateReverseSortedArray(n);
            break;
        case 3:
            array = generateConstantArray(n, 20);
            break;
        case 4:
            array = generateRandomizedArrayRangeN(n);
            break;
        case 5:
            array = generateRandomizedArrayRangeLogN(n);
            break;
        case 6:
            array = generateRandomizedArrayRangeNSquare(n);
            break;
        }
        switch (sortingAlgo)
        {
        case 1:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            triInsertion(array, n);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 2:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            triFusion(array, n);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 3:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            triParTas(array, n);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 4:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            quickSortIterativeArbitraire(array, 0, n-1);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 5:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            quickSortIterativeAleatoire(array, 0, n-1);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 6:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            sort(array, n);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        }
        double ns = (((double)t2.tv_sec + 1.0e-9*t2.tv_nsec) - ((double)t1.tv_sec + 1.0e-9*t1.tv_nsec));
        printf("%0.9f\n", ns);
    }
    return 0;
}
