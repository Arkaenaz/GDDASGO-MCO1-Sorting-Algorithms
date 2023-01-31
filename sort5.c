#include "sort5.h"


void swap(int *nNum1, int *nNum2){
    int temp = *nNum1;
    *nNum1 = *nNum2;
    *nNum2 = temp;
}

void heapify(int arr[], int n, int i){
    int small, left, right;
    do{
        small = i;
        left  = 2 * i + 1;
        right = 2 * i + 2;

        if(left < n && arr[left] < arr[small]) small = left;
        if(right < n && arr[right] < arr[small]) small = right;

        if(small != i) swap(&arr[i], &arr[small]);
        
    }while(small != i);
}

void sort5(int A[], int n, double *dCounter){

    for(int i = n/2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }
}