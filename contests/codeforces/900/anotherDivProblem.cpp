//  Another Divisibility Problem 

#include <bits/stdc++.h> 
using namespace std ; 

int concate(int n , int m) {
    while(m != 0) {
        int x = m % 10  ; 
        n = n * 10 + x ; 
        m = m / 10 ; 
    } 

    return n ;
}

int rev(int m) {
    int check = 0 ; 
    while( m != 0 ){
        int x = m % 10 ; 
        check = check * 10 + x ; 
        m = m / 10 ; 
    } 

    return check; 
} 

int main() {
    int t ; 
    cin >> t; 

    while(t--) {
        int n ;
        cin >> n; 
        long i=1 ; 
        while( concate( n , rev(i) ) % (n+i) != 0 ) {
            i = i + 1 ; 
        } 

        cout << i << endl; 
    }  

    return 0 ; 
}