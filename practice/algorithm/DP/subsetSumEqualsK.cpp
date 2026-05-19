#include <bits/stdc++.h> 
using namespace std ; 

/* 
    given an array Arr and an integer k check if there is exists a subset with sum k 
*/ 

bool subSetSumk(vector<int> &arr , int k ) { // this is for subarrays which are supposed to be contiguous 
    int left = 0; 
    int n = arr.size() ; 

    int sum = 0 ; 

    for(int right=0 ; right<n ; right++) {
        sum += arr[right] ;  
        if( sum == k ) {
            return true ; 
        } 
        else if( sum > k && left <= right ) {   
            while( sum > k ) {
                sum = sum - arr[left] ; 
                left++ ;
            }
        } 
    } 

    return false ; 
}  
 
// start from n-1 go till 0 in a pick and not pick fashion  
// TC = O(2^n)  
// SC = recursion stack space where I move in for n times 

bool f(int i , int target , vector<int> &arr) {
    if( target == 0 ) return true ;  
    if( i==0 ) {
        return arr[0] == target ; 
    }  

    bool notPick = f(i-1 , target , arr) ;  
    bool pick = false ; 

    if( arr[i] <= target ) {
        pick = f(i-1 , target - arr[i] , arr) ; 
    }

    return pick || notPick ;  
} 

bool f1(int i , int target , vector<int> &arr , vector<vector<bool>> &dp) {
    if( target == 0 ) return true ; 
    if( i==0 ) {
        return arr[i] == target ; 
    } 

    if( dp[i][target] != -1 ) return dp[i][target] ; 
    
    bool notPick = f1(i-1 , target , arr , dp) ; 
    bool pick = false ; 

    if( target >= arr[i] ) pick = f1(i-1 , target - arr[i] , arr , dp) ; 
    
    return dp[i][target] = pick || notPick ; 
}

/* 
    tabulation solution goes from n-1 to 0  
*/ 
bool f2(int target , vector<int> &arr){ 
    int n = arr.size() ; 
    vector<vector<bool>> dp(n , vector<bool>(target + 1 , 0)) ;  

    // start with the first row of i=0  
    for(int i=0 ; i<target ; i++) {
        dp[i][0] = true ; 
    } 

    // mark the dp[i][target] = true ;  
    dp[0][arr[0]] = true ; 

    // mark the remaining rows( 1 -> n-1 ) and the corresponding targets( 1 - k )  
    for(int i=1 ; i<n ; i++) {
        for(int j=1 ; j<=target ; j++) {
            bool notTake = dp[i-1][j] ; 
            bool take = false ; 

            if( arr[i] <= j ) take = dp[i-1][j - arr[i]] ;   

            dp[i][j] = take || notTake ; 
        } 
    } 

    return dp[n-1][target] ;
} 

// Space Optimization 
bool f3(int target , vector<int> &arr) {
    int n = arr.size() ;  

    vector<int> prev( target + 1 , 0 )  , curr( target + 1 ,0 ) ; 

    prev[0] = curr[0] = true ; 
    prev[arr[0]] = true ;  // for the first row ( first index = 0 )   

    for(int i=1 ; i<n ; i++) {
        for(int j=1 ; j<target + 1 ; j++) {
            bool notTake = prev[j] ; 

            bool take = false ; 
            if( arr[i] <= j ) take = prev[j - arr[i]] ;  
            
            curr[j] = take || notTake ; 
        } 

        prev = curr ; 
    }
    
    return prev[target] ; 
}
