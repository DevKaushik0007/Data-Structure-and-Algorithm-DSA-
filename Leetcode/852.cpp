// 852. Peak Index in a Mountain Array

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
int peakIndex(vector<int> arr){
    int s = 0;
    int e = arr.size()-1;
    int m = s + (e-s)/2;
    while(s<e){
        if(arr[m]<arr[m+1]){
            s = m+1;
        }
        else{
            e=m;
        }
        m = s +(e-s)/2;
    }
    return s;
}
    int peakIndexInMountainArray(vector<int>& arr) {
        return peakIndex(arr);
    }
};