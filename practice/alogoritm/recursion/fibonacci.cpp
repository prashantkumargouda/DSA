// fibonacci series using recursion 

// using multiple recursion calls 

#include <iostream>
using namespace std ;  

int fibo(int n) { 
    if( n<=1 ) return n ;   
    return fibo(n-1) + fibo(n-2) ;  
}  

int main(){  
    int n ; 
    cout << "Enter the value of n :" << endl;  
    cin >> n ;  

    cout << fibo(n) << endl;  
    return 0 ; 
}