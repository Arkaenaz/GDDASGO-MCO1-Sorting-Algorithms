/****************************************************
REFERENCE

Author: 
Link: https://www.programiz.com/dsa/selection-sort
****************************************************/

/*
	You may declare additional functions here
*/


/*
	Swaps two(2) array indexes with one another

	@param int *nValue1     value #1
	@param int *nValue2     value #2
*/
void swap(int *nValue1, int *nValue2)
{
    int temp;
    temp = nValue1;
    nValue1 = nValue2;
    nValue2 = temp;
}

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/

/*
	Sorts the array A using selection sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void selectionSort(int A[], int n, double *dCounter)
{
    for (int i = 0; i < n; i++)
    {
        int nMinimum = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[nMinimum])
                nMinimum = j;
        }

        swap(&A[i], &A[nMinimum]);
    }
}
