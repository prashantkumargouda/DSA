// Maximum Consecutive Ones After Flipping Zeroes 

#include <iostream>
#include <vector> 
#include <climits> 

using namespace std ; 

int maxOnes(vector<int> &arr , int k ) {
    // explore all the possible subarrays 
    int n = arr.size() ; 
    int res = INT_MIN ; 
    
    for(int i=0 ; i<n ; i++) {
        int count = 0 ; // for each new subarray make the count zero 
        for(int j=i ; j<n ; j++) {
            if( arr[j] == 0 ) {
                count++ ; 
            } 

            if( count <= k ) {
                res = max(res , j-i+1 ) ;
            }
        }
    } 

    return res ; 
} 

int maxOnes2(vector<int> &arr , int k ) {
    int n = arr.size() ; 
    int res = INT_MIN ; 
    int start = 0 , end = 0 ; 
    int count = 0 ; 
    while( end < arr.size() ){
        if( arr[end] == 0 ) {
            count++ ;
        } 

        if( count > k ) {
            if( arr[start] == 0 ) { 
                count-- ; 
            } 
            start++; 
        } 

        res = max( res , end - start + 1 ) ;

        end++ ;  
    } 

    return res ;
}

int main() {
    vector<int> arr= {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}; 
    cout << maxOnes(arr , 2) << endl; 
    cout << maxOnes2(arr , 2) << endl; 

    return 0 ; 
}