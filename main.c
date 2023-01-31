/****************************************************
Group: 		
Section:	
Members:	
****************************************************/

#include <stdio.h>
#include <time.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "sort5.h"
#include "sort6.h"
#include "generateData.h"
#include "timer.h"

void printArray(int A[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\n",A[i]);
	}
	printf("\n");
}

double computeAverage(double dArray[], int nSize) {
	double dSum = 0;
    int i;
    for (i = 0; i < nSize; i++) {
        dSum += dArray[i];
    }
    return dSum / nSize;
}

int main() {
	
	//	your code here
	int N = 65536;			// Change this to change the number of values in the array
	int nMaxRun = 10;		// Change this to change the number of runs

	int M;
	struct timespec timeStart;
	struct timespec timeEnd;
	double dElapsed[nMaxRun];
	double dCounter;

	int A[N];
	double dMET;

	generateData(A, N);
	//printArray(A, N);
	printf("-- N: %d --\n\n", N);
	printf("Insertion Sort:\n");
	for (M=0; M < nMaxRun; M++) {
		timeStart = getTime();
		insertionSort(A,N,&dCounter);
		//printArray(A, N);
		timeEnd = getTime();
		dElapsed[M] = getElapsed(timeStart, timeEnd);
	}
	dMET = computeAverage(dElapsed, nMaxRun);
	printf("Average MET: %lf milliseconds\n", dMET);
	printf("Average counter value: %lf", dCounter);

	return 0;
}
