#include "generator.h"
#include "tri.h"

// Return 1 for success, 0 for failure

long testTriInsertion() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triInsertion(array,100);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}

long testTriFusion() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triFusion(array,100);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}

long testTriRapidePivotArbitraire() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triRapidePivotArbitraire(array,0, 99);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 2;
		}
	}
	array = generateReverseSortedArray(100);
	quickSortIterativeArbitraire(array,0,99);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}

long testTriRapidePivotAleatoire() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triRapidePivotAleatoire(array,0,99);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}

	array = generateReverseSortedArray(100);
	quickSortIterativeAleatoire(array,0,99);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 2;
		}
	}
	return 0;
}

long testTriRapidePivotOptimal() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triRapidePivotOptimal(array,0,99);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}

long testTriRapidePivotMed3() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triRapidePivotMed3(array,0,99);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}

long testTriParTas() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	triParTas(array,100);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}
long testQSort() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	sort(array,100);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}

long testSmoothSort() {
	long * array = generateReverseSortedArray(100);
	long * sorted = generateSortedArray(100);
	smoothSort(array,100);
	for(long i=0;i<100;i++){
		if(array[i]!=sorted[i]){
			return 1;
		}
	}
	return 0;
}