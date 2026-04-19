// Tab Closing 

#include <bits/stdc++.h> 
using namespace std ; 

int main() { 
    int t ; 
    cin >> t ;
    
    while(t--) {
        int a, b , n ; 
        cin >> a >> b >> n ;  

        if( a==b || a/b >= n ) {
            cout << 1 << endl; 
        } 
        else {
            cout << 2 << endl; 
        }
    } 

    return 0 ; 
}