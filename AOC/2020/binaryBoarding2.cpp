#include <iostream>
#include <string> 
#include <sstream>
#include <vector> 
#include <climits> 
#include <algorithm>  

using namespace std ; 

int main() {  
    ios::sync_with_stdio(false) ; 
    cin.tie(nullptr) ; 

    string line ;   
    vector<string> codes  ; 
    vector<int> seats ;  

    while( getline(cin , line ) ) { 
        codes.push_back(line) ;
    } 
 
    for(const string &code : codes ) { 
        int row = 0 , col = 0 ; 

        for(int i=0 ; i<7 ; i++) { 
            row = row << 1 ; 
            if( code[i] == 'B' ) row = row | 1 ;  
        }  
        
        for(int i=7 ; i<10 ; i++) { 
            col = col << 1 ; 
            if( code[i] == 'R' ) col = col | 1 ; 
        } 

        int seatId = row * 8 + col ;  

        seats.push_back(seatId) ;
    } 

    sort( seats.begin() , seats.end() ) ;  // sorted here  

    for(int i=0 ; i+1 < seats.size() ; i++){ 
        if( seats[i] + 2 == seats[i+1] ) { 
            cout << seats[i] + 1 << endl;  
            break ; 
        } 
    } 

    return 0 ; 

}