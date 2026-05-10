#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std ;

int main(){
    int t; 
    cin >> t; 
    
    while( t-- ) {
        int n , x , y ; 
        cin >> n >> x >> y ; 
        
        vector<int> a(n) ; 
        for(int &it : a) cin >> it ; 
        
        vector<int> pool ; 
        vector<int> mid  ; 
        
        for(int i=0 ; i<x ; i++) pool.push_back(a[i]) ; 
        for(int i=y ; i<n ; i++) pool.push_back(a[i]) ; 
        
        for(int i=x ; i<y ; i++) mid.push_back(a[i]) ; 
        
        if(!mid.empty()) rotate(mid.begin() , min_element(mid.begin() , mid.end()), mid.end()) ;  
        int m = mid.empty() ? -1 : mid[0] ; 
        
        auto it = pool.begin() ; 
        while( it != pool.end() && *it < m ) {
            it++; 
        } 
         
        pool.insert( it , mid.begin() , mid.end() )  ; 
        
        for(int i=0 ; i<n ; i++) {
            cout << pool[i] << " ";
        } 
        
        cout << endl;  
        
    } 
    
    return 0 ; 
}