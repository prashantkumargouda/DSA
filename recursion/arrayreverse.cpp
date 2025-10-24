// functional recursions 

// reversing an array using recursion  

#include <iostream> 
#include <vector>  
using namespace std ;  

// using two pointers method 
// void reverse(vector<int> &arr , int l , int r ) {  
//     if( l >= r ) return ;  
//     swap( arr[l] , arr[r] ) ;   
//     reverse( arr , l+1 , r-1 ) ; 
// } 

// using single pointer  
void reverse(vector<int> &arr , int l , int n ) {  
    if( l >= n/2 ) return ;   

    swap( arr[l] , arr[n-l-1] ) ;  
    reverse(arr , l+1 , n) ;  
}

int main() {  
    vector<int> arr = { 1,3,2,5 , 10 ,4} ;   
    int n = arr.size() ;   

    reverse(arr , 0 , n) ; 

    for( int i : arr ) { 
        cout << i << " " ; 
    } 

    cout << endl;  

    return 0 ; 
}