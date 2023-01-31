/****************************************************
REFERENCE

Author:
Link: https://www.geeksforgeeks.org/merge-sort/
****************************************************/


/* 
	Sorts and merges the array A.

	@param int A[] 			array to be sorted
	@param int l			left index
	@param int x			middle index
	@param int n			array size/right index
*/
void merge(int A[], int l, int x, int n);


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void mergeSort(int A[], int n, double *dCounter);
