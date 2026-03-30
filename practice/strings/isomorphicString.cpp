// isomorphic string 
// Problem Statement: Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself. 

#include <iostream> 
#include <string> 
#include <vector> 

using namespace std ; 

bool isomorphic(string s , string t){
    int m1[256] = {0} ;  
    int m2[256] = {0} ; 

    int n = s.size() ;  

    for(int i=0 ; i<n ; i++) {
        if( m1[s[i]] != m2[t[i]] ) {
            return false ; 
        } 

        m1[s[i]] = i+1; 
        m2[t[i]] = i+1;
    }

    return true ; 
} 

int main() {
    string s = "paper" ; 
    string t = "title" ; 

    if( isomorphic(s ,t) ) cout << "YES" << endl; 
    else cout << "NO" << endl; 
    
    return 0 ; 
}