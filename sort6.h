/****************************************************
REFERENCE

Author:
Link: https://www.geeksforgeeks.org/quick-sort/
****************************************************/


/* 
	Swaps two elements from an array

	@param int* a 			first element to swap
	@param int* b			second element to swap
	@param double *dCounter	counter variable for critical parts of the code
*/
void swapQuick(int* a, int* b, double* dCounter){
	int t = *a;
    *a = *b;
    *b = t;
	*dCounter += 1.0;
}


/* 
	Takes last element as pivot, puts pivot on correct position, then places elements to the left or right whether they're smaller or bigger

	@param int A[] 			array to be sorted
	@param int l			starting index
	@param int n			ending index
	@param double *dCounter	counter variable for critical parts of the code
*/
int partition(int A[], int l, int n, double* dCounter)
{
    int pivot = A[n];
    int i = (l-1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = l; j <= n - 1; j++) {
        // If current element is smaller than the pivot
        if (A[j] < pivot) {
            i++; // increment index of smaller element
            swapQuick(&A[i], &A[j], dCounter);
        }
    }
    swapQuick(&A[i + 1], &A[n], dCounter);
    return (i + 1);
}


/* 
	Function that is called to implement quicksort

	@param int A[] 			array to be sorted
	@param int l			starting index
	@param int n			ending index
	@param double *dCounter	counter variable for critical parts of the code
*/
void quick(int A[], int l, int n, double *dCounter){
	//i cant modify function prototypes so this is my workaround
	if(l<n){
		int pi = partition(A,l,n,dCounter);

		quick(A, l, pi-1, dCounter);
		quick(A, pi+1, n, dCounter);
	}
}

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using QuickSort sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void sort6(int A[], int n, double *dCounter) {
	//	your code here
	//i cant modify function prototypes so this is my workaround
	quick(A,0,n,dCounter);
}
 