#include <iostream>
#include <string> 
#include <sstream>
#include <vector> 
#include <climits> 

using namespace std ; 

int main() {  

    ios::sync_with_stdio(false); 
    cin.tie(nullptr);  

    string line ;  
    vector<string> codes ;  

    while(getline(cin , line)) { 
        codes.push_back(line) ; 
    }    
    int minSeat = INT_MAX  ; 
    int maxSeat = INT_MIN ;  

    for( const string &code : codes ) { 
        // extracting the row and col for the seats  
        int col = 0 , row = 0 ;  

        for(int i=0 ; i<7 ; i++) {
            row = row << 1 ; 
            if( code[i] == 'B' ) row |= 1 ; 
        } 

        for(int i=7 ; i<10 ; i++) { 
            col = col << 1 ; 
            if( code[i] == 'R' ) col |= 1 ; 
        } 

        int seatId = row * 8 + col ; 
        if( maxSeat < seatId ) maxSeat = seatId ;  
        if( minSeat > seatId ) minSeat = seatId ; 
        cout << seatId << " " ; 
    }   
    cout << endl; 
    cout << maxSeat << endl; 
    cout << minSeat << endl;
    return 0 ; 
}