#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <climits> 

using namespace std ; 

// naive approach 
int largest(vector<int> &arr , int k ) {
    int n = arr.size() ; 

    vector<int> sums ; 
    for(int i=0 ; i<n ; i++) {
        int sum = 0 ; 
        for(int j=i ; j<n ; j++){
            sum += arr[j]; 
            sums.push_back(sum) ; 
        } 
    } 

    sort( sums.begin() , sums.end() , greater<int>() ) ; 
    return sums[k-1] ;  

} 

// the idea is to use the concept of prefix sum array and make separate list sort abd return the solution 
int largest2(vector<int> &arr , int k) {
    int n = arr.size() ; 

    vector<int> prefixSum( n+1 ) ;  
    prefixSum[0] = 0 ; 
    for(int i=1 ; i<=n ; i++) {
        prefixSum[i] = arr[i-1] + prefixSum[i-1] ; 
    } 

    vector<int> subArraySums ; 
    // finding the subarraySum 
    for(int i=0 ; i<=n ; i++) {
        for(int j=i+1 ; j<=n ; j++) {
            subArraySums.push_back( prefixSum[j] - prefixSum[i] ) ; 
        } 
    } 
 
    sort( subArraySums.begin() , subArraySums.end() , greater<int>() ) ;  

    return subArraySums[k-1] ; 
}  

int largest3(vector<int> &arr , int k) {
    int n = arr.size() ; 

    // finding the prefix sum first ; 

    vector<int> prefixSum(n+1) ; 
    prefixSum[0] = 0 ; 
    prefixSum[1] = arr[0] ; 

    for(int i=2 ; i<=n ; i++ ){
        prefixSum[i] = prefixSum[i-1] + arr[i-1] ; 
    } 

    // now we require a priority queue with min heap 
    priority_queue< int , vector<int> , greater<int>> pq ; 

    // calculating the subarraysums contiguous position wise 
    for(int i=0 ; i<=n ; i++){
        for(int j=i+1 ; j<=n ; j++) { 
            // calculated the sums 
            int x = prefixSum[j] - prefixSum[i] ;  
            // if queue has less than k elements 
            // then push it 

            if( pq.size() < k ) {
                pq.push(x) ; 
            } 
            
            else { 
                // else if elements is greater than k 
                // now if x the sum is greater than 
                // the top element of pq 
                // then pop one element and insert it  
                // else it is of no use  

                if( x > pq.top() ) {
                    pq.pop() ; 
                    pq.push(x) ;
                }
            } 
        } 
    }  

    return pq.top() ; 
}

int main() {
    vector<int> arr = {20,-5,-1} ;  
    
    cout << largest(arr, 3) << endl; 
    cout << largest2(arr , 3) << endl; 
    cout << largest3(arr , 3) << endl;  

    return 0 ;  

}