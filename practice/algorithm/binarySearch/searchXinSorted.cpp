// Search X in a sorted array 

#include <iostream>  
#include <vector> 

using namespace std ;  

class Solution {
public : 
    int binarySearch(vector<int> &nums , int target) {
        int n = nums.size() ; 
        int low = 0 ; 
        int high = n-1 ; 

        while( low <= high ) {
            int mid = (low + high) / 2 ;  

            if( nums[mid] == target ) {
                return mid ; 
            } 
            else if( nums[mid] > target ) {
                high = mid - 1 ; 
            } 
            else{
                low = mid + 1 ;
            }
        } 
        return -1 ;
    }

}; 

int main() {

    vector a = {3, 4, 6, 7, 9, 12, 16, 17}; 
    int target = 6; 
    int n = a.size() ; 

    Solution obj ; 
    int ind = obj.binarySearch(a , target) ; 

    if( ind == -1 ) cout << "Target not found" << endl; 
    else cout << "target found at position :" << ind << endl; 

    return 0  ; 
}