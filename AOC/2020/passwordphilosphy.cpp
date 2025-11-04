// learning stringstream first 
#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std ;  

// -----------------------------------------------------------------------------------------------------
// string data = "100 200 300" ; 
// stringstream ss(data) ; // creating a stringstream ss of data 
// int a , b , c ; 
// ss >> a >> b >> c ; // extracted integers from ss into a b c  

// cout << a << " " << b << " " << c ; 
// cout << endl;  
// -----------------------------------------------------------------------------------------------------
// stringstream ss ;  // ss stringstream  
// int x = 42 ; 
// float y = 4.2 ;  

// string name = "Prashant" ;  

// ss << "Name:" << name << " x:" << x << " y:" << y ;   

// string result = ss.str() ; 
// cout << result << endl;  

// return 0 ;  
// --------------------------------------------------------------------------------------------------------
int main() {  
    string line ;   
    int countNo = 0 ; 
    while( getline(cin , line) && line != "xx" ) { 
    // using this line taken as input and putting it into stringstream ss 

        stringstream ss(line) ; 

    // using the above stringstream to get the valye which is something like  
    // 4-8 n: dnjjrtclnzdnghnbnn  

        int num1 , num2 ;  
        char letter ;
        string password ;  

        ss >> num1 ; 
        ss.ignore(1,'-') ; 
        ss >> num2 ; 
        ss >> letter ;  

        ss.ignore(1,':') ;  
        ss >> password ; 

        int count = 0 ; 
        
        for(char c : password) {  
            if( c == letter ) {
                count++ ; 
            }
        }   

        if( count >= num1 && count <= num2 ) { 
            countNo++ ;  
        }
    } 

    cout << countNo << endl; 
      
    return 0 ; 

}
