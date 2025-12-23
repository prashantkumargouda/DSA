#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std ; 

int findSmallest1(vector<int> &arr) {
    int n = arr.size() ; 

    vector<int> missing; 

    int i=0 ; 

    while( i < arr.size() ) { 
        if( i != arr[i] ) {
            missing.push_back(i) ;
        }  
        i++; 
    } 

    sort(missing.begin() , missing.end()) ; 
    return missing[0] ; 
}  

int findSmallest2(vector<int> &arr , int m , int n) {
    // using a hashmap  

    vector<int> check(m , 0) ; 
    for(int i=0 ; i<n ; i++) {
        check[arr[i]] = 1 ; 
    } 

    for(int i=0 ; i<m ; i++) {
        if( check[i] == 0 ) {
            return i ; 
        }
    }
}  

int findSmallest3(vector<int> &arr , int start , int end ) {
    int n = arr.size() ;  

    if( start > end ) {
        return start ; 
    } 

    int mid = start + (end - start) / 2 ; 

    if( arr[mid] == mid ) {
        return findSmallest3( arr , mid + 1 , end ) ; 
    } 
    else {
        return findSmallest3(arr , start , mid-1 ) ; 
    } 

}

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 10} ;  
    cout << findSmallest1(arr) << endl; 

    cout << findSmallest2(arr , 11 , 9) << endl;  
    
    int n = arr.size() ; 
    cout << findSmallest3( arr , 0 , n-1 ) << endl; 

    return 0 ; 
}