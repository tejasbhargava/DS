#include<stdio.h>

int linearSearch(int arr[], int n, int ele){
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele){
            idx = i;
        }
    }
    return idx;
}
int main(){

    int n, ele;
    printf("enter number of elements in array");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("enter element to be searched ");
    scanf("%d", &ele);
    
    int idx = linearSearch(arr, n, ele);
    if(idx == -1){
        printf("not found");
    }
    else{
        printf("%d element found at index %d", ele, idx);
    }
    return 0;
}
