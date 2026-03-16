// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

#include <iostream>  
#include <vector> 
#include <unordered_map> 

using namespace std ;

int solve(vector<int> &nums) {
    int n = nums.size() ; 
    
    unordered_map<int ,int> sumIndex ; 

    int sum = 0 ; 
    int maxLen = 0 ; 

    for(int i=0 ; i<n ; i++) {
        sum += nums[i] ; 

        if( sum == 0 ) {
            maxLen = i+1 ; 
        } 

        else if( sumIndex.find(sum) != sumIndex.end() ) {
            maxLen = max( maxLen , i - sumIndex[sum] ) ; 
        } 
        else {
            sumIndex[sum] = i ; 
        } 
    }  

    return maxLen ; 
}

int main(){
    int n ;
    cin >> n ; 

    vector<int> nums(n) ;  
    for(auto &it : nums) cin >> it ; 

    cout << solve(nums) << endl; 

    return 0 ; 

} 

