// count the number of special characters I

#include <bits/stdc++.h> 
using namespace std ; 

int check1(string word) { // bitmask solution for counting I problem
    int lower = 0 ; 
    int upper = 0 ; 

    for( char c : word ) { 
        if( islower(c) ) {
            lower = lower | ( 1 << ( c - 'a' ) ) ; 
        } 
        else {
            upper = upper | ( 1 << ( c - 'z' ) ) ;
        }
    }

    int common = lower & upper ; 
    
    return __builtin_popcount(common);

} 

int check2(string word){ // count the number of special characters II 
    vector<int> lower( 26 , -1 ) ; 
    vector<int> upper( 26 , -1 ) ; 

    for(int i=0 ; i<word.size() ; i++) {
        if( islower(word[i]) ) {
            lower[word[i] - 'a'] = 1 ;  
        } 
        else {
            if( upper[word[i] - 'A'] == -1 ) { // not updated with the first occurence of uppercase
                upper[word[i] - 'A'] == i ;
            }
        }
    } 

    int count = 0 ; 
    for(int i=0 ; i<26 ; i++) {
        if( lower[i] != -1 && upper[i] != -1 ) {
            if( lower[i] < upper[i] ) count++ ; 
        }
    } 

    return count ; 
} 

int check3(string word) {
    // trying out the bitmask solution for the second problem
    
    

}