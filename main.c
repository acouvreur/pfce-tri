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
        if (!testTriInsertion())
        {
            fprintf(stderr, "Erreur testTriInsertion\n");
        }
        if (!testTriFusion())
        {
            fprintf(stderr, "Erreur testTriFusion\n");
        }
        if (!testTriRapidePivotArbitraire())
        {
            fprintf(stderr, "Erreur testTriRapidePivotArbitraire\n");
        }
        if (!testTriRapidePivotAleatoire())
        {
            fprintf(stderr, "Erreur testTriRapidePivotAleatoire\n");
        }
        if (!testTriRapidePivotOptimal())
        {
            fprintf(stderr, "Erreur testTriRapidePivotOptimal\n");
        }
        if (!testTriParTas())
        {
            fprintf(stderr, "Erreur testTriParTas\n");
        }
		if (!testQSort())
        {
            fprintf(stderr, "Erreur testQSort\n");
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
        int n = atoi(argv[3]);
        int *array;
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
            triRapidePivotArbitraire(array, 0, n-1);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 5:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            triRapidePivotAleatoire(array, 0, n-1);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        case 6:
            clock_gettime(CLOCK_MONOTONIC, &t1);
            sort(array, n);
            clock_gettime(CLOCK_MONOTONIC, &t2);
            break;
        }
        long ns = (long) ((((double)t2.tv_sec + 1.0e-9*t2.tv_nsec) - ((double)t1.tv_sec + 1.0e-9*t1.tv_nsec)) * 1000000000);
        printf("%ld\n", ns);
    }
    return 0;
}
