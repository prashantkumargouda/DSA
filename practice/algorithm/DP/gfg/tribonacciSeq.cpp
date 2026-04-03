// tribonacci Numbers 
// extension of fibonacci Numbers  
// a(n) = a(n-1) + a(n-2) + a(n-3) 
// 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, ....  


#include <iostream>  
#include <vector> 

using namespace std ; 

int tribonacci(int n , vector<int> &dp ) {
    if( n == 0 || n == 1) return 0 ; 
    if( n==2 ) return 1 ; 

    if( dp[n] != -1 ) {
        return dp[n] ; 
    } 
     
    return dp[n] = tribonacci( n-1 , dp ) + tribonacci( n-2 , dp ) + tribonacci( n-3  , dp ) ;    
} 
int main() {
    
}