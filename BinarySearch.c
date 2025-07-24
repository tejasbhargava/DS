#include <stdio.h>

int binarySearch(int arr[], int n, int ele){
    int idx = -1;
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == ele){
            idx = mid;
            break;
        }
        if(arr[mid] > ele){
            high = mid -1;
        }
        if(arr[mid] < ele){
            low = mid + 1;
        }
    }
    return idx;
}
int main(){

    int n, ele;
    printf("enter number of elements");
    scanf("%d", &n);
    int arr[n];
    printf("enter element to be searched");
    scanf("%d", &ele);
    printf("enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int idx = binarySearch(arr, n, ele);
    if(idx == -1){
        printf("not found");
    }
    else{
        printf("%d element found at index %d", ele, idx);
    }
    return 0;
}
