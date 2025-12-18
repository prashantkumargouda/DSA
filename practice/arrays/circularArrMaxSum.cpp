// finding the maximum sum in a circular subarray 

#include <iostream> 
#include <vector> 
#include <climits> 

using namespace std ; 

// Naive Approach 

int maxSum1(vector<int> &arr ) {
    int n = arr.size() ; 

    int res = INT_MIN ; 
    for(int i=0 ; i<n ; i++) {
        int currSum = 0 ; 
        for(int j=0 ; j<n ; j++) {
            int idx = (i+j) % n ; 
            currSum = currSum + arr[idx] ; 

            res = max(res ,currSum) ;
        }
    } 

    return res ; 
} 

//Better approach 

int maxSum2(vector<int> &arr) {
    int n = arr.size() ; 
    int suffixSum = arr[n-1] ; 

    vector<int> maxSuffix(n+1 ,0) ;
    maxSuffix

}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12} ; 
    cout << maxSum1(arr) << endl; 

    return 0 ; 
}