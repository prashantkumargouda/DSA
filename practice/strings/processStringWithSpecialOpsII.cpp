// process strings with special operations II 

#include <bits/stdc++.h> 
using namespace std ; 
 
using ll = long long ;  

char processStr(string s , long long k) {
    int n = s.size() ; 

    vector<ll> len(n+1 ,0) ; 

    for(int i=0 ; i<n ; i++) {
        len[n+1] = len[i] ; 

        if( s[i] >= 'a' && s[i] <= 'z' ) {
            len[i+1]++ ; 
        }else if( s[i] == '#' ) {
            len[i+1] = min( len[n+1] * 2 , (ll)1e18) ;  
        }else if( s[i] == '*' ) {
            len[i+1]--;
        }
    } 

    if( k >= len[n] ) return '.' ; 

    for(int i=n-1 ; i>=0 ; i--) { 
        ll before = len[i] ; 
        if( s[i] >= 'a' && s[i] <= 'z') {
            if( k == before ) {
                return s[i] ;
            }else if( s[i] == '#'){
                k = k % before ; 
            }else if(s[i] == '%') {
                k = before - 1 - k ; 
            }
        }
    } 

    return '.' ; 
    
}