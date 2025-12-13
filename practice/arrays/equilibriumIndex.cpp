// // Given an array arr[] of size n, the task is to return an equilibrium index (if any) or -1 if no equilibrium index exists. The equilibrium index of an array is an index such that the sum of all elements at lower indexes equals the sum of all elements at higher indexes.

// Note: When the index is at the start of the array, the left sum is 0, and when it's at the end, the right sum is 0. 

// Input: arr[] = [1, 2, 0, 3]
// Output: 2
// Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3. 

#include <iostream> 
#include <vector> 

using namespace std ; 

int find(vector<int> &arr) {
    int n = arr.size() ; 

    vector<int> prefSum(n,0) ; 
    vector<int> suffSum(n,0) ; 

    prefSum[0] = arr[0] ; 
    suffSum[n-1] = arr[n-1] ; 

    for(int i=1 ; i<n ; i++) {
        prefSum[i] = arr[i] + prefSum[i-1] ; 
    } 
    for(int i=n-2 ; i>=0 ; i--) {
        suffSum[i] = arr[i] + suffSum[i+1] ; 
    } 
    for(int i=0 ; i<n ; i++) {
        if( suffSum[i] == prefSum[i] ) {
            return i ;
        }
    } 
    return -1 ; 
}

int findEqui(vector<int> &arr) { 
    // we use the the total sum option 
    int total = 0 ; 
    int n = arr.size() ; 
    
    int prefSum = 0 ; 

    for(int i=0 ; i<n ; i++){
        total += arr[i]  ;
    } 

    for(int i=0 ; i<n ; i++) {
        int suffSum = total - arr[i] - prefSum ; 

        if( suffSum == prefSum ) return i ; 
        
        prefSum += arr[i] ; 
    } 
}  
 
int Naive(vector<int> &arr) {
    int n = arr.size() ; 

    
    for(int i=0 ; i<n ; i++) { 
        int prefSum = 0 ; 
        int suffSum = 0 ;  
        for(int j=0 ; j<i ; j++ ) {
            prefSum += arr[j] ; 
        }      

        for(int j=i+1 ; j<arr.size() ; j++){
            suffSum += arr[j] ; 
        } 

        if( prefSum == suffSum ) return i ; 
    } 

    return -1 ; 
}


int main() {
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};  

    cout << find(arr) << endl;  
    cout << findEqui(arr) << endl;  
    cout << Naive(arr) << endl;  

    return 0 ; 
}