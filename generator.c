#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "generator.h"

int* initializeArray(int n) {
    return (int*)malloc(sizeof(int)*n);
}

int* generateSortedArray(int n) {
    int* array = initializeArray(n);

    for(int i = 0; i < n; i++) {
        array[i] = i;
    }

    return array;
}

int* generateReverseSortedArray(int n) {
    int* array = initializeArray(n);

    for(int i = 0; i < n; i++) {
        array[i] = n - i;
    }

    return array;
}

int* generateRandomizedArrayRangeN(int n) {
    int* array = initializeArray(n);

    time_t t;
    srand((unsigned) time(&t));

    for(int i = 0; i < n; i++) {
        array[i] = rand() % n;
    }

    return array;
}

int* generateRandomizedArrayRangeLogN(int n) {
    int* array = initializeArray(n);

    time_t t;
    srand((unsigned) time(&t));

    double dn = (double) n;

    for(int i = 0; i < n; i++) {
        array[i] = rand() % (int) log(dn);
    }

    return array;
}

int* generateRandomizedArrayRangeNSquare(int n) {
    int* array = initializeArray(n);

    time_t t;
    srand((unsigned) time(&t));

    int ns = n*n;

    for(int i = 0; i < n; i++) {
        array[i] = rand() % ns;
    }

    return array;
}

int* generateConstantArray(int n, int constant) {
    int* array = initializeArray(n);

    for(int i = 0; i < n; i++) {
        array[i] = constant;
    }

    return array;
}