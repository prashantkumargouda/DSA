// trying to print all the subsequencess  

// using recursion  - {power set method can also be used}   
// subsequence is a sequence in which the order of the elements is maintained and and it doesnt 
// matter if it is contiguos or not 

// unlike subarrays - which need to be contiguos  

#include <iostream> 
#include <vector> 
using namespace std ;  

void subsq(int ind , vector<int> &ds , int arr[] , int n ){ 
    if( ind == n ) { 
        for(int it : ds) { 
            cout << it << " " ; 
        } 
        cout << endl ;  
        return ; 
    }    
    
    // take or pick the particular index into the subsequence  
    ds.push_back(arr[ind]) ;  
    subsq(ind + 1 , ds , arr , n ) ;  

    // remove it to add more elements 
    ds.pop_back() ;  

    // not pick case 
    subsq( ind + 1 , ds , arr , n ) ;  
}    

int main() {  
    int arr[] = {3,2,1} ;  

    int n = 3;  
    vector<int> ds ;  

    subsq( 0 , ds , arr , n ) ;  

    return 0 ; 
}