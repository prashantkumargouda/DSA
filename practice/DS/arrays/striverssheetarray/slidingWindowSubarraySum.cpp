// finding the sum which is less than or equal to the target 
#include <iostream> 
#include <vector> 

using namespace std ; 

pair<int , int> longestSubarraySum(vector<int> &nums , int target) {
    int n = nums.size() ; 

    int left = 0 , sum = 0 , maxLen = 0 , maxSum = INT_MIN ; 

    for(int right = 0 ; right < n ; right++) {
        sum += nums[right] ; 
        while( sum > target ) {
            sum = sum - nums[left++] ; 
        } 

        if( right - left + 1 > maxLen ) {
            maxLen = right - left + 1 ; 
            maxSum = max(sum , maxSum) ; 
        }
    } 

    return {maxSum , maxLen} ; 
}