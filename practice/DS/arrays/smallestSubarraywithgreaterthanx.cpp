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

int smallestSubArray3(vector<int> &arr , int x ) {
    int n = arr.size() ; 

    int i=0 , j=0 , sum =0 ; 
    int res = INT_MAX ; 

    while( j < n ) {

        // finding the sum until it is less than or equal to x   
        // while j < n keep adding to make the sum  
        // the moment it crosses it just stop 
        // check if it j == arr.size() 
        // if yes break the loop 
        // else 
        // start increasing the i value to change the window 
        // now keep doing this and removing the values there is a window 
        // and minimise the res or window

        while( j < arr.size() && sum <= x ){
            sum += arr[j++] ; 
        } 

        if( j == arr.size() && sum <= x ) break ;

        while( i<j && sum - arr[i] > x ){
            sum = sum - arr[i++] ; 
        }  

        res = min( res , j-i ) ;   
        sum = sum - arr[i] ;
        i++ ;
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
    cout << smallestSubArray3(arr , 51) << endl; 
    return 0 ; 
} 