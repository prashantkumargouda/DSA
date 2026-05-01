#include <bits/stdc++.h> 
using namespace std ; 

int main() {
    int t ;
    cin >> t ; 

    while(t--) {
        int n , k ; 
        cin >> n >> k ; 

        vector<int> freq( n+1 , 0 ) ; 
        for(int i=0 ; i<n ; i++) { 
            int x ; cin >> x ; 
            freq[x]++ ; 
        } 

        int missing = 0 ; 
        for(int i=0 ; i<k ; i++) {
            if( freq[i] == 0 ) {
                missing++ ;
            }
        } 

        int kCount = freq[k] ; 

        int ops = kCount + max( 0 , missing - kCount ) ;

        cout << ops << endl; 
      
    } 

    return 0 ; 
}