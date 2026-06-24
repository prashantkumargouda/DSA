// FIND THE INDEX OF THE FIRST OCCURENCE IN A STRING 

#include <bits/stdc++.h> 
using namespace std ; 

int strStr(string haystack , string needle) {
    int n1 = haystack.size() ; 
    int n2 = needle.size() ; 

    int i = 0 , j = 0 ; 

    while( i < n1 && j < n2 ) {
        if( haystack[i] == needle[j] ) {
            i++ ; 
            j++ ; 
        } 
        else { 
            i = i - j + 1 ;  
            j=0 ; 

        } 
    } 

    if( j == n2 ) {
        return i -  j ; 
    } 

    return -1 ; 
}