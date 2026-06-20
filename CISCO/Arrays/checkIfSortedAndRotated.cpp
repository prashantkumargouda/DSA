#include <bits/stdc++.h>
using namespace std ; 

/*  
    3 4 5 1 2  
    3 4 5  1 2  

    7 9 1 1 1 3 
    7 9  1 1 1 3
*/
bool checkSorted(vector<int> &arr) {
    // counting the number of breaks  
    int count = 0 ; 
    int n = arr.size() ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] > arr[(i+1) % n]) {
            count++ ; 
        }
    } 

    return count <= 1 ; 
} 

