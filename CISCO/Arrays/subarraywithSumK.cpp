#include <bits/stdc++.h> 
using namespace std ; 

int solve(vector<int> &nums ,int k) {
    int n = nums.size() ; 
    int left = 0 , right = 0 ; 

    int maxi = INT_MIN; 
    int sum = 0 ; 

    while( right < n ) { 
        while( left <= right && sum > k ) {
            sum = sum - nums[left] ; 
            left++ ; 
        } 

        if( sum == k ) {
            maxi = max( maxi , right - left + 1 ) ; 
        } 

        right++ ; 
        if( right < n ) sum += nums[right] ; 

    } 

    return maxi ; 
}