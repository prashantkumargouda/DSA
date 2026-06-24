// Longest Increasing Subsequence 

#include <bits/stdc++.h> 
using namespace std ; 

int lengthOf(vector<int> &nums) {
    int n = nums.size() ; 

    // initialized the subarray with 1 to n-1 
    vector<int> dp(n , 1) ; 

    for(int i=0 ; i<n ; i++){
        for(int j=1 ; j<i ; j++){
            if( nums[i] > nums[j] ) {
                dp[i] = max( dp[i] , dp[j] + 1 ) ; 
            }
        }
    } 

    int maxi = *max_element( dp.begin() , dp.end() ) ; 
    
    return maxi ; 
}  

int lengthOf(vector<int> &nums) {
    int n = nums.size() ; 
    vector<int> tails ; 

    for(int num : nums) {
        auto it = lower_bound(tails.begin() , tails.end() , num) ;  // this returns an iterator 

        if( it == tails.end() ) { // if there are no elements greater than num ( >= num ) 
            tails.push_back(num) ; 
        } 
        else { // if there are elements >= num we replace
            *it = num ;      // it( iterator ) is replaced with num 
        }
    } 

    return tails.size() ; 
}

