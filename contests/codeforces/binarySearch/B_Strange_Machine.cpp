#include <bits/stdc++.h>
using namespace std ; 

using ll = long long ; 

/* 
    q queries consisting of single integer a    
    find the total no of seconds required until a becomes 0  
    
    type A : x = x - 1 ; 
    type B : x = |x/2| 

    1 to n machines where 1 <= n <= 20   

    binary search , brute force , greedy  
    
    check for optimized answer with check for all 'A's 
*/

int main(){
    int t ; 
    cin >> t; 

    while(t--) {
        int n , q ; 
        cin >> n >> q ; 

        string s ; 
        cin >> s ; 

        bool allA = true ; 
        for(char c : s) {
            if( c == 'B' ) {
                allA = false ; 
                break ; 
            }
        } 

        while(q--){
            ll a ; 
            cin >> a ; 
            
            if( allA == true ) {
                cout << a << endl; 
                continue ; 
            } 
            
            int pos = 0 ; 
            ll count = 0 ; 

            while( a != 0 ) {
                if( s[pos] == 'A' ) {
                    a-- ; 
                }     
                else if( s[pos] == 'B' ) {
                    a = a/2 ;
                } 

                pos = (pos + 1) % n ;

                count++ ; 
            } 

            cout << count << endl; 
        }
    } 

    return 0 ; 
} 