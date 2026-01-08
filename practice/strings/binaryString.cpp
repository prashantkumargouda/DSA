#include <iostream> 
#include <string> 
#include <vector> 

using namespace std ; 

int binarySubstring(string &s) { 
    int n = s.size() ; 
    int count = 0 ; 

    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            if( s[i] == '1' && s[j] == '1' ) {
                count++ ;
            }
        }
    } 

    return count ; 
} 

int check(string &s) {
    int count = 0 ; 
    int prevOnes = 0 ; 

    for(char e : s) {
        if( e == '1' ) {
            count += prevOnes ; 
            prevOnes += 1 ;
        }
    } 

    return count ; 
}  

// using the formula 
int check2(string &s) { 
    int countOnes = 0 ; 

    for(char c: s) {
        if( c == '1' ) {
            countOnes++ ; 
        }
    } 

    return ( countOnes * ( countOnes - 1) ) / 2 ; 

} 

int check3(string &s) {
    int n = s.size() ; 
    int count = 0 ; 

    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            if( s[i] == s[j] ) {
                count++ ;
            }
        }
    } 

    return count ; 
}


int main() { 
    string s = "1111" ; 

    int x = binarySubstring(s) ; 

    cout << x << endl; 

    cout << check(s) << endl; 
    cout << check2(s) << endl; 
    cout << check3(s) << endl; 
    return 0 ;

}