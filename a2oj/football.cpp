// count the number of consecutive 1s or 0s and if the value reaches 7 o ris greter than 7 -- 
// mark it as dangerous or else leave it keep counting  

#include <iostream> 
#include <vector> 
#include <string> 
using namespace std ;  

int main() { 
    string s ; 
    cin >> s ;  

    int count = 1 ; 
    bool danger = false ;  

    int n = s.size() ;  

    for(int i=1 ; i< n ; i++) { 
        if( s[i] == s[i-1] ) { 
            count += 1 ;  
            if( count >= 7 ) {
                danger = true ; 
                break ; 
            }   
        }  
        else { 
            count = 1 ; 
        }
    } 
    if( danger ) { 
        cout << "YES" << endl; 
    } 

    else { 
        cout << "NO" << endl; 
    } 

    return 0 ; 
}