#include <bits/stdc++.h> 
using namespace std ; 

/*  
    TC = O(N) 
    SC = O(1) 
*/ 

int maximum(vector<int> &arr) {
    int maxi = INT_MIN ;  

    for(int  x : arr) {
        if( x > maxi ) {
            maxi = x ; 
        }
    } 
    
    return maxi ; 
} 

int main(){
    vector<int> arr = {2,3,1,7,0} ; 
    
    cout << maximum(arr) << endl;  
    return 0 ; 
} 