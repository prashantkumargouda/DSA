// find the minimum cost of buying candies with discount 

#include <bits/stdc++.h>
using namespace std ; 


/* 
    6,5,7,9,2,2  - 9 7 6 5 2 2   
    6,35,7,9,2,2,10 - 35 10 9 7 6 2 2 
*/ 

int minimumCost(vector<int> &cost) {
    int n = cost.size() ; 

    if( n <= 2 ) {
        return accumulate( cost.begin() , cost.end() , 0); 
    } 

    sort( cost.begin() , cost.end() , greater<int>() ) ; 
    int totalCost = 0 ; 

    int k = 1 ; 

    for(int i=0 ; i<n ; i++){
        if( k % 3 == 0 ) {
            k++ ; 
            continue ; 
        } 

        k++ ; 
        totalCost += cost[i] ; 
    }

    return totalCost ;
} 

