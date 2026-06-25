// GAS STATION 

#include <bits/stdc++.h> 
using namespace std ; 

int canCompleteCircuit(vector<int> &gas , vector<int> &cost) {  
    int n = gas.size() ; 
    int totalGas = 0 ; 
    int totalCost = 0 ; 

    int start = 0 ; 
    int total = 0 ; 

    for(int i=0 ; i<n ; i++){
        totalCost += cost[i] ; 
        totalGas += gas[i] ; 

        total += gas[i] - cost[i] ; 

        if( total < 0 ) {
            total = 0 ; 
            start = i + 1 ; 
        } 
    }  

    return (totalCost - totalGas) > 0 ? -1 : start ; 
} 

