#include "tri.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

int comp(const void *elem1, const void *elem2)
{
	long f = *((long *)elem1);
	long s = *((long *)elem2);
	return (f > s) - (f < s);
}

void triInsertion(long *array, long size)
{
	long x,j;
	for (long i = 1; i < size; i++)
	{
		x=array[i];
		j=i;
		while (j>0 && array[j-1]>x){
			array[j]=array[j-1];
			j--;
		}
		array[j]=x;
	}
}

void mergeArray(long* array1,long size1,long* array2,long size2,long* buffer){
	long i = 0;
	long y = 0;
	for(long z=size1+size2-1;z>=0;z--){
		if(i==size1){
			buffer[z]=array2[y];
			y++;
		}else if(y==size2){
			buffer[z]=array1[i];
			i++;
		}else if(array1[i] > array2[y]){
			buffer[z]=array1[i];
			i++;
		}else {
			buffer[z]=array2[y];
			y++;
		}
	}
}

void triFusion2(long *array, long size, long *buffer)
{
	if (size == 1)
	{ //Tableau de taille 1 deja trie
		return;
	}
	else
	{
		//Coupe tableau en 2
		long newSize1 = size / 2;
		long newSize2 = size / 2 + size % 2;

		long *newArray1 = array;
		long *newArray2 = array+newSize1;
		//Trie nouveau tableaux par recursion
		triFusion2(newArray1, newSize1, buffer);
		triFusion2(newArray2, newSize2, buffer+newSize1);
		//Fusion des 2 tableau trie
		mergeArray(newArray1,newSize1,newArray2,newSize2,buffer);

	}
}

void triFusion(long *array, long size)
{
	if (size <= 1)
	{ //Tableau de taille 1 deja trie
		return;
	}
	long *buffer = malloc(sizeof(long) * size);
	triFusion2(array, size, buffer);
	for (long i = 0; i < size; i++)
	{
		array[i] = buffer[i];
	}
}

/*---------------------------------------------------*/
/*---------------  QUICKSORT   ----------------------*/
/*---------------------------------------------------*/
/*---------------------------------------------------*/

long pivotArbitraire(long *array, long start, long end)
{
	// return start;
	// return end;
	// return end - start;
	return (start + end) / 2;
}

long pivotAleatoire(long *array, long start, long end)
{
	return (rand() % (end - start)) + start;
}

void swap(long *i, long *j)
{
	// prlongf("swap %d<=>%d\n", *i, *j);
	long tmp = *i;
	*i = *j;
	*j = tmp;
	// prlongf("swapresult %d<=>%d\n", *i, *j);
}

long partitionner(long *array, long start, long end, long pivot)
{
	// prlongf("swap indexes %d %d (from total range %d %d)\n", pivot, end, start, end);
	swap(&array[pivot], &array[end]);

	for (long i = start; i < end; i++)
	{
		if (array[i] <= array[end])
		{
			swap(&array[i], &array[start]);
			start++;
		}
	}
	swap(&array[end], &array[start]);
	return start;
}

void triRapidePivotArbitraire(long *array, long start, long end)
{
	long pivot;
	if (start < end)
	{
		pivot = pivotArbitraire(array, start, end);
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot - 1);
		triRapidePivotArbitraire(array, pivot + 1, end);
	}
}

void triRapidePivotAleatoire(long *array, long start, long end)
{
	long pivot;
	if (start < end)
	{
		pivot = pivotAleatoire(array, start, end);
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot - 1);
		triRapidePivotArbitraire(array, pivot + 1, end);
	}
}

void triRapidePivotOptimal(long *array, long start, long end)
{
	long pivot;
	if (start < end)
	{
		pivot = pivotArbitraire(array, start, end); //TODO: change to call optimal pivot
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot - 1);
		triRapidePivotArbitraire(array, pivot + 1, end);
	}
}

void quickSortIterativeAleatoire (long arr[], long l, long h) 
{ 
    // Create an auxiliary stack 
    long stack[ h - l + 1 ]; 
  
    // initialize top of stack 
    long top = -1; 
  
    // push initial values of l and h to stack 
    stack[ ++top ] = l; 
    stack[ ++top ] = h; 
  
    // Keep popping from stack while is not empty 
    while ( top >= 0 ) 
    { 
        // Pop h and l 
        h = stack[ top-- ]; 
        l = stack[ top-- ]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        long p = pivotAleatoire(arr, l, h);
		p = partitionner(arr, l, h, p);
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if ( p-1 > l ) 
        { 
            stack[ ++top ] = l; 
            stack[ ++top ] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if ( p+1 < h ) 
        { 
            stack[ ++top ] = p + 1; 
            stack[ ++top ] = h; 
        } 
    } 
} 

void quickSortIterativeArbitraire (long arr[], long l, long h) 
{ 
    // Create an auxiliary stack 
    long stack[ h - l + 1 ]; 
  
    // initialize top of stack 
    long top = -1; 
  
    // push initial values of l and h to stack 
    stack[ ++top ] = l; 
    stack[ ++top ] = h; 
  
    // Keep popping from stack while is not empty 
    while ( top >= 0 ) 
    { 
        // Pop h and l 
        h = stack[ top-- ]; 
        l = stack[ top-- ]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        long p = pivotArbitraire(arr, l, h);
		p = partitionner(arr, l, h, p);
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if ( p-1 > l ) 
        { 
            stack[ ++top ] = l; 
            stack[ ++top ] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if ( p+1 < h ) 
        { 
            stack[ ++top ] = p + 1; 
            stack[ ++top ] = h; 
        } 
    } 
} 


int partition (long arr[], long l, long h) 
{ 
    long x = arr[h]; 
    long i = (l - 1); 
  
    for (long j = l; j <= h- 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            i++; 
            swap (&arr[i], &arr[j]); 
        } 
    } 
    swap (&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 

void quickSortIterative (long arr[], long l, long h) 
{ 
    // Create an auxiliary stack 
    long stack[ h - l + 1 ]; 
  
    // initialize top of stack 
    long top = -1; 
  
    // push initial values of l and h to stack 
    stack[ ++top ] = l; 
    stack[ ++top ] = h; 
  
    // Keep popping from stack while is not empty 
    while ( top >= 0 ) 
    { 
        // Pop h and l 
        h = stack[ top-- ]; 
        l = stack[ top-- ]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        long p = partition( arr, l, h ); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if ( p-1 > l ) 
        { 
            stack[ ++top ] = l; 
            stack[ ++top ] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if ( p+1 < h ) 
        { 
            stack[ ++top ] = p + 1; 
            stack[ ++top ] = h; 
        } 
    } 
} 


void tamiser(long *tree, long node, long n)
{
	long k = node;
	long j = 2 * k;
	long tmp;
	while (j <= n)
	{
		if (j < n && tree[j - 1] < tree[j])
		{
			j++;
		}
		if (tree[k - 1] < tree[j - 1])
		{
			tmp = tree[k - 1];
			tree[k - 1] = tree[j - 1];
			tree[j - 1] = tmp;
			k = j;
			j = 2 * k;
		}
		else
		{
			j = n + 1;
		}
	}
}

void triParTas(long *tree, long size)
{
	for (long i = size / 2; i >= 1; i--)
	{
		tamiser(tree, i, size);
	}
	long tmp;
	for (long i = size; i >= 2; i--)
	{
		tmp = tree[i - 1];
		tree[i - 1] = tree[0];
		tree[0] = tmp;
		tamiser(tree, 1, i - 1);
	}
}

void sort(long *array,long size)
{
	qsort(array, size, sizeof(long), comp);
}