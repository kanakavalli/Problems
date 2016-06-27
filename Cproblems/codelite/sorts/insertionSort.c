#include <stdlib.h>
#include <stdio.h>

void insertionSort(int noOfElements, int* array){
    int i,j;
    for(i=0; i<noOfElements-1; i++){
        if (*(array+i) > *(array+i+1)) {
            int temp = *(array+i);
            *(array+i) = *(array+i+1);
            *(array+i+1) = temp;
            for(j=i; j>0; j--) {
                if(*(array+j) < *(array+j-1)) {
                    int temp1 = *(array+j);
                    *(array+j) = *(array+j-1);
                    *(array+j-1) = temp1;
                }
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
    insertionSort(noOfElements, array);
    
    return 0;
}