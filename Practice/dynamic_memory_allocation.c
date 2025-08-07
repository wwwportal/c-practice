#include <stdlib.h>
#include <stdio.h>

void intAlloc(){
    int* num = (int*)malloc(sizeof(int));
    *num = 999;
    printf("The number stored is %d\n", *num);
    free(num);
}

void intArrAlloc(){
    int* arr = (int*)malloc(10 * sizeof(int));
    int i;
    printf("Array of Integers: \n");
    for(i = 0; i<9; i++) {
        *(arr+i) = i*5;
        printf("[%d]: %d\n", i, arr[i]);
    }
}

void flipOrder(){
    /*use bubble sort*/
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int i;
    int temp;
    char swap = 1;
    while (swap == 1) {
        swap = 0;
        for(i = 0; i<n; i++) { /*should only go up to arr.len-1*/
            if(arr[i]<arr[i+1]) {
                swap = 1;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    printf("After reversing order: \n");
    for(i = 0; i<n; i++) {
        printf("%d \n", arr[i]);
    }
}

void intArrRealloc() {
    int n = 20;
    int * arr = (int*)realloc(n, sizeof(int));
    int i;
    int count = 0;
    for(i=0; i<n; i++){
        *(arr+count) = i;
        ++count;
        printf("%d\n", arr[i]);
    }
}

int main(){
    /*intAlloc();
    intArrAlloc();
    flipOrder();*/
    intArrRealloc();
    return 0;
}