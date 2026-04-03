#include <bits/stdc++.h> 
using namespace std ; 

class Solution {
public : 
    int lowerBound(vector<int> &arr , int x ) {
        int n = arr.size() ;  

        int low = 0 ; 
        int high = n-1 ;  
        int ans = n ; 

        while( low <= high ) {
            int mid = ( low + high ) / 2 ; 
            if( arr[mid] >= x ) {
                ans = mid ;  
                high = mid - 1 ; 
            } 
            else {
                low = mid + 1 ;
            }
        } 

        return ans ; 
    } 
} ;

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};  // Sorted input array
    int n = arr.size();                  // Size of array
    int x = 9;  

    Solution obj ; 
    int ind = obj.lowerBound(arr , x) ; 

    cout << ind << endl; 

    return 0 ;
}