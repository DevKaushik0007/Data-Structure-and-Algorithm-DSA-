#include<iostream>
using namespace std;

int knapSack(int val[], int wt[], int W, int n){
    if(n == 0|| W == 0){
        return 0;
    }
    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    if(itemWt <= W){
        return max(knapSack(val, wt, W-itemWt, n-1) + itemVal, knapSack(val, wt, W, n-1));
    }
    else{
        return knapSack(val, wt, W, n-1);
    }
}

int main(){
    int val[] = {15,14,10,45,30};
    int wt[] = {2,5,1,3,4};
    int W = 7;
    int n = 5;
    cout<<knapSack(val, wt, W, n)<<endl;
    return 0;
}