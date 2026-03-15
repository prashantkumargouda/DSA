// finding the longest subarray with sum K 

#include <iostream>  
#include <vector> 

using namespace std ;

int longestSubArray(vector<int> &nums , int k) {
    int n = nums.size() ; 

    int left = 0 , maxLen = 0 ; 

    int maxSum = 0 ;  

    int right = 0 ; 
    while( right < n ) {
        maxSum += nums[right++] ;  
        
        while( maxSum > k && left <= right ) {
            maxSum -= nums[left++] ; 
        }   

        if( maxSum == k ) {
            maxLen = max( maxLen , right - left  ) ; 
        }      

    } 

    return maxLen ; 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n) ;
    for(auto &it : nums) cin >> it ; 

    cout << longestSubArray(nums , 15) << endl; 

    return 0 ;

}