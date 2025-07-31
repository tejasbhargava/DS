#include<stdio.h>
#include<stdlib.h>
void RecursiveSelectionSort(int arr[], int n, int idx){
    int minidx = idx;
    if(idx == n - 1){
        return;
    }
    for(int i = idx; i < n; i++){
        if(*(arr + i) < *(arr + minidx)){
            minidx = i;
        }
    }
    int temp = *(arr + minidx);
    *(arr + minidx) = *(arr + idx);
    *(arr + idx) = temp;

    RecursiveSelectionSort(arr, n, idx + 1);

}

int main(){
    int n;
    scanf("%d", &n);

    int* arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Memory not available");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    RecursiveSelectionSort(arr, n, 0);

    for(int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    free(arr);
    return 0;
}
