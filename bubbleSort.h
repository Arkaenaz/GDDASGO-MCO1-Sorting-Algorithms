/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/

void swapBubble (int *nValue1, int *nValue2) {
	int nTemp;
    nTemp = *nValue1;
    *nValue1 = *nValue2;
    *nValue2 = nTemp;
}

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using bubble sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void bubbleSort(int A[], int n, double *dCounter) {
	//	your code here
    int i, j;

	for(i = 0; i < n; i++) {
		for(j = (n-1); j >= i+1; j--) {
        	if(A[j] < A[j-1]) {
            	swapBubble(&A[j], &A[j-1]);
				*dCounter += 1;
			}
      	}
   }
}

