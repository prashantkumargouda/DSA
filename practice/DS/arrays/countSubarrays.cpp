// counting the number of subarrays having values strictly greater than provided K value 
// N = 3, K = 2
// Arr[] = {3, 2, 1}
// Output: 3
// Explanation: The subarrays having value
// strictly greater than K are: [3], [3, 2]
// and [3, 2, 1]. Thus there are 3 such
// subarrays. 

#include <iostream> 
#include <vector>
#include <climits>  

using namespace std ; 

int countSubarrays(vector<int> &arr , int k ) {
    // using the brute force first ; 
    int n = arr.size() ; 
    
    int count = 0 ; 
    for(int i=0 ; i<n ; i++) { 
        int mx = arr[i]; 
        for(int j=i ; j<n ; j++ ){
            for(int k=i ; k<=j ; k++) {
                mx = max( mx , arr[k]) ;  
            }
            if( mx > k ){
                count++ ; 
            }
        }
    }

    return count ; 
}

int solve_two_loops(vector<int>& arr, int K) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int mx = INT_MIN;
        for (int j = i; j < n; j++) {
            mx = max(mx, arr[j]);
            if (mx > K) count++;
        }
    }
    return count;
}

int counting(vector<int> &arr , int k) {
    int n = arr.size() ; 

    int total = n*(n+1) / 2 ; 

    int len = 0 ; 
    int good = 0 ; 

    for(int x : arr) {
        if ( x <= k ) {
            len++;
        } else {
            good += len*(len +1) / 2 ; 
            len = 0 ; 
        }
    } 

    good += len*(len+1) / 2 ;
    return total - good ; 
} 

int counting2(vector<int> &arr , int k ) {
    int n = arr.size() ; 

    int ans =  0 ; 
    int lastBad = -1 ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] > k ){
            lastBad = i ;
        } 
        ans = ans + lastBad + 1 ; 
    } 

    return ans ;
}

int main() {
    vector<int> arr = {1, 2, 3, 4} ; 
    cout << countSubarrays(arr , 1) << endl ; 
    cout << solve_two_loops(arr , 1) << endl; 
    cout << counting(arr , 1) << endl; 
    cout << counting2(arr , 1) << endl; 
    return 0 ; 
}