// maximum path sum 
// with variable starting and ending  

#include <bits/stdc++.h> 
using namespace std ; 

int f1(int i , int j ,int n ,int m , vector<vector<int>> &matrix , vector<vector<int>> &dp) {
    if( j<0 || j>=m ) return -1e9 ; 
    if( i==0 ) return matrix[0][j] ;  

    if( dp[i][j] != -1 ) return dp[i][j] ; 

    int s = matrix[i][j] + f1(i-1, j , n , m , matrix , dp)  ;  
    int ld = matrix[i][j] + f1(i-1 , j-1 , n , m , matrix , dp) ;  
    int rd = matrix[i][j] + f1(i-1 , j+1 , n , m , matrix , dp ) ; 

    return dp[i][j] = max( s , max( ld , rd )) ; 
} 

// tabulation method for this problem 
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size() ; 
    int m = matrix[0].size() ; 

    vector<vector<int>> dp(n , vector<int>(m , 0)) ; 

    for(int i=0 ; i<m ; i++) {
        dp[0][i] = matrix[0][i] ; 
    } 

    for(int i=1 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) { 
            int ld = -1e9 ; 
            int rd = -1e9 ; 

            int s = matrix[i][j] + dp[i-1][j] ; 
            
            if( j>0 ) ld = matrix[i][j] + dp[i-1][j-1] ; 
            if( j<m-1 ) rd = matrix[i][j] + dp[i-1][j+1] ; 

            dp[i][j] = max( max(ld , rd ) , s ) ; 
        }
    } 

    int maxi = dp[n-1][0] ; 

    for(int j=1 ; j<m ; j++) {
        maxi = max( maxi , dp[n-1][j] ) ;  
    } 

    return maxi ; 

} 

// Space Optimization  
int getMaxPathSum1(vector<vector<int>> &matrix)
{
    int n = matrix.size() ;  
    int m = matrix[0].size() ; 
     
    vector<int> dp(m,0) ; 

    for(int i=0 ; i<m ; i++) {
        dp[i] = matrix[0][i] ;
    }  

    for(int i=1 ; i<n ; i++) {
        vector<int> temp(m,0) ; 
        for(int j=0 ; j<m ; j++) {
            int ld = -1e9 ; 
            int rd = -1e9 ; 

            int s = matrix[i][j] + dp[j] ; 

            if( j>0 ) ld = matrix[i][j] + dp[j-1] ; 
            if( j<m-1 ) rd = matrix[i][j] + dp[j+1] ;  


            temp[j] = max( max(rd ,ld) , s ) ;  
        } 
        dp = temp ; 
    } 


    int maxi = dp[0] ; 

    for(int i=1 ; i<m ; i++){
        maxi = max( maxi , dp[i] ) ; 
    } 

    return maxi ; 

}

int main(){

    vector<vector<int>> matrix; 

    int n = matrix.size() ; 
    int m = matrix[0].size() ; 
    vector<vector<int>> dp(n , vector<int>(m , -1)) ; 

    int maxi = f1(n-1 , 0 , n , m , matrix , dp); 

    for(int j=1 ; j<m ; j++) {
        maxi = max( maxi , f1(n-1 , j , n , m , matrix , dp )) ; 
    } 

    return maxi ; 
}
