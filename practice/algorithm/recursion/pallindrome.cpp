// checking for pallindrome  

// uses recursion same concept as array reverse single pointer  

#include <iostream> 
using namespace std ;  

bool pallindrome(string &s , int n , int i ) { 
    if( i >= n/2 ) return true ;  

    if( s[i] != s[n-i-1] ) return false ; 

    return pallindrome(s , n , i+1) ; 
} 

int main(){  
    string s = "namopew" ;   
    int n = s.length() ; 
    if( pallindrome( s , n , 0 ) ) cout << "yes" << endl;  
    else {
        cout << "no" << endl; 
    }  
    return 0 ; 
}