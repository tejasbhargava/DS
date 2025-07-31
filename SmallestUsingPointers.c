#include<stdio.h>
#include<stdlib.h>
int smallest(int* arr, int n){
    int min_idx = 0;
    for(int i = 0; i < n; i++){
        if(*(arr +i)< *(arr + min_idx)){
            min_idx = i;
        }
    }
    return min_idx;
}
int main(){
    int n;
    printf("enter number of elements");
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory not available");
        return 1;
    }
    printf("enter elements of array");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int idx = smallest(arr, n);
    printf("the smallest number in the array is %d", *(arr + idx));

    free(arr);
    return 0;
}