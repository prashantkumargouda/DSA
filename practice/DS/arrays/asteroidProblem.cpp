// return true if the asteroids cannot destroy the planet else return false ; 
/* 
    eg : 

    asteroids = [3,9,19,5,21] 
    mass = 10 

    it cannot destroy the mass 
    just check if the smallest element in the array can destroy the planet or not 
    if it can destroy then rest of the planets can also destroy 
    
*/ 

#include <bits/stdc++.h> 
using namespace std ; 

bool cannotDestroy(int mass , vector<int> &asteroids) {  
    sort( asteroids.begin() , asteroids.end() )  ;  

    for(int num : asteroids) {
        if( mass < num ) {
            return false ; 
        } 

        mass += num ; 
    } 

    return true ; 
} 

