#include "mergeSort.h"


/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void mergeSort(int A[], int n, double *dCounter){
	//i = index, j = index left, k = index right
	int i, j, k;

	//middle index
	int x = 0 + n / 2;

	//left array size
	int n1 = x + (n%2);
	//right array size
	int n2 = n - x;

	int L[n1], R[n2];

	//left array
	for(i = 0; i < n1; i++){
		L[i] = A[i];
	}
    //split further if at least 3 or more items in array
	if(n1>2){
		mergeSort(L,n1,dCounter);
	}
	

    //right array
	for(j=0; j < n2; j++){
		R[j] = A[x + 1 + j];
	}
    //split further if at least 3 or more items in array
	if(n2>2){
		mergeSort(R,n2,dCounter);
	}

	i = 0;
	j = 0;
	k = 0;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		*dCounter += 1.0;
		k++;
	}

	while(i < n1){
		A[k] = L[i];
		*dCounter += 1.0;
		i++;
		k++;
	}

	while(j < n2){
		A[k] = R[j];
		*dCounter += 1.0;
		j++;
		k++;
	}
}