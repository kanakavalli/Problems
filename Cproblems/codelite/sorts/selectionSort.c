#include <stdlib.h>
#include <stdio.h>

int getIndexOfMinElementInSubArray(int index, int array[], int noOfElements) {
    int minIndex = index;
    int i;
    for(i=index; i<noOfElements; i++){
        if(array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
    
void selectionSort(int noOfElements, int array[]){
    int i,j;
    for(i=0; i<noOfElements-1; i++) {
        int index = getIndexOfMinElementInSubArray(i+1, array, noOfElements);
        if(array[index] < array[i]) {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
    printf("Sorted elements are: ");
    for(i=0; i<noOfElements; ++i){
        printf("%d  ",array[i]);
    }
}

int main(){
    int noOfElements,i;
    int *array;
    printf("\nEnter no.of elements in array: ");
    scanf("%d", &noOfElements);
    array = (int*) calloc(noOfElements ,sizeof (int));
    printf("\n Enter elements of array: \n");
    for(i=0; i<noOfElements; ++i){
        scanf("%d", array+i);
    }
    selectionSort(noOfElements, array);
    
    return 0;
}