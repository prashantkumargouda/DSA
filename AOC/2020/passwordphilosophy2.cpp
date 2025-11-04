#include <iostream>
#include <sstream> 
#include <string> 

using namespace std ;  

// making use of xor using bool first and second  

int main() { 
    string line ;   
    int countNo = 0 ; 
    // 4-8 n: dnjjrtclnzdnghnbnn  
    while( getline(cin , line) ) { 
        stringstream ss(line) ;  

        int num1 , num2 ; 
        char letter ; 
        string password ;  

        ss >> num1 ;   
        ss.ignore(1 , '-') ; 
        ss >> num2 ;  
        ss >> letter ; 
        ss.ignore(1,':') ; 

        ss >> password ; 

        bool first = password[num1 - 1] == letter ; 
        bool second = password[num2 - 1] == letter ; 

        if( first ^ second ) {
            countNo++ ; 
        }
    } 

    cout << countNo << endl;  

    return 0 ;    
}