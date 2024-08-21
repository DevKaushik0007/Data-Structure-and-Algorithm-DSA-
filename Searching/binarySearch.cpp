#include<iostream>
using namespace std;

int binarySearch( int arr[], int size, int target){
    int s = 0;
    int e = size-1;
    int m = s + (e - s) / 2;
    while(s<=e){
        int element = arr[m];
        if(element == target)
        return m;
        if(element < target){
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return -1;
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int target;
    cout<<"Enter element to be search, array is";
    cin>>target;
    int result = binarySearch(arr , size , target);
    if(result == -1)
        cout<<"Element not found";
    else{
    cout<<"Element found at "<<result<<" index";
    }
    return 0;
}