// 6. Zigzag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility) 

// P   A   H   N
// A P L S I I G
// Y   I   R 

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows); 

#include <iostream> 
#include <string>  
#include <vector>

using namespace std ; 

vector<vector<char>> convert(string &s , int numRows) { 
    int n = s.size() ; 

    // using a 2d square matrix to store the values 
    // then simply traversing and finding the solution 

    vector<vector<char>> mat(numRows) ; 
    
    int i=0 ; 
    int j=0 ; 
    for(int k=0 ; k<3;k++) {
        while( i<numRows ) {
            mat[i][j] = s[k] ;  
            i++ ; 
        }
    } 

    return mat ; 
    
} 

int main() {
    string s = "PAYPALISHIRING" ;
    vector<vector<char>> temp = convert(s , 3) ; 

    for(auto &e : temp) {
        for(char c : e) {
            cout << c << ' ' ;
        } 
        cout << endl; 
    } 

    cout << endl; 

    return 0 ;
}