#include <bits/stdc++.h> 
using namespace std ; 
 
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size() ; 
    
    int sum = 0 ; 
    int maxi = INT_MIN ; 

    for(int i=0 ; i<n ; i++) {
        sum = sum + nums[i]; 

        if( sum > maxi ) {
            maxi = sum ; 
        } 
        if( sum < 0 ) {
            sum = 0 ; 
        }
    }   

    sum = 0 ; 

    int minSum = INT_MAX ; 

    for(int i=0 ; i<n ; i++) {
        sum = sum + nums[i] ; 
        if( sum < minSum ){
            minSum = sum ; 
        } 

        if( sum > 0 ) {
            sum = 0 ; 
        }
    }
 

    return max( abs(maxi) , abs(minSum) )  ;
}

int main(){  
    /* 
        find the max absolute sum of subarrays  
        find max subarray sum  
        find min subarray sum 
        return the best absolute value   

        1 -3 2 3 -4 
    */  

    vector<int> nums = {1,-3,2,3,-4} ; 
    cout << maxAbsoluteSum(nums) << endl; 

}