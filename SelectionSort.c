#include<stdio.h>

void selectionSort(int arr[], int n){
    int idx;
    for(int i = 0; i < n; i++){
        idx = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[idx]){
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

int main(){
    int n;
    printf("enter number of elements");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }  
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    } 
    selectionSort(arr, n);
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }  
}