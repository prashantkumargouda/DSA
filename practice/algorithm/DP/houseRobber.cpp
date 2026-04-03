// maximum sum of Non adjacent Elements 
// House Robber 

#include <iostream>  
#include <vector> 
using namespace std ;  

// memoization 
int f(int ind , vector<int> &nums , vector<int> &dp ) {
    if( ind == 0 ) return nums[ind] ; 
    if( ind < 0 ) return 0 ; 
    if( dp[ind] != -1 ) return dp[ind] ; 

    int pick = nums[ind] + f(ind - 2 , nums , dp ) ; 
    int notPick = 0 + f(ind - 1 , nums , dp) ; 

    return dp[ind] = max( pick , notPick ) ; 
} 

// tabulation method o(n) space and time complexity 
int f1(vector<int> &nums , vector<int> &dp) { 
    int n = nums.size(); 

    dp[0] = nums[0]; 
    for(int i=1 ; i < n ; i++) {
        int take = nums[i] ; 
        if( i > 1 ) take += dp[i-1] ;  
        
        int notTake = dp[i-1] ; 

        dp[i] = max( take , notTake ) ; 
    }  
    return dp[n-1] ; 
} 

// tabulation with space optimization and it follows a bottom up approach
int f2(vector<int> &nums) {
    int n = nums.size() ; 

    int prev2 = 0 , prev = nums[0] ; 

    for(int i=1 ; i<n ; i++) {
        int take = nums[i] ; 
        if( i > 1 ) take += prev2 ; 
        
        int notTake = prev ; 

        int curr = max(take , notTake) ; 

        prev2 = prev ;
        prev = curr ; 
    } 

    return prev ; 
} 

int main() {
    int n ;
    cin >> n ; 

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 

    vector<int> dp( n , -1 ) ; 

    cout << f( n-1 , nums , dp ) << endl; 

    return 0 ; 
}