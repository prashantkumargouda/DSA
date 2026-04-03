#include <bits/stdc++.h> 
using namespace std ; 

class UpperBoundFinder {
public : 
	int upperBound(vector<int> &nums , int x , int n) {
		int low = 0 ; 
		int high = n-1 ; 
		
		int ans = n ; 

		while( low <= high ) {
			int mid = (low + high) / 2 ; 
			if( nums[mid] > x ) {
				ans = mid ;  
				high = mid - 1 ; 
			} 
			else{
				low = mid + 1 ; 
			}
		} 
		return ans ; 
	}
}; 

int main() {
	vector<int> arr = {3, 5, 8, 9, 15, 19};  // Sorted input array
    int n = arr.size();                     // Size of the array
    int x = 9;                              // Target value

    UpperBoundFinder finder;               // Create object
    int ind = finder.upperBound(arr, x, n);  // Call method

    cout << "The upper bound is the index: " << ind << "\n";  // Output result
    return 0;
} 

