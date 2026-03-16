#include <iostream> 
using namespace std ;

int countNum(int n) {
    int count = 0 ; 

    while( n > 0 ) {
        n = n / 10 ; 
        count = count + 1 ; 
    }  

    return count ; 
}   

// 1,000,000

int countCommas(int n) {
    if( countNum(n) <= 3 ) {
        return 0 ; 
    } 

    else if( countNum(n) / 3 == 1 && countNum(n) != 3 ) {
        return ( n - 999 ) * 1 ;  
    } 

    else {
        return (n - 999) * (( countNum(n) / 3 ) - 1 )  ; 
    } 
}

int main() {
    int n ; 
    cin >> n ; 

    cout << countCommas(n) << endl; 

    return 0 ; 

}