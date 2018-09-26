
void triInsertion(int * array, int size){
	int min,minPos;
	for(int i=0;i<size-1;i++){
		//Recherce du minimum
		min=array[i];minPos=i;
		for(int y=i+1;y<size;y++){
			if(array[y]<min){
				min=array[y];
				minPos=y;
			}
		}
		//Swap
		if(minPos!=i){
			array[minPos]=array[i];
			array[i]=min;
		}
	}
}


void triFusion(int * array, int size){
	if(size<=1){ //Tableau de taille 1 deja trie
		return;
	}
	else {
		//Coupe tableau en 2
		int newSize1 = size/2;
		int newSize2 = size/2 + size%2;
		int * newArray1 = malloc(sizeof(int)*newSize1);
		for(int i=0;i<newSize1;i++){
			newArray1[i]=array[i];
		}
		for(int i=0;i<newSize2;i++){
			newArray1[i]=array[i+newSize1];
		}
		int * newArray2 = malloc(sizeof(int)*newSize2);
		//Trie nouveau tableaux par recursion
		triFusion(newArray1,newSize1);
		triFusion(newArray2,newSize2);
		//Fusion des 2 tableau trie
		int i=0;int y=0;
		while(i+y<size){
			if(i<newSize1){
				if(y<newSize2){
					if(newArray1[i]<=newArray2[y]){
						array[i+y] = newArray1[i];
						i++;
					}
					else{
						array[i+y] = newArray2[y];
						y++;
					}
				}
				else{
					array[i+y] = newArray1[i];
						i++;
				}
				
			}else{
				array[i+y] = newArray2[y];
						y++;
			}
		}
		free(newArray1);free(newArray2);
	}

}

/*---------------------------------------------------*/
/*---------------  QUICKSORT   ----------------------*/
/*---------------------------------------------------*/
/*---------------------------------------------------*/

int pivotArbitraire(int* array, int start, int end) {
	// return start;
	// return end;
	// return end - start;

	return start;
}

int pivotAleatoire(int* array, int start, int end) {
	return (rand() % end) + start;
}

int swap(int* i, int* j) {
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

int partitionner(int* array, int start, int end, int pivot) {
	swap(&array[pivot], &array[end]);

	for (int i = start; i < end; i++) {
		if(array[i] <= array[end]) {
			swap(&array[i], &array[start]);
			start++;
		}
	}
	swap(&array[end], &array[start]);
}

void triRapidePivotArbitraire(int * array, int start, int end) {
	int pivot;
	if(start < end) {
		pivot = pivotArbitraire(array, start, end);
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot-1);
		triRapidePivotArbitraire(array, pivot+1, end);
	}
}

void triRapidePivotAleatoire(int * array, int start, int end) {
	int pivot;
	if(start < end) {
		pivot = pivotArbitraire(array, start, end);
		pivot = partitionner(array, start, end, pivot);
		triRapidePivotArbitraire(array, start, pivot-1);
		triRapidePivotArbitraire(array, pivot+1, end);
	}
}