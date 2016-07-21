#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool createMaxHeap(int array[], int arrayLength) {
    int position = arrayLength/2;
    int i;
    bool isMaxHeapCreated = true;
    while(position >= 0) {
        int leftChildIndexOfPosition = (2*position) +1;
        int rightChildIndexOfPosition = leftChildIndexOfPosition +1;
        if(leftChildIndexOfPosition < arrayLength) {
            if(array[position] < array[leftChildIndexOfPosition]) {
                int temp = array[position];
                array[position] = array[leftChildIndexOfPosition];
                array[leftChildIndexOfPosition] = temp;
                isMaxHeapCreated = false;
            }
        }
        if(rightChildIndexOfPosition < arrayLength) {
            if(array[position] < array[rightChildIndexOfPosition]) {
                int temp = array[position];
                array[position] = array[rightChildIndexOfPosition];
                array[rightChildIndexOfPosition] = temp;
                isMaxHeapCreated = false;
            }
        }
        position--;
    }
    return isMaxHeapCreated;
}

void deleteFromMaxHeap(int array[], int arrayLength) {
    int temp = array[0];
    array[0] = array[arrayLength -1];
    array[arrayLength-1] = temp;
    createMaxHeap(array, arrayLength-1);
}

void heapify(int array[], int length) {
    bool isMaxHeapCreated = false;
    while(!isMaxHeapCreated) {
        isMaxHeapCreated = createMaxHeap(array, length);
    }
}

void heapSort(int array[], int arrayLength) {
    bool isMaxHeapCreated = false;
    bool anyNodesSwapped = true;
    int i=arrayLength-1;
    while(i >0) {
        heapify(array, arrayLength);
        deleteFromMaxHeap(array, arrayLength);
        arrayLength--;
        i--;
    }
}

int main() {
    int noOfElements,i;
    int *array;
    printf("\n ****** Heap Sort ******\n");
    printf("\nEnter no.of elements in array: ");
    scanf("%d", &noOfElements);
    array = (int*) calloc(noOfElements ,sizeof (int));
    printf("\n Enter elements of array: \n");
    for(i=0; i<noOfElements; ++i){
        scanf("%d", array+i);
    }
    heapSort(array, noOfElements);
    printf("\n **** Sorted array is ***** \n");
    for(i=0; i<noOfElements; ++i){
        printf(" %d ", array[i]);
    }
    return 0;
}