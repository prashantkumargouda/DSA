#include <iostream>  
#include <vector> 
using namespace std ;  

void modify(vector<int> &arr) {
    int n = arr.size() ; 

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if( arr[j] == i ) {
                swap( arr[i] , arr[j]) ; 
                break ; 
            }
        }
    } 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] != i ) {
            arr[i] = -1 ;
        }
    } 
    
} 

void modify2(vector<int> &arr) {
    // using a temporary array 
    int n = arr.size() ; 

    vector<int> temp(n , -1) ; 

    for(int i=0 ; i<n ; i++ ){
        if( arr[i] != -1 ) {
            temp[arr[i]] = arr[i] ; 
        }  
    }
    for(int i=0 ; i<n ; i++) {
        arr[i] = temp[i] ; 
    } 

} 

void modify3(vector<int> &arr) {
    int i=0 ; 

    while( i<arr.size() ) {
        if( arr[i] != -1 && arr[i] != arr[arr[i]]) {
            swap(arr[i] , arr[arr[i]]) ;
        }else {
            i++ ;
        }
    }
} 

int main() { 
    vector<int> arr = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 }; 
    // modify(arr) ; 
    // modify2(arr) ;  
    modify3(arr) ;
    for(int x : arr) {
        cout << x << " " ;  
    } 

    cout << endl; 

    return 0 ; 
}