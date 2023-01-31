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

	for(i = 0; i < n1; i++)
		L[i] = A[l + i];
	for(j=0; j < n2; j++)
		R[j] = A[x + 1 + j];

	i = 0;
	j = 0;
	while(i < n1 && j <n2){
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

    //left index, n will serve as right index
    int l = 0;

    //dCounter to be used as right index variable in if statement
    dCounter = n;

	if(l < *dCounter){
        //middle index
		int x = l + (n - l) / 2;

        //sort first half
        dCounter = x;
		mergeSort(A, l, dCounter);
        //sort second half
        dCounter = n;
		mergeSort(A, x+1, dCounter);

		merge(A, l, x, n);
	}
}
