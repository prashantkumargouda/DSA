// largest odd number in a string 
// this problem has a case of leading zeroes 

#include <iostream> 
#include <string> 

using namespace std ;  

string largestOdd(string str) {
    int n = str.size() ; 
    int ind = -1 ; 
    for(int i = n-1 ; i>= 0 ; i--) {
        if( ( str[i] - '0' ) % 2 == 1 ) {
            ind = i ; 
            break ; 
        }
    } 

    int i=0 ; 
    while( i <= ind && str[i] == '0' ) {
        i++; 
    } 

    return str.substr(i , ind - i + 1 ) ; 
}  

int main() {
    string str ; 
    cin >> str ; 

    cout << largestOdd(str) << endl; 

    return 0 ; 
}