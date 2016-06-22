#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int noOfElements, int* array){
    int i, j;
    for (i = 0; i < noOfElements; i++) {
        for (j = 0; j < noOfElements - 1; j++) {
            if (*(array+j) > *(array+j+1)) {
                int temp = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = temp;
            }
        }
    }
    printf("Sorted elements are: ");
    for(i=0; i<noOfElements; ++i){
        printf("%d  ",*(array+i));
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
    bubbleSort(noOfElements, array);
    
    return 0;
}