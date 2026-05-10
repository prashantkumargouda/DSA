// finding the minimum path sum for a grid 

#include <bits/stdc++.h> 
using namespace std ; 

int f1(int i, int j , vector<vector<int>> &nums) {
    if( i==0 && j==0 ) return nums[i][j] ; 
    if( i<0 || j<0 ) return INT_MAX ; 

    int up = nums[i][j] + f1(i-1 , j , nums) ; 
    int left = nums[i][j] + f1(i , j-1 , nums) ; 

    return up + left ; 
} 

int f2(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &dp) {
    if( i==0 && j==0 ) return grid[0][0] ; 
    if( i<0 || j<0 ) return 1e9 ; 

    if( dp[i][j] != -1 ) return dp[i][j] ; 
    int up = grid[i][j] + f2(i-1 , j , grid , dp ) ; 
    int left = grid[i][j] + f2( i , j-1 , grid , dp ) ; 

    return dp[i][j] = min(up , left); 
} 

// trying out the tabulation method 
int f3(int m , int n , vector<vector<int>> &grid , vector<vector<int>> &dp) {
    for(int i=0 ; i<m ; i++) {
        for(int j=0 ; j<n ; j++) {
            if( i==0 && j==0 ) dp[i][j] = grid[i][j] ;  
            else {
                int up = INT_MAX ; 
                int left = INT_MAX ; 

                if(i>0) up = grid[i][j] + dp[i-1][j] ; 
                if(j>0) left = grid[i][j] + dp[i][j-1] ;  

                dp[i][j] = min(up ,left) ;
            }
        }
    } 

    return dp[m-1][n-1] ; 
} 

int f4(int m , int n , vector<vector<int>> &grid) {
    vector<int> dp(n,0)  ; 

    for(int i=0 ; i<n ; i++) {
        vector<int> temp ; 
        for(int j=0 ; j<m ; j++) {
            if(i==0 && j==0) {
                dp[i] = grid[i][j] ; 
            } 
            else {
                int up = INT_MAX ; 
                int left = INT_MAX ; 

                if( i>0 ) up = grid[i][j] + dp[j] ;  
                if( j>0 ) left = grid[i][j] + temp[j-1] ; 

                temp[j] = min( up , left ) ; 
            }
        } 

        dp = temp ;  
    } 

    return dp[m-1] ;
} 

int main() {    
    
}