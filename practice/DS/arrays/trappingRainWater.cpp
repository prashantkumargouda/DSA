// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
#include <iostream> 
#include <algorithm>
#include <vector>  
#include <climits>

using namespace std  ;

int trap(vector<int> &arr) { 

    // okay this takes O(n) space comp and O(3n) time comp 
    int n = arr.size() ; 

    // using prefixMax and SuffixMax  

    vector<int> prefixMax(n) ; 
    vector<int> suffixMax(n) ; 

    prefixMax[0] = arr[0] ; 
    suffixMax[n-1] = arr[n-1] ; 

    for(int i=1 ; i<n ; i++) {
        prefixMax[i] = max( prefixMax[i-1] , arr[i] ); 
    } 

    for(int i=n-2 ; i>=0 ; i--) {
        suffixMax[i] = max( suffixMax[i+1] , arr[i] ); 
    } 

    int total = 0 ; 
    for(int i=0 ; i<n ; i++) {
        total += min( prefixMax[i] , suffixMax[i] ) - arr[i] ; 
    } 

    return total ; 
}  
 
int trap1(vector<int> &arr) {
    // solving it without maintaining the prefixSum  
    // only using the suffixSum 

    int n = arr.size() ; 

    vector<int> suffixMax(n) ; 
    suffixMax[n-1] = arr[n-1] ; 

    // calculating the suffixMax  

    for(int i=n-2 ; i>=0 ; i--) {
        suffixMax[i] = max( suffixMax[i+1] , arr[i] ) ; 
    } 

    int total = 0 ; 
    int prefixMax = INT_MIN ;   
    for(int i=0 ; i<n ; i++) { 
        prefixMax = max( prefixMax , arr[i] ) ; 
        total += min( prefixMax , suffixMax[i] ) - arr[i] ; 
    } 

    return total ; 
}

int trap3(vector<int> &arr){
    int n = arr.size() ; 

    int left = 0 , right = n-1 ; 
    int leftMax = 0 , rightMax = 0 ,  total = 0 ; 

    while( left < right ) {
        if( arr[left] <= arr[right] ) {
            if( leftMax > arr[left] ) {
                total += leftMax - arr[left] ; 
            } 
            else{
                leftMax = arr[left] ; 
            } 

            left = left + 1 ; 
        }else {
            if( rightMax > arr[right] ) {
                total += rightMax - arr[right] ; 
            } 
            else{
                rightMax = arr[right] ; 
            } 

            right = right - 1 ; 
        }
    } 

    return total ; 
}

int main() {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1} ;   
    cout << trap(arr) << endl; 
    cout << trap1(arr) << endl;  
    cout << trap3(arr) << endl; 
    return 0 ;
}