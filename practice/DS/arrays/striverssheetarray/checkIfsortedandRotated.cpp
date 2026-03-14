// check if the array provided is sorted and rotated 

#include <iostream>  
#include <vector> 
#include <algorithm>

using namespace std ;

int main() {
    int n ;
    cin >> n ; 

    vector<int> arr(n)  ; 
    for( auto &it : arr ) cin >> it ; 

    // now check if it follows or not 

    if( is_sorted( arr.begin() , arr.end() )) {
        cout << "YES" << endl; 
    }

    int count = 0 ; 

    for(int i=1; i<n ; i++) {
        if( arr[i] < arr[i-1] ) count++ ; 
    }

    if( arr[n-1] > arr[0] ) count++ ;

    if( count > 1 ) cout << "No" << endl; 

    else {
        cout << "Yes" << endl; 
    }

    return 0 ; 
} 