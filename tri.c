#include "tri.h"

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
	if(size==1){ //Tableau de taille 1 deja trie
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

void triParTas(int * tree, int size){
	for(int i=size/2;i>=1;i--){
		tamiser(tree,i,size);
	}
	int tmp;
	for(int i=size;i>=2;i--){
		tmp=tree[i-1];
		tree[i-1]=tree[0];
		tree[0]=tmp;
		tamiser(tree,1,i-1);
	}
}

void tamiser(int * tree, node, int n){
	int k=node;
	int j=2*k;
	int tmp;
	while(j<=n){
		if(j<n && tree[j-1]<tree[j]){
			j++;
		}
		if (tree[k-1]<tree[j-1]){
			tmp=tree[k-1];
			tree[k-1]=tree[j-1];
			tree[j-1]=tmp;
			k=j;
			j=2*k;
		}else {
			j=n+1;
		}
	}
}