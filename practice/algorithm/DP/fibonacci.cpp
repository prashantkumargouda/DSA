// fibonacci using dp 

// 0 1 1 2 3 5 8 13 21  
// 0 1 2 3 4 5 6 7  8
#include <iostream>  
#include <vector> 

using namespace std ; 

int fibo1(int n) {
    if( n <= 1 ) {
        return n ; 
    } 

    return fibo1(n-1) + fibo1(n-2) ; 
} 

// memoization Approch
int fibo2(int ind , vector<int> &dp) {
    if( ind <= 1 ) return ind ; 
    
    if( dp[ind] != -1 ) return dp[ind] ; 

    return dp[ind] = fibo2(ind-1 , dp) + fibo2(ind - 2 , dp ) ; 
}   

// tabulation method - bottom up 
int fibo3(int ind , vector<int> &dp) {
    dp[0] = 0 ; 
    dp[1] = 1 ;  

    for(int i=2 ; i<=ind ; i++) {
        dp[i] = dp[i-1] + dp[i-2] ; 
    } 

    return dp[ind] ; 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> dp( n+1 , -1 ) ; 
    cout << fibo2( n, dp ) << endl; 

    return 0 ;
}