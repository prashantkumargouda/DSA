// Longest common prefix 
// Problem Statement: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "". 

// find the lexicographic order( sorted order ) for the strings 
// and then compare the first and the last strings 
// to get the common prefix 

#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std ; 

string longestCommonPrefix(vector<string> &str) {
    int n = str.size() ; 

    if( str.empty() ) return "" ; 

    sort( str.begin() , str.end() ) ; 

    string first = str[0] ; 
    string last = str[n-1] ; 
 
    string res = "" ; 

    int length = min(first.size() , last.size()) ; 

    for(int i=0 ;i<length ; i++) {
        if( first[i] != last[i] ) break ; 

        res += first[i] ;   
    }

    return res ; 

} 

int main() {
    string str ; 
    cin >> str ; 


}