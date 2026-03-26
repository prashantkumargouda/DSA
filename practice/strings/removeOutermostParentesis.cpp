// removing the outermost paranthesis 

#include <iostream> 
using namespace std ; 

int main() {
    string res ; 

    string check ; 
    cin >> check ; 

    int count = 0 ; 

    for( char c : check ) {
        if( c == '(' ) { 
            count++ ;
            if( count >  1) {
                res.push_back(c) ; 
            } 
        }  
        else if( c == ')' ) {
            count-- ; 
            if( count > 0 ) {
                res.push_back(c) ; 
            }
        }
    }

    for( char ch : res ) {
        cout << ch ; 
    } 
    cout << endl; 


    return 0 ; 


}