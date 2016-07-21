#include <stdlib.h>
#include <stdio.h>


int partition(int array[], int start, int end) {
    int pivot = array[end];
    int i=0, pivotIndex=0;
    while(i <= end-1) {
        if(array[i] <= pivot) {
            int temp = array[i];
            array[i] = array[pivotIndex];
            array[pivotIndex] = temp;
            pivotIndex++;
        }
        i++;
    }
    int tempForSwap = array[end];
    array[end] = array[pivotIndex];
    array[pivotIndex] = tempForSwap;
    return pivotIndex;
}

void quickSort(int array[], int start, int end) {
    if(start >= end)
        return;
    int pivotIndex = partition(array, start, end);
    quickSort(array, start, pivotIndex-1);
    quickSort(array, pivotIndex +1, end);
}

int main() {
    int noOfElements,i;
    int *array;
    printf("\n ****** Quick Sort ******\n");
    printf("\nEnter no.of elements in array: ");
    scanf("%d", &noOfElements);
    array = (int*) calloc(noOfElements ,sizeof (int));
    printf("\n Enter elements of array: \n");
    for(i=0; i<noOfElements; ++i){
        scanf("%d", array+i);
    }
    quickSort(array, 0, noOfElements-1);
    printf("\n **** Sorted array is ***** \n");
    for(i=0; i<noOfElements; ++i){
        printf(" %d ", array[i]);
    }
    return 0;
}