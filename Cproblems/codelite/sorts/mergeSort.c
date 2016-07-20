#include <stdlib.h>
#include <stdio.h>


void merge(int array[], int low, int mid, int high) {
    int i, j;
    int leftArrLen = mid - low +1;
    int rightArrLen = high - mid;
    int leftArr[leftArrLen];
    int rightArr[rightArrLen];
    for(i=0; i<leftArrLen; i++)
        leftArr[i] = array[low+i];
    for(i=0; i<rightArrLen; i++)
        rightArr[i] = array[mid+i+1];
        
    i = j = 0;
    int k = low;
    while(i < leftArrLen && j < rightArrLen) {
        if(leftArr[i] < rightArr[j]) {
            array[k] = leftArr[i];
            i++;
            k++;
        } else {
            array[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while(i < leftArrLen) {
        array[k] = leftArr[i];
        k++;
        i++;
    }
    while (j < rightArrLen) {
        array[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int array[], int low, int high){
    if(low == high) {
        return ;
    }
    int mid = (low+high)/2;
    mergeSort(array, low, mid);
    mergeSort(array, mid+1, high);
    merge(array, low, mid, high);
}


int main() {
    int noOfElements,i;
    int *array;
    printf("\nEnter no.of elements in array: ");
    scanf("%d", &noOfElements);
    array = (int*) calloc(noOfElements ,sizeof (int));
    printf("\n Enter elements of array: \n");
    for(i=0; i<noOfElements; ++i){
        scanf("%d", array+i);
    }
    mergeSort(array, 0, noOfElements-1);
    printf("\n **** Sorted array is ***** \n");
    for(i=0; i<noOfElements; ++i){
        printf(" %d ", array[i]);
    }
    return 0;
}