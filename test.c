#include "generator.h"
#include "tri.h"

// Return 1 for success, 0 for failure

int testTriInsertion() {
	int * array = generateReverseSortedArray(100);
	int * sorted = generateSortedArray(100);
	triInsertion(array,100);
	for(int i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 0;
		}
	}
	return 1;
}

int testTriFusion() {
	int * array = generateReverseSortedArray(100);
	int * sorted = generateSortedArray(100);
	triFusion(array,100);
	for(int i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 0;
		}
	}
	return 1;
}

int testTriRapidePivotArbitraire() {
	int * array = generateReverseSortedArray(100);
	int * sorted = generateSortedArray(100);
	triRapidePivotArbitraire(array,0,100);
	for(int i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 0;
		}
	}
	return 1;
}

int testTriRapidePivotAleatoire() {
	int * array = generateReverseSortedArray(100);
	int * sorted = generateSortedArray(100);
	triRapidePivotAleatoire(array,0,100);
	for(int i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 0;
		}
	}
	return 1;
}

int testTriRapidePivotOptimal() {
	int * array = generateReverseSortedArray(100);
	int * sorted = generateSortedArray(100);
	triRapidePivotOptimal(array,0,100);
	for(int i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 0;
		}
	}
	return 1;
}

int testTriParTas() {
	int * array = generateReverseSortedArray(100);
	int * sorted = generateSortedArray(100);
	triParTas(array,100);
	for(int i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 0;
		}
	}
	return 1;
}