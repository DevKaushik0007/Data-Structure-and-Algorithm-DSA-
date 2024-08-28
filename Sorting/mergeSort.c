#include<stdio.h>
#include<stdlib.h>

int printArray(int *arr ,int size){
     for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
        printf("\n");
}

void merge(int arr[],int low,int mid,int high){
    int size = high-low+1;
    int *b = (int *)malloc(size * sizeof(int));
    if (b == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
         b[k++]=arr[i++];  
        }
        else{
            b[k++]=arr[j++];
        }
    }
    while(i<=mid){
          b[k++]=arr[i++];
    }
    while(j<=high){
          b[k++]=arr[j++];
    }
    for(int i=0;i<size;i++){
        arr[low+i] = b[i];
    }
    free(b);
}

int mS(int arr[],int low, int high){
    if(low<high){
        int mid = low + (high-low) / 2;
        mS(arr,low,mid);
        mS(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[] = {50,10,30,60,20,40};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr,size);
    mS(arr,0,size-1);
    printf("Sorted array: ");
    printArray(arr,size);
    return 0;
}