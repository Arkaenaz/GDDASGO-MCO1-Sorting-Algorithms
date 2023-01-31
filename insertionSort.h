/****************************************************
REFERENCE

Author:
Link: https://www.programiz.com/dsa/insertion-sort
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using insertion sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void insertionSort(int A[], int n, double *dCounter) {
	int i,j,nKey;
	for (i = 1; i < n; i++) {
		nKey = A[i];
		j = i - 1;
		while (nKey < A[j] && j>=0) {
		    A[j+1] = A[j];
			--j;
		}
	    A[j+1] = nKey;
    }
}