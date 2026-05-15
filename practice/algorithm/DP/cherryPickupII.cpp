// DP 3d grid problem 

#include <bits/stdc++.h> 
using namespace std ; 

int f(int i , int j1 , int j2 , vector<vector<int>> &grid) { 
    int n = grid.size() ; 
    int m = grid[0].size() ; 

    if( j1 < 0 || j1 >=m || j2 < 0 || j2>=m ) {
        return -1e8 ; 
    } 

    if( i==n-1 ) {
        if( j1 == j2 ) return grid[i][j1] ; 
        else {
            return grid[i][j1] + grid[i][j2] ; 
        }
    } 
    int maxi = -1e8 ; 
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++) {
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++) {
            if( j1 == j2 ) maxi = max(maxi , grid[i][j1] + f(i+1 , j1 + dj1 , j2 + dj2 , grid) ) ; 
            else {
                maxi = max( maxi , grid[i][j1] + grid[i][j2] + f(i+1 , j1 + dj1 , j2 + dj2 ,grid)) ; 
            }
        }
    } 

    return maxi ; 
} 
 
int f2(int i , int j1 , int j2 , vector<vector<int>> &grid , vector<vector<vector<int>>> &dp) {
    int n = grid.size() ; 
    int m = grid[0].size() ; 

    if( j1 < 0 || j1 >=m || j2 < 0 || j2>=m ) {
        return -1e8 ; 
    }   

    if( i==n-1 ) {
        if( j1 == j2 ) return grid[i][j1] ; 
        else {
            return grid[i][j1] + grid[i][j2] ; 
        }
    }   

    if( dp[i][j1][j2] != - 1 ) return dp[i][j1][j2] ; 

    int maxi = -1e8 ; 
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++) {
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++) {
            if( j1 == j2 ) maxi = max(maxi , grid[i][j1] + f2(i+1 , j1 + dj1 , j2 + dj2 , grid , dp) ) ; 
            else {
                maxi = max( maxi , grid[i][j1] + grid[i][j2] + f2(i+1 , j1 + dj1 , j2 + dj2 ,grid , dp)) ; 
            }
        }
    } 

    return dp[i][j1][j2] = maxi ; 

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) { 
    int n = grid.size() ; 
    int m = grid[0].size() ; 

    vector<vector<vector<int>>> dp(n , vector<vector<int>> (m ,vector<int>(m ,-1))) ;  

    // writing the base cases first 
    for(int j1 = 0 ; j1<m ; j1++) {
        for(int j2 = 0 ; j2<m ; j2++) {
            if( j1 == j2 ) dp[n-1][j1][j2] = grid[n-1][j1] ;  
            else{ 
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2] ; 
            }
        }
    } 

    // expanding the tabulation solution from top to bottom 
    for(int i=n-2 ; i>=0 ; i--) {
        for(int j1 = 0 ; j1 < m ; j1++) {
            for(int j2 = 0 ;j2 < m ; j2++) {
                int maxi = -1e8 ; 

                for(int dj1 = -1 ; dj1 <= 1 ; dj1++) {
                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++){ 
                        int value = 0 ; 
                        if( j1 == j2 ) {
                            value = grid[i][j1] ; 
                        } 
                        else {
                            value = grid[i][j1] + grid[i][j2] ; 
                        }
                    }
                }
            }
        }
    }
}   