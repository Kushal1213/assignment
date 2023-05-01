#include <stdio.h>

int count = 0;

void divide(int arr[], int low, int high){
    if(low == high){
        return;
    }
    int mid = (low + high) / 2;
    divide(arr, low, mid);
    divide(arr, mid+1, high);
    count++;
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    divide(arr, 0, n-1);
    printf("Number of iterations: %d", count);
    return 0;
}