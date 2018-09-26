#include "tri.h"
#include "generator.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

const int MAX = 0;
const int TIMEOUT = 2000;

int main(int argc, char[]* argv) {
	
	if(argc==0){
		//Execute test
	}else if(argc!=3){
		exit(2);
	}
	else{
		int sortingAlgo = atoi(argv[1]);
		int generatorAlgo = atoi(argv[2]);
		int n = atoi(argv[3]);
		int * array;
		struct timespec t1,t2;
		
		switch(generatorAlgo){
			case 1:
				array = generateSortedArray(n);
				break;
			case 2:
				array = generateReverseSortedArray(n);
				break;
			case 3:
				array = generateConstantArray(n,20);
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
		switch(sortingAlgo){
			case 1:
				clock_gettime(CLOCK_REALTIME,&t1);
				triInsertion(array,n);
				clock_gettime(CLOCK_REALTIME,&t2);
				break;
			case 2:
				clock_gettime(CLOCK_REALTIME,&t1);
				triFusion(array,n);
				clock_gettime(CLOCK_REALTIME,&t2);
				break;
			case 3:
				clock_gettime(CLOCK_REALTIME,&t1);
				triParTas(array,n);
				clock_gettime(CLOCK_REALTIME,&t2);
				break;
			case 4:
				clock_gettime(CLOCK_REALTIME,&t1);
				//quicksort(array,n);
				clock_gettime(CLOCK_REALTIME,&t2);
				break;
			case 5:
				clock_gettime(CLOCK_REALTIME,&t1);
				//smoothsort(array,n);
				clock_gettime(CLOCK_REALTIME,&t2);
				break;
			case 6:
				clock_gettime(CLOCK_REALTIME,&t1);
				sort(array);
				clock_gettime(CLOCK_REALTIME,&t2);
				break;
		}
		long ns = t2.tv_nsec - t1.tv_nsec;
		printf("%ld",ns);
	}
    return 0;
}



