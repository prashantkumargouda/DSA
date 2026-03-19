// using the kadanes algo to find the maximum subarray sum

#include <iostream> 
#include <vector> 
#include <climits> 

using namespace std ;

int solve1(vector<int> &nums) {
    int n = nums.size() ; 
    int sum = 0 ; 
    int maxi = INT_MIN ;  

    // -2,1,-3,4,-1,2,1,-5,4 

    for(int i=0 ; i<n ; i++) {
        sum = sum + nums[i] ; 

        maxi = max(sum , maxi) ; 

        if( sum < 0 ) sum = 0 ;   
    }   

    return maxi ; 
}  

int solve2(vector<int> &nums) {
    int n = nums.size() ; 

    int maxSum = INT_MIN ; 

    for(int i=0 ; i<n ; i++) { 
        int currSum = 0 ; 
        for(int j=i ; j<n ; j++) {
            currSum += nums[j] ; 
            maxSum = max( maxSum , currSum ) ; 
        }
    } 

    return maxSum ; 
} 

int solve3(vector<int> &nums) {
    int n = nums.size() ; 
    
    // using the prefixSum method 
    int maxi = INT_MIN ; 
    vector<int> prefixSum( n+1 , 0 ) ; 

    // finding all the prefixSum first  
    for(int i=1 ; i<=n ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i-1] ;  
    } 
    
    for(int i=0 ; i<=n ; i++) {
        for(int j=i+1 ; j<=n ; j++) {
            maxi = max( maxi , prefixSum[j] - prefixSum[i] ) ; 
        } 
    } 

    return maxi ; 
} 

int main() {
    int n ;
    cin >> n ; 

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 

    cout << solve2(nums) << endl; 

    return 0 ; 
}