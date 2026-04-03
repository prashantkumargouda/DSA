// maximum no of points with cost 

#include <iostream> 
#include <vector> 
#include <climits> 
#include <algorithm> 

typedef long long ll ; 

using namespace std ;  

long long maxP(int ind , int last , vector<vector<int>> &points , int m , vector<vector<int>> &dp) {
    if( ind == 0 ) {
        ll maxi = LLONG_MIN ; 
        for(int i=0 ; i<m ; i++) {
            maxi = max( maxi , (ll)points[ind][i] - abs( i - last ) ) ;  
        } 
        return maxi ; 
    }  

    if( dp[ind][last] != -1 ) return dp[ind][last] ; 
    ll maxi = LLONG_MIN ; 

    for(int i=0 ; i<m ; i++) { 
        ll check = points[ind][i] - abs( i - last ) ;  
        maxi = max( maxi , check );  
    } 


    return dp[ind][last] = maxi ; 
} 

int main() { 
    int n , m ; 
    cin >> n >> m ; 

    vector<vector<int>> dp( n , vector<int>( m , -1 )) ;  


}