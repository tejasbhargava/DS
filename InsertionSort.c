#include<stdio.h>

void insertionSort(int arr[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }  
}