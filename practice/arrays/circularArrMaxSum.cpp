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

// expected approach 
int maxSum2(vector<int> &arr) {
    int n = arr.size() ;  

    int globalMax = arr[0] ; 
    int globalMin = arr[0] ; 

    int currMax = 0  , currMin = 0 ; 
    int total = 0 ; 
    for(int i=0 ; i<n ; i++){ 
        total += arr[i] ; 
        currMax = max(currMax + arr[i] , arr[i] ) ; 
        globalMax = max( globalMax , currMax ) ; 
        currMin = min(currMin + arr[i] , arr[i] ) ; 
        globalMin = min( globalMin , currMin ) ;  
    }

    if(globalMax < 0) {
        return globalMax ; 
    } 

    return max(globalMax , total - globalMin) ; 
}

int maxSum3(vector<int> &arr) {
    int n = arr.size() ; 

    // trying to find the maxSuffix for an element  
    int suffixSum = arr[n-1] ; 

    vector<int> maxSuffix( n+1 , 0 ) ; 
    maxSuffix[n-1] = arr[n-1] ; 

    for(int i=0 ; i<n ; i++) {
        suffixSum += arr[i]; 
        maxSuffix[i] = max( maxSuffix[i+1] , suffixSum ) ; 
    }   

    // now the circularSum is the maximum circular Sum  
    // and the normalSum is the maximum sum in the normal array 
    int circularSum = arr[0] ; 
    int normalSum  = arr[0] ; 

    int prefix = 0 ; 
    int currSum = 0 ;  

    for(int i=0 ; i<n ; i++) {
        currSum = max( currSum + arr[i] , arr[i] ); 
        normalSum = max( normalSum , currSum ) ;  

        prefix = prefix + arr[i] ; 
        circularSum = max(circularSum , prefix + maxSuffix[i+1] ) ; 

    } 

    return max( circularSum , normalSum )  ;

}


int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12} ; 
    cout << maxSum1(arr) << endl; 
    cout << maxSum2(arr) << endl;  
    cout << maxSum3(arr) << endl; 
    return 0 ; 
}