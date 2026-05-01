// grid unique path II  

#include <bits/stdc++.h> 
using namespace std ; 

// grid unique paths problem with obstacles  
int f(int i , int j , vector<vector<int>> &nums) {
    if( i==0 && j==0 ) return 1 ; 
    if( i<0 || j<0 ) return 0 ; 

    if( i>=0 && j>=0 && nums[i][j] == -1) {
        return -1 ; 
    } 

    int up = f(i-1 , j , nums); 
    int left = f(i , j-1 , nums)  ; 

    return up + left ; 
} 

// overlapping subproblems 
int f1(int i , int j , vector<vector<int>> &nums , vector<vector<int>> &dp) {
    if( i==0 && j==0 ) return 1 ; 
    if( i<0 || j<0 ) return 0 ; 

    if( i>=0 && j>=0 && nums[i][j] == -1) {
        return -1 ; 
    }  

    if( dp[i][j] != -1 ) return dp[i][j] ; 

    int up = f1(i-1 , j , nums , dp); 
    int left = f1( i , j-1 , nums , dp ); 

    return dp[i][j] = up + left ; 
} 

// tabulation method 
// bottom up 
int f2(int m , int n , vector<vector<int>> &nums) {
    vector<vector<int>> dp(m , vector<int>(n , 0)) ; 

    for(int i=0 ; i<m ; i++) {
        for(int j=0 ; j<n ; j++) {
            if( i>=0 && j>=0 && nums[i][j] == 1 ) {
                dp[i][j] = 0 ; 
            } 
            else if( i==0 || j==0 ) {
                dp[i][j] = 0 ; 
            }
            else {
                int up = 0 ; 
                int left = 0 ; 

                if( i>0 ) up = dp[i-1][j] ; 
                if( j>0 ) left = dp[i][j-1] ; 

                dp[i][j] = up + left ; 
            }  
        }
    }

    return dp[m-1][n-1] ;
} 

int main(){
    
}