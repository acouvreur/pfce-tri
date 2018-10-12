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

void triInsertion2(long *array, long l, long h)
{
	long x,j;
	for (long i = l+1; i < h; i++)
	{
		x=array[i];
		j=i;
		while (j>l && array[j-1]>x){
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

long medianOf3(long * intArray, long left, long right) {
    int center = (left + right) / 2;

    if (intArray[left] > intArray[center])
      swap(&intArray[left], &intArray[center]);

    if (intArray[left] > intArray[right])
      swap(&intArray[left], &intArray[right]);

    if (intArray[center] > intArray[right])
      swap(&intArray[center], &intArray[right]);

    swap(&intArray[center], &intArray[right-1]);
    return right - 1;
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

void triRapidePivotMed3(long *array, long start, long end)
{
	long pivot;
	if (start < end)
	{
		pivot = medianOf3(array, start, end);
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

void quickSortIterativeMed3 (long arr[], long l, long h) 
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
        long p = medianOf3(arr, l, h);
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

void quickSortIterativeMed3Threshold (long arr[], long l, long h, long threshold) 
{ 
    // Create an auxiliary stack 
    long stack[ h - l + 1 ]; 
	// long size = h - l + 1 ;
  
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
        long p = medianOf3(arr, l, h);
  
        // Threshold test
        if(h - l < threshold){
			triInsertion2(arr,l, h);
		} else {
		    p = partitionner(arr, l, h, p);
        }
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

long lsr(long x, long n)
{
  return (long)((unsigned long)x >> n);
}

long numberOfTrailingZeros(long x){
	long counter=0;
	while(x % 2 == 0){
		counter++;
		x /= 2;
	}
	return counter;
}

void smoothSortSift(long * array,long size, long pshift, long head,long *smoothSortLP) { 
        long val = array[head]; 
 
        while (pshift > 1) { 
            long rt = head - 1; 
            long lf = head - 1 - smoothSortLP[pshift - 2]; 
 
            if (val >= array[lf] && val >= array[rt]) 
                break; 
            if (array[lf] >= array[rt]) { 
                array[head]= array[lf]; 
                head = lf; 
                pshift -= 1; 
            } else { 
                array[head]= array[rt];
                head = rt; 
                pshift -= 2; 
            } 
        } 
 
        array[head]=val; 
    } 

void smoothSortTrinkle(long * array,long size, long p, long pshift, long head, int isTrusty,long *smoothSortLP) { 
        long val = array[head]; 
 
        while (p != 1) { 
            long stepson = head - smoothSortLP[pshift]; 
 
            if (array[stepson]<= val) 
                break; // current node is greater than head. Sift. 
 
            // no need to check this if we know the current node is trusty, 
            // because we just checked the head (which is val, in the first 
            // iteration) 
            if (!isTrusty && pshift > 1) { 
                long rt = head - 1; 
                long lf = head - 1 - smoothSortLP[pshift - 2]; 
                if (array[rt] >= array[stepson]
                        || array[lf] >= array[stepson]) 
                    break; 
            } 
 
            array[head]=array[stepson]; 
 
            head = stepson; 
            long trail = numberOfTrailingZeros(p & ~1); 
            p = lsr(p,trail); 
            pshift += trail; 
            isTrusty = 0; 
        } 
 
        if (!isTrusty) { 
            array[head] = val; 
            smoothSortSift(array,size, pshift, head,smoothSortLP); 
        } 
}

void smoothSort2(long *array,long size,long lo,long hi,long * smoothSortLP){
	long head = lo;
	long p = 1;
	long pshift = 1; 
	while (head < hi) { 
		if ((p & 3) == 3) { 
			// Add 1 by merging the first two blocks into a larger one. 
			// The next Leonardo number is one bigger. 
			smoothSortSift(array,size, pshift, head,smoothSortLP); 
			p = lsr(p,2); 
			pshift += 2; 
		} else { 
			// adding a new block of length 1 
			if (smoothSortLP[pshift - 1] >= hi - head) { 
			    // this block is its final size. 
			    smoothSortTrinkle(array,size, p, pshift, head, 0,smoothSortLP); 
			} else { 
			    // this block will get merged. Just make it trusty. 
			    smoothSortSift(array,size, pshift, head,smoothSortLP);
			} 
 
			if (pshift == 1) { 
				// smoothSortLP[1] is being used, so we add use smoothSortLP[0] 
				p <<= 1; 
				pshift--; 
			} else { 
				// shift out to position 1, add smoothSortLP[1] 
				p <<= (pshift - 1); 
				pshift = 1; 
			} 
		} 
		p |= 1; 
		head++; 
    }
	smoothSortTrinkle(array, size, p, pshift, head, 0,smoothSortLP); 
	
	while (pshift != 1 || p != 1) { 
		if (pshift <= 1) { 
			// block of length 1. No fiddling needed 
			long trail = numberOfTrailingZeros(p & ~1); 
			p = lsr(p, trail); 
			pshift += trail; 
		} else { 
			p <<= 2; 
			p ^= 7; 
			pshift -= 2; 
			smoothSortTrinkle(array, size, lsr(p,1), pshift + 1, head - smoothSortLP[pshift] - 1, 1,smoothSortLP); 
			smoothSortTrinkle(array, size, p, pshift, head - 1, 1,smoothSortLP); 
		} 
		head--; 
	} 
}

void smoothSort(long *array,long size){
	if(size > 1){
		long smoothSortLP[] = {1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 
            177, 287, 465, 753, 1219, 1973, 3193, 5167, 8361, 13529, 21891, 
            35421, 57313, 92735, 150049, 242785, 392835, 635621, 1028457, 
            1664079, 2692537, 4356617, 7049155, 11405773, 18454929, 29860703, 
            48315633, 78176337, 126491971, 204668309, 331160281, 535828591, 
            866988873 // the next number is > 31 bits. 
		};
		smoothSort2(array, size, 0, size - 1,smoothSortLP); 
	}
}






