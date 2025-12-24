#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std ; 

int findMajor(vector<int> &arr) {
    int n = arr.size(); 

    for(int i=0 ; i<n ; i++){
        int count = 0 ; 
        for(int j=0 ; j<n ; j++) {
            if( arr[i] == arr[j] ) {
                count++ ; 
            }
        } 

        if( count > n/2 ) {
            return arr[i] ;
        }
    } 

    return -1 ; 
} 

int findMajority(vector<int> &arr) {
    int n = arr.size() ; 

    sort( arr.begin() , arr.end() ) ; 

    int i=0 ;  
    while( i < arr.size() - n/2 ) {
        if( arr[i] == arr[i + n/2 ] ) {
            return arr[i] ;
        } 
        i++ ;
    } 

    return -1 ; 
}  

int findMajority(vector<int> &arr) {
    int n = arr.size() ; 

    
}

int main() {
    vector<int> arr = {1, 5, 2, 5, 3, 5, 5};   

    cout << findMajor(arr) << endl; 

    return 0 ;
}