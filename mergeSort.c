#include "mergeSort.h"


/* 
	Sorts and merges the array A.

	@param int A[] 			array to be sorted
	@param int l			left index
	@param int x			middle index
	@param int n			array size/right index
*/
void merge(int A[], int l, int x, int n){
	int i, j, k;
	int n1 = x - l + 1;
	int n2 = n - x;

	int L[n1], R[n2];

    //left array
	for(i = 0; i < n1; i++)
		L[i] = A[l + i];
    //right array
	for(j=0; j < n2; j++)
		R[j] = A[x + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		A[k] = L[i];
		i++;
		k++;
	}

	while(j < n2){
		A[k] = R[j];
		j++;
		k++;
	}
}


/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void mergeSort(int A[], int n, double *dCounter) {
	//	your code here

    //left index
	int l = *dCounter;

	if((int)*dCounter < n){
        //middle index
		int x = l + (n - l) / 2;

        //sort first half
		mergeSort(A, x, dCounter);
        //sort second half
        *dCounter = x+1;
		mergeSort(A, n, dCounter);

		merge(A, l, x, n);
	}
}
