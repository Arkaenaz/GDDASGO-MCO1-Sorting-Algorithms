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

void resetArray(int original[], int A[], int n) {
	int i;
	for (i=0;i<n;i++) {
        A[i] = original[i];
    }
}

void resetCounter(double dCounter[], int n) {
	int i;
	for (i=0;i<n;i++) {
		dCounter[i] = 0;
	}
} 

int main() {
	
	//	your code here
	int N = 65536;			// Change this to change the number of values in the array
	int nMaxRun = 10;		// Change this to change the number of runs

	int M;
	struct timespec timeStart;
	struct timespec timeEnd;
	double dElapsed[nMaxRun];
	double dCounter[nMaxRun];
	double dAverageCounter;

	int nSort;

	int aOriginal[N];
	int A[N];
	double dMET;

	generateData(aOriginal, N);
	//printArray(A, N);
	printf("-- N: %d --\n\n", N);
	for (nSort = 0; nSort < 6; nSort++) {
		resetCounter(dCounter, nMaxRun);
		switch(nSort) {
			case 0:
				printf("Bubble Sort:\n");
				break;
			case 1:
			    printf("Insertion Sort:\n");
                break;
			case 2:
			    printf("Selection Sort:\n");
                break;
            case 3:
			    printf("Merge Sort:\n");
                break;
            case 4:
			    printf("Sort 5:\n");
                break;
            case 5:
			    printf("Sort 6:\n");
                break;
		}
		for (M=0; M < nMaxRun; M++) {
			resetArray(aOriginal, A, N);
			timeStart = getTime();
			switch(nSort) {
				case 0: bubbleSort(A, N, &dCounter[M]); break;
                case 1: insertionSort(A, N, &dCounter[M]); break;
                case 2: selectionSort(A, N, &dCounter[M]); break;
				case 3: mergeSort(A, N, &dCounter[M]); break;
				case 4: sort5(A, N, &dCounter[M]); break;
				case 5: sort6(A, N, &dCounter[M]); break;
			}
			timeEnd = getTime();
			dElapsed[M] = getElapsed(timeStart, timeEnd);


			/* Remove Comment to see Elapsed Time and Counter per Run
			printf("Time Elapsed: %lf\n", dElapsed[M]);
			printf("Counter: %.lf\n\n", dCounter[M]);
			*/
		}
		dMET = computeAverage(dElapsed, nMaxRun);
		dMET = dMET * 1000;								// Converts it to milliseconds
		printf("Average MET: %lf milliseconds\n", dMET);
		dAverageCounter = computeAverage(dCounter, nMaxRun);
		printf("Average counter value: %.lf\n", dAverageCounter);
		printf("\n");
	}

	return 0;
}
