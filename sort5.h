/****************************************************
REFERENCE

Author:
Link:https://www.programiz.com/dsa/heap-sort
****************************************************/


/* 
	You may declare additional functions here
*/

/*
	Swaps two(2) array indexes with one another

	@param int *nValue1     value #1
	@param int *nValue2     value #2
*/
void swapHeap(int *nNum1, int *nNum2){
    int temp = *nNum1;
    *nNum1 = *nNum2;
    *nNum2 = temp;
}

/*
	This function does the tree node comparison between parent and child nodes.

	@param int arr[] 		array to be sorted
	@param int n			size of the array to be sorted
	@param int i            array index
	@param double *dCounter	counter variable for critical parts of the code
*/
void heapify(int arr[], int n, int i, double *dCounter){
    int small, left, right;
    do{
        small = i;
        left  = 2 * i + 1;
        right = 2 * i + 2;

        if(left < n && arr[left] < arr[small]){
            small = left;
            *dCounter += 1;
        }
        if(right < n && arr[right] < arr[small]){
            small = right;
            *dCounter += 1;
        }
        

        if(small != i){
            swapHeap(&arr[i], &arr[small]);
            *dCounter += 1;
            }
        
        
        
    }while(small != i);
}


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using Heap sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void sort5(int A[], int n, double *dCounter){

    for(int i = n/2 - 1; i >= 0; i--){
        *dCounter += 1;
        heapify(A, n, i, dCounter);
    }
}
