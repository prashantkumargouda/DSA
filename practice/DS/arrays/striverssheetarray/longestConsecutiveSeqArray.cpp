// finding the longest consecutive sequence in an array 

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <climits> 

using namespace std; 

int solve1(vector<int> &nums) {
    int n = nums.size() ; 

    sort(nums.begin() , nums.end()) ; 

    int count = 1 ; 
    int maxi = 0 ; 

    for(int i=0 ; i<n-1 ; i++) {  
        if( nums[i] == nums[i+1] ) continue;

        if( nums[i] + 1 == nums[i + 1] ) {
            count = count + 1 ;  
            maxi = max( maxi , count ) ; 
        } 
        else {
            count = 0 ; 
        }
    } 
    
    return maxi + 1 ; 
}  

// 0 0 1 2 3 4 5 6 7 8

int main() {
    int n ;
    cin >> n;

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it; 

    cout << solve1(nums) << endl; 

    return 0 ; 
}