#include <iostream> 
#include <vector> 

using namespace std ; 

vector<int> prod( vector<int> &arr ) {
    int n = arr.size() ; 

    vector<int> res(n) ; 

    for(int i=0 ; i<n ; i++) {
        int prod = 1 ; 
        for(int j=0 ;  j<n ; j++ ){
            if( i==j ) {
                continue ; 
            } 
            prod *= arr[j] ; 
        } 
        res[i] = prod ; 
    } 

    return res ; 

} 

vector<int> prod2(vector<int> &arr) {
    int n = arr.size() ; 
    vector<int> res(n) ; 

    vector<int> prefix(n) ; 
    vector<int> suffix(n) ; 

    // finding the prefix and suffix for all the elements ;    
    prefix[0] = arr[0] ;  
    suffix[n-1] = arr[n-1] ; 

    for(int i=1 ; i<n ; i++ ){
        prefix[i] = prefix[i-1] * arr[i] ; 
    } 

    for(int i=n-2 ; i>=0 ; i--) {
        suffix[i] = suffix[i+1] * arr[i] ; 
    } 

    for(int i=0 ; i<n ; i++){
        if( i==0 ) {
            res[i] = suffix[i+1] ;
        } else if( i==n-1 ) {
            res[i] = prefix[i-1] ; 
        }  
        else {
            res[i] = prefix[i-1] * suffix[i+1] ; 
        } 
    } 

    return res ; 
}  

vector<int> prod3(vector<int> &arr) {
    int n = arr.size() ; 

    int idx = -1 ; 
    int zeros =  0 ;  

    int prod = 1 ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] == 0 ){
            zeros++ ; 
            idx = i ; 
        } else {
            prod = prod * arr[i] ; 
        }
    } 

    vector<int> res(n,0) ; 

    if(zeros == 0) {
        for(int i=0 ;i <n ;i++) {
            res[i] = prod / arr[i] ;
        }
    } 
    else if( zeros == 1 ) {
        res[idx] = prod ; 
    } 

    return res ; 
} 

int main() {
    vector<int> arr = {10,3,5,6,2} ;  
    vector<int> res = prod2(arr) ;  
    vector<int> res1 = prod(arr) ; 
    vector<int> res2 = prod3(arr) ;  
    for(int x : res ){
        cout << x << " " ; 
    }  
    cout << endl; 

    for(int x : res1) {
        cout << x << " " ; 
    } 
    cout << endl;  
 
    for(int x : res2) {
        cout << x << " " ; 
    } 

    cout << endl; 
    return 0 ;  
}