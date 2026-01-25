#include <iostream>
#include <vector> 
#include <algorithm> 
#include <unordered_set>
#include <math.h> 

using namespace std ;

int repeat(vector<int> &arr) {
    int n = arr.size() ; 

    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            if( arr[i] == arr[j] ) {
                return arr[i] ; 
            }
        }
    } 
    return -1 ; 
}  

int repeat2(vector<int> &arr){
    // using the sorting method 
    int n = arr.size() ; 

    sort(arr.begin() , arr.end() ) ; 
    for(int i=1 ; i<n ; i++) {
        if( arr[i] == arr[i-1] ) {
            return arr[i] ; 
        }
    } 

    return -1 ; 
}
 
int repeat3(vector<int> &arr) {
    // using a hashset 

    int n = arr.size() ; 
    unordered_set<int> ans ; 

    for(int i=0 ; i<n ;i++) {
        if( ans.find(arr[i]) != ans.end() ) {
            return arr[i] ; 
        } 
        ans.insert(arr[i]) ;
    } 
    return -1 ; 
} 

int repeat4(vector<int> &arr){
    // using the sum method 

    int n = arr.size() ; 

    int sum1 = 0 , sum2 = 0 ; 
    for(int i=0 ; i<n ; i++){
        sum1 += arr[i] ; 
    } 

    for(int i=1 ; i<=n-1 ; i++) {
        sum2 += i ; 
    } 

    return sum1 - sum2 ; 
} 

int repeat5(vector<int> &arr) {
    int n = arr.size() ; 
    int res = 0; 
    // using a single loop this time 
    for(int i=0 ; i<n-1 ; i++){
        res = arr[i] ^ (i+1) ; 
    } 

    res = res ^ arr[n-1] ; // xor the last remainiing element ; 

    return res; 
} 

int repeat6(vector<int> &arr) {
    // making the values negative  
    int n = arr.size() ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[abs(arr[i])] < 0 ) {
            return abs(arr[i]) ;
        } 

        arr[abs(arr[i])] = -arr[abs(arr[i])] ; 
    } 

    return -1 ;
}  

int floyd(vector<int> &arr) {
    int slow = arr[0]; 

    // fast pointer
    int fast = arr[0]; 

    do {

        // moves one step
        slow = arr[slow];  

        // moves two steps
        fast = arr[arr[fast]];     
    } while (slow != fast);

    // reinitialize fast to the start
    fast = arr[0]; 
  
    // Loop until both pointers meet at the duplicate
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
  
   // Return duplicate number
    return slow;	
}

int main() { 
    vector<int> arr = {1, 3, 2, 3, 4}; 

    cout << repeat(arr) << endl; 
    cout << repeat2(arr) << endl; 
    cout << repeat3(arr) << endl;  
    cout << repeat4(arr) << endl;  
    cout << repeat5(arr) << endl;  
    cout << repeat6(arr) << endl;  
    cout << floyd(arr) << endl; 
    return 0 ; 
} 

