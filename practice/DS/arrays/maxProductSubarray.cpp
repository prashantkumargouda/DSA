/*
    finding the maximum product subarray  
    2 3 -2 4  

    so kadanes lag raha hai yeh with product 
    ignore when prod is less than 0  

*/ 

#include <bits/stdc++.h> 
using namespace std ; 

int maxProduct(vector<int> &nums) {
    int prod = nums[0] ; 
    int maxi = nums[0] ; 
    int n = nums.size() ; 
    int mini = nums[0] ; 

    for(int i=1 ; i<n ; i++) {
        if( nums[i] < 0 ) {
            swap(maxi ,mini) ; 
        } 

        maxi = max( nums[i] , maxi * nums[i] ) ;  
        mini = min( nums[i] , mini * nums[i] ) ;   

        prod = max( maxi , prod ) ; 
    } 

    return prod ; 
}

int main(){
    vector<int> nums = {2 , 3 , -2 , 4} ;  

    cout << maxProduct(nums) << endl;  
    return 0 ; 
}