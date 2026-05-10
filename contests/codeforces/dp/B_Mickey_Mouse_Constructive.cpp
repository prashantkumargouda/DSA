#include <bits/stdc++.h> 
using namespace std ; 

const long long mod = 676767677 ; 

void solve() {
    int x,y ; 
    cin >> x >> y ; 

    int diff = abs(x - y); 

    if( diff == 0 ) cout << "1" << endl; 
    else {
        int ans = 0 ; 
        for(int i=1 ; i*i <= diff ; i++) {
            if( diff % i == 0 ) {
                ans++ ; 
                if( i != diff / i ) {
                    ans++ ; 
                }
            }
        } 

        cout << ans % mod << endl; 
    } 

    for(int i=0 ; i<y ; i++) cout << "-1" << " " ;  
    for(int i=0 ; i<x ; i++) cout << "1" << " " ;  
    
    cout << endl; 
} 

signed main() { 
    ios::sync_with_stdio(false) ;   
    cin.tie(nullptr) ; 

    int t = 1 ; 
    cin >> t ; 

    while(t--) {
        solve() ; 
    } 
    
    return 0 ; 
}