// Finding the length of the longest substring without repeating characters 

#include <bits/stdc++.h> 
using namespace std ; 

/* 
    maintain a hashMap for the encountered letters 
    then if it is repeated you change it false;  
    and start the sequence again 
*/
int lengthOfSubString(string s) {
    if( s.size() == 0 ) return 0 ; 

    vector<int> last( 128 , -1 ) ; 

    int ans = INT_MAX;  
    int left = 0 ; 

    for(int right = 0 ; right < s.size() ; right++ ) {
        if( last[s[right]] >= left ){
            left = last[s[right]] + 1  ; 
        }  

        last[s[right]] = right ;  

        ans = max( ans , right - left + 1 ) ; 
    } 

    return ans ; 
}
