// grid problem codestudio 

#include <bits/stdc++.h> 
using namespace std ; 

int f1(int i ,int j, vector<vector<int>> &grid , int n) {
    if( i==n-1 ) return grid[n-1][j] ;  

    // there are no edge cases for out of bounds in this problem 
    int d = grid[i][j] + f1(i+1 , j) ;
    int dg = grid[i][j] + f1(i+1 , j+1) ; 

    return min( d , dg ) ; 
}  

// memoization - toptobottom - goes from 0 to n-1 then again to 0 
int f2(int i , int j , vector<vector<int>> &grid , int n , vector<vector<int>> &dp) { 
    if( i==n-1 ) return grid[n-1][j] ;  

    if( dp[i][j] != -1 ) return dp[i][j] ; 

    // there are no edge cases for out of bounds in this problem 
    int d = grid[i][j] + f2(i+1 , j) ;
    int dg = grid[i][j] + f2(i+1 , j+1) ; 

    return dp[i][j] = min( d , dg ) ; 
}

//  tabulation method - bottom up - goes from n-1 levels to 0th level 
int f3(int m , int n , vector<vector<int>> &grid , vector<vector<int>> &dp) {
    vector<vector<int>> dp(n , vector<int>(n , 0)) ;  
	
	for(int i=0 ; i<n ; i++) {
		dp[n-1][i] = grid[n-1][i] ; 
	} 

	for(int i=n-2 ; i>=0 ; i--) {
		for(int j=i ; j>=0 ; j--) { 
			int d = grid[i][j] + dp[i+1][j] ; 
			int dg = grid[i][j] + dp[i+1][j+1] ;  

			dp[i][j] = min(d , dg) ; 
		}
	} 

	return dp[0][0] ;
} 

int main(){

}