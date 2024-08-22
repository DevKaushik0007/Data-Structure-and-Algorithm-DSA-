#include<iostream>
using namespace std;
bool binarySearch(int arr[][3],int rows,int cols, int target){
    int s = 0;
    int e = (rows*cols) -1;
    int mid = s+(e-s)/2;
    while(s<=e){
        int rowIndex = mid/cols;
        int colIndex = mid%cols;
        if(arr[rowIndex][colIndex] == target){
            cout<<"Element found at index ["<<rowIndex<<"]"<<"["<<colIndex<<"]";
            // return true;
        }
        if(arr[rowIndex][colIndex] < target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
}
        return false;
}
int main(){
    int arr[2][3] = {{10,20,30},{40,50,60}};
    int rows = 2;
    int cols = 3;
    int target = 60;
    bool ans = binarySearch(arr,rows,cols,target);
    if(ans)
    cout<<"found";
    else
    cout<<"Not Found";
    return 0;
}