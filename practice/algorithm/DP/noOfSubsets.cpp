/*

You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.



Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.

*/ 

#include <bits/stdc++.h> 
using namespace std ; 

int check(vector<int> &arr ,int ind ,int sum , vector<vector<int>> &dp) {  
    // TC - O(N X sum) 
    // SC - O(N X sum) + stack space 
    if( sum == 0 ) return 1 ; 
    if( ind == 0 ) {
        return arr[ind] == sum ; 
    }  

    if( dp[ind][sum] != - 1) return dp[ind][sum] ; 

    int notPick = check(arr , ind - 1, sum , dp) ; 
    int pick = 0 ; 
    if( arr[ind] <= sum ) pick = check( arr, ind - 1 , sum - arr[ind] , dp ) ;  

    return dp[ind][sum] = pick + notPick  ;
} 

 
