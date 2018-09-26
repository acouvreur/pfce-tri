#include "tri.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int comp(const void *elem1, const void *elem2)
{
	int f = *((int *)elem1);
	int s = *((int *)elem2);
	return (f > s) - (f < s);
}

void triInsertion(int *array, int size)
{
	int x,j;
	for (int i = 1; i < size - 1; i++)
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

void triFusion(int *array, int size)
{
	if (size <= 1)
	{ //Tableau de taille 1 deja trie
		return;
	}
	int *buffer = malloc(sizeof(int) * size);
	triFusion2(array, size, buffer);
	for (int i = 0; i < size; i++)
	{
		array[i] = buffer[i];
	}
}

void triFusion2(int *array, int size, int *buffer)
{
	if (size == 1)
	{ //Tableau de taille 1 deja trie
		return;
	}
	else
	{
		//Coupe tableau en 2
		int newSize1 = size / 2;
		int newSize2 = size / 2 + size % 2;

		int *newArray1 = array;
		int *newArray2 = &(array[newSize1]);
		//Trie nouveau tableaux par recursion
		triFusion2(newArray1, newSize1, buffer);
		triFusion2(newArray2, newSize2, &(buffer[newSize1]));
		//Fusion des 2 tableau trie
		int i = 0;
		int y = 0;
		while (i + y < size)
		{
			if (i < newSize1)
			{
				if (y < newSize2)
				{
					if (newArray1[i] <= newArray2[y])
					{
						buffer[i + y] = newArray1[i];
						i++;
					}
					else
					{
						buffer[i + y] = newArray2[y];
						y++;
					}
				}
				else
				{
					buffer[i + y] = newArray1[i];
					i++;
				}
			}
			else
			{
				buffer[i + y] = newArray2[y];
				y++;
			}
		}
	}
}

/*---------------------------------------------------*/
/*---------------  QUICKSORT   ----------------------*/
/*---------------------------------------------------*/
/*---------------------------------------------------*/

int pivotArbitraire(int *array, int start, int end)
{
	// return start;
	// return end;
	// return end - start;

	return start;
}

int pivotAleatoire(int *array, int start, int end)
{
	return (rand() % end) + start;
}

int swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

int partitionner(int *array, int start, int end, int pivot)
{
	swap(&array[pivot], &array[end]);

	for (int i = start; i < end; i++)
	{
		if (array[i] <= array[end])
		{
			swap(&array[i], &array[start]);
			start++;
		}
	}
	swap(&array[end], &array[start]);
}

void triRapidePivotArbitraire(int *array, int start, int end)
{
	int pivot;
	if (start < end)
	{
		pivot = pivotArbitraire(array, start, end);
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot - 1);
		triRapidePivotArbitraire(array, pivot + 1, end);
	}
}

void triRapidePivotAleatoire(int *array, int start, int end)
{
	int pivot;
	if (start < end)
	{
		pivot = pivotArbitraire(array, start, end);
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot - 1);
		triRapidePivotArbitraire(array, pivot + 1, end);
	}
}

void triRapidePivotOptimal(int *array, int start, int end)
{
	int pivot;
	if (start < end)
	{
		pivot = pivotArbitraire(array, start, end); //TODO: change to call optimal pivot
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot - 1);
		triRapidePivotArbitraire(array, pivot + 1, end);
	}
}


void tamiser(int *tree, int node, int n)
{
	int k = node;
	int j = 2 * k;
	int tmp;
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

void triParTas(int *tree, int size)
{
	for (int i = size / 2; i >= 1; i--)
	{
		tamiser(tree, i, size);
	}
	int tmp;
	for (int i = size; i >= 2; i--)
	{
		tmp = tree[i - 1];
		tree[i - 1] = tree[0];
		tree[0] = tmp;
		tamiser(tree, 1, i - 1);
	}
}

void sort(int *array)
{
	qsort(array, sizeof(array) / sizeof(array[0]), sizeof(array[0]), comp);
}