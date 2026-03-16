#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std ; 


// just count the no of maximums ; 

int solve(vector<int> &nums) {
    int n = nums.size() ; 

    int maxi = INT_MIN ; 

    int count = 0 ; 

    for(int i=0 ; i<n ; i++) {
        if( nums[i] >=  maxi ){
            maxi = nums[i] ; 
            count++ ; 
        }
    }

    return count ; 
}

int main() {
    int t ; 
    cin >> t ; 

    while( t-- ) {
        int n ; 
        cin >> n ; 

        vector<int> nums(n) ;
        for( auto &it : nums ) cin >> it ; 

        cout << solve(nums) << endl; 
    } 

    return 0 ;
}