// finding the max consecutive ones in nums array after flipping K 0's 

#include <bits/stdc++.h> 
using namespace std ; 

/*  
    1,1,1,0,0,0,1,1,1,1,0 
    k=2 

*/ 
int longestOne(vector<int> &nums , int k) {
    // finding all the subarrays 
    int maxLen = 0 ; 

    // here for each subarray we try counting the number of 0's 
    // if the number of 0's exceed the k value just terminate the subarray we dont need it 

    for(int i=0 ; i<nums.size() ; i++) { 
        int zeros = 0 ; 
        for(int j=i ; j<nums.size() ; j++){
            if( nums[j] == 0 ) {
                zeros++ ; 
            }  
            
            if( zeros > k ) break ;  

            maxLen = max( maxLen , j-i+1 ) ; 
        }
    } 

    return maxLen ; 
} 

int longestOnes(vector<int> &nums , int k) {
    int maxCount = 0 ; 
    int left = 0 ; 
    int zeros = 0 ; 

    for(int right = 0 ; right < nums.size() ; right++) {  
        if( nums[right] == 0 ) zeros++ ; 

        if( zeros > k ) {
            if( nums[left] == 0 ) {
                zeros-- ; 
            } 
            left++ ; 
        } 

        maxCount = max( maxCount , right - left + 1 ) ; 
    } 

    return maxCount ; 
}