#include <bits/stdc++.h> 
using namespace std ; 

using ll = long long ; 

int maxBuilding(int n , vector<vector<int>> &restrictions) {  
    // adding the first building restriction 
    restrictions.push_back({1,0}) ; 
    sort(restrictions.begin() , restrictions.end() ) ;  // sort it out 

    // adding the ending block restrictions
    if( restrictions.back()[0] != n ) {
        restrictions.push_back({n , n-1}) ; 
    } 

    int m = restrictions.size() ;  

    // left to right pass 
    for(int i=1 ; i<m ; i++) {
        int dis = restrictions[i][0] - restrictions[i-1][0] ; 
        restrictions[i][1] = min( restrictions[i][1] , dis + restrictions[i-1][1]); 
    } 

    // right to left pass 
    for(int i=m-2 ; i>=0 ; i--){
        int dis = restrictions[i+1][0] - restrictions[i][0] ; 
        restrictions[i][1] = min( restrictions[i][1] , dis + restrictions[i+1][1]); 
    } 

    long long ans = 0 ; 

    // finding the peak/max height of building between restrictions 
    for(int i=1 ; i<m ; i++){
        ll x1 = restrictions[i-1][0] ; 
        ll h1 = restrictions[i-1][1] ; 

        ll x2 = restrictions[i][0] ; 
        ll h2 = restrictions[i][1] ; 

        ll d = x2 - x1 ; 

        ans = max( ans , ( h1 + h2 + d) / 2) ; 
    } 

    return ans ; 
} 

