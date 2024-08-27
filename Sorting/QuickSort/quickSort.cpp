#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low +1;
    int j = high;
    while(i<=j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(int arr[], int low, int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        qs(arr, low,pIndex-1);
        qs(arr, pIndex+1,high);
    }
}
int main(){
    int arr[] = {2,5,1,4,8,0,6,3,7,0,4,4,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    qs(arr, 0,size -1);
    for(int i = 0; i<size; i++){
        cout<<arr[i];
    }
    
}