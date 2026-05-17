#include <bits/stdc++.h> 
using namespace std ; 

/* 
    sort the first array (a) 
    count the no of usable swords based on the unique sword strenghts 
    usable swords = no of swords greater than or equal to x(strength) ( k = n - lowerBound)

    then find the prefix sum for array b 
    and use upperbound to find the no of levels that can be completed for each unique sword

    keep calculating the max score and maintain ans using max function 
*/ 

using ll = long long  ; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t ;
    cin >> t ; 
    
    while(t--) {

        int n ; 
        cin >> n ; 
    
        vector<ll> a(n) ; 
        vector<ll> b(n) ; 
    
        for(auto &it : a) cin >> it ; 
        for(auto &it : b) cin >> it ; 
    
        vector<ll> pref(n)  ; 
    
        pref[0] = b[0] ; 
    
        for(int i=1 ; i<n ; i++) {
            pref[i] = pref[i-1] + b[i] ; 
        } 
    
        vector<ll> s = a ; 
        sort( s.begin() , s.end() ) ; 
    
        ll ans = 0 ; 
    
        for(int i=0 ; i<n ; i++) { 
            // unique swords 
            ll x = s[i] ; 
    
            // found the usable swords 
            ll usable = n - (lower_bound( s.begin() , s.end() , x ) - s.begin()) ; 
    
            // levels that can be completed with this unique sword 
            ll levels = upper_bound( pref.begin() , pref.end() , usable ) - pref.begin() ;  
    
            ans = max(ans , x * levels)  ;    
        } 
    
        cout << ans << endl; 
    }

    return 0 ; 
    

}