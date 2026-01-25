// find the maximum subarray sum  
// kadanes algorithm 
// for finding the maximum subarray 
// the idea is if the sum is less than 0 and we are trying to add something to it  
// it is going to make that sum much more less  
// than the actual value that is being added 
// so better to make the sum = 0   

#include <iostream> 
#include <vector> 
#include <climits>

using namespace std ; 

int maxSubarraySum(vector<int> arr) {
    int n = arr.size() ; 

    int res = 0 ; 

    for(int i=0 ; i<n ; i++) {
        int currSum = arr[i] ; 
        for(int j=i+1 ; j<n ; j++){
            currSum += arr[j] ;  

            res = max(currSum , res);
        }
    } 

    return res ;
}

int kadanes(vector<int> &arr) {
    int n = arr.size() ; 

    int maxSum = INT_MIN ;
    int sum = 0 ; 

    for(int i=0 ; i<n ; i++) { 
        sum = sum + arr[i] ; 
        maxSum = max(sum , maxSum) ;
        if( sum < 0 ) {
            sum = 0 ; 
        }
    } 

    return maxSum ; 

}

int main() {
    vector<int> arr ={-2, -3, 4, -1, -2, 1, 5, -3} ;
    cout << maxSubarraySum(arr) << endl; 
    cout << kadanes(arr) << endl ;
    return 0 ;
}