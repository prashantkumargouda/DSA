#include <iostream> 
#include <vector> 
#include <climits> 
#include <algorithm> 

using namespace std ; 

int smallestSubArray1(vector<int> &arr , int x ) {
    // trying out all the subarrays 

    int n = arr.size() ; 

    int res = INT_MAX ; 
    for( int i=0 ; i<n ; i++) {
        int sum = 0 ;   
        for(int j=i ; j<n ; j++) {
            sum += arr[j] ;

            if( sum > x ) {
                res = min(res , j-i+1) ; 
                break ; 
            }
        }
    } 

    if( res == INT_MAX ) {
        return -1 ; 
    } 

    return res ;
} 

int smallestSubArray2(vector<int> &arr , int x) {
    int n = arr.size() ; 

    int res = INT_MAX ; 
    // finding the prefixSum first 
    vector<int> prefixSum(n+1 , 0); 

    for(int i=1 ; i<=n ; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i-1] ; 
    } 
 
    for(int i=0 ; i<=n ; i++) {
        int toFind = x + prefixSum[i] ; 

        auto bound = lower_bound(prefixSum.begin() , prefixSum.end() , toFind ) ; 

        if( bound != prefixSum.end() && *bound != toFind ) {
            int len = bound - ( prefixSum.begin() + i ) ;  
            res = min( res , len ) ; 
        }
    }  

    if( res == INT_MAX ) {
        return 0 ; 
    } 

    return res ;

} 

int main(){
    vector<int> arr = {1, 4, 45, 6, 10, 19} ;  

    cout << smallestSubArray1(arr , 51) << endl; 
    
    cout << smallestSubArray2( arr , 51 ) << endl;     
    

    return 0 ; 
} 