// finding the maximum ice cream bars one can buy

#include <bits/stdc++.h> 
using namespace std ; 

int maxIceCream(vector<int> &costs , int coins) {
    int n = costs.size() ; 

    sort(costs.begin() , costs.end())  ; 

    int count = 0 ; 
    for(auto &it : costs) {
        while( coins > it ) {
            coins -= it ; 
            count++ ;
        }
    } 

    return count ; 
}