// find the minimum no of jumps to raech end 

#include <bits/stdc++.h> 
using namespace std ;  

int check(vector<int> &nums) {
    int jumps = 0 , farthest = 0 , currEnd = 0 ; 

    for(int i=0 ; i<nums.size() - 1 ; i++) {
        farthest = max( farthest , nums[i] + i ) ; 

        if( i == currEnd ) {
            jumps++ ; 
            currEnd = farthest ; 
        }
    } 

    return jumps ; 
} 

int check2(int ind , vector<int> &nums) {
    if(ind >= nums.size() - 1) return 0 ; 

    int sum = INT_MAX ;  

    for(int i=0 ; i<= nums[ind] ; i++){
        int jumps = check2( ind + i , nums ) ;  

        if( jumps != INT_MAX ) {
            sum = max( sum , jumps + 1 ) ;
        } 
    } 

    return sum ; 
} 


int check3(int ind , vector<int> &nums , vector<int> &dp) { 
    vector<int> dp( nums.size() , -1 ) ; 

    if(ind >= nums.size() - 1) return 0 ;  

    if( dp[ind] != -1 ) return dp[ind] ;  

    int sum = INT_MAX ;  

    for(int i=0 ; i<= nums[ind] ; i++){
        int jumps = check2( ind + i , nums ) ;  

        if( jumps != INT_MAX ) {
            sum = max( sum , jumps + 1 ) ;
        } 
    } 

    return dp[ind] = sum ; 
} 

 
