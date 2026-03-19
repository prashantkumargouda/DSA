// finding the longest subarray with sum K 

#include <iostream>  
#include <vector> 
#include <unordered_map> 

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

int solve2(vector<int> &nums , int k ) {
    int n = nums.size() ; 

    int sum = 0 ; 
    int maxLen = 0 ; 

    unordered_map<int , int> mp ; 

    for(int i=0 ; i<n ; i++) {
        sum += nums[i] ; 

        if( sum == k ) maxLen = i+1 ; 

        if( mp.find(sum - k) != mp.end() ) {
            maxLen = max( maxLen , i - mp[sum - k] ) ; 
        } 

        if( mp.find(sum) == mp.end() ) {
            mp[sum] = i ; 
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