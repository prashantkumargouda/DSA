// unique grids 

#include <bits/stdc++.h> 
using namespace std ; 

int f(int i , int j) {
    if( i==0 && j == 0 ) return 1 ;  
    if( i < 0 || j < 0 ) return 0 ; 

    int up = f(i-1 , j) ; 
    int left = f( i , j-1 ) ; 

    return up + left ; 
} 

int f1(int i , int j , vector<vector<int>> &dp) {
    if( i==0 && j == 0 ) return 1 ;  
    if( i < 0 || j < 0 ) return 0 ; 

    if( dp[i][j] != -1 ) return dp[i][j] ; 

    int up = f1( i-1 , j , dp ) ; 
    int left = f1( i , j-1 , dp ) ; 

    return dp[i][j] = up + left ; 
} 

// tabulation solution eliminating space complexity 
// trying out the bottom up tabulation approach 
int f2(int m , int n , vector<vector<int>> &dp) {
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			if( i==0 && j==0 ) dp[i][j] = 1 ; 
			else{
				int up = 0 ; 
				int left = 0 ; 

				if( i > 0 ) up = dp[i-1][j] ;  
				if( j > 0 ) left = dp[i][j-1] ;  

				dp[i][j] = up + left ; 
			} 
		}
	} 

	return dp[m-1][n-1] ; 
}

// space optimization 
// using a single dp array along with a temp 
int f3(int m , int n ) {
    vector<int> dp( n , 0 ) ; 
    
    for(int i=0 ; i<m ; i++) {
        vector<int> temp( n , 0 ) ;  
        for(int j=0 ; j<n ; j++) {
            if( i==0 && j==0 ) {
                temp[j] = 1 ; 
            } 
            else{
                int up = dp[j] ;  
                int left = (j > 0) ? temp[j-1] : 0; 
                int left = temp[j-1] ;
                temp[j] = up + left ; 
            }
        } 

        dp = temp ; 
    } 

    return dp[n-1];

}


int unique(int m , int n) {
    vector<vector<int>> dp(m , vector<int>(n , 0)) ; 
    
    return f2( m , n , dp ) ; 
} 
