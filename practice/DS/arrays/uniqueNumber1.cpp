#include <iostream>
#include <vector> 
#include <unordered_map> 
#include <algorithm> 

using namespace std ; 

int findUnique(vector<int> &arr) { 
    int n = arr.size() ; 

    // using unordered_set  
    
    unordered_map<int,int> cnt ; 

    for(int i=0 ; i<n ; i++) {
        cnt[arr[i]]++ ;
    } 

    for( auto c : cnt ){
        if( c.second == 1 ) {
            return c.first ; 
        }
    } 

    return -1 ;
} 

int findUnique2(vector<int> &arr) { 
    // using xor  

    int n = arr.size() ;  
    int res = 0 ; 
    for(int i=0 ; i<n ; i++){
        res = res ^ arr[i] ; 
    } 

    return res ; 

}  

int findUnique3(vector<int> &arr) {
    int n = arr.size() ; 

    sort(arr.begin() , arr.end() ) ; 

    for(int i=0 ; i<n ; i= i+2) {
        if( arr[i] != arr[i+1] ){
            return arr[i] ; 
        }
    } 

    return -1 ; 
}

int findUnique4(vector<int> &arr) { 
    int n = arr.size() ; 

    for(int i=0 ; i<n ; i++) {
        int count = 0 ; 
        for(int j=0 ; j<n ; j++){
            if( arr[i] == arr[j] ) {
                count++ ; 
            }
        } 
        if( count == 1 ) {
            return arr[i] ; 
        }
    } 
 
    return -1 ; 
    
}  


int main() { 
    vector<int> arr = {2,3,5,4,5,3,4} ; 
    cout << findUnique(arr) << endl; 
    cout << findUnique2(arr) << endl; 
    cout << findUnique3(arr) << endl;   
    cout << findUnique4(arr) << endl;
    return 0 ; 
}