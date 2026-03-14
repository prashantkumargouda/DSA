// Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

// Example:

// Input: heights[] = [20, 30, 40, 20]
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20 - 30| = 10
// Total Cost = 10 + 10 = 20
// Input: heights[] = [30, 20, 50, 10, 40]
// Output: 30
// Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
// jump from stair 0 to 2: cost = |50 - 30| = 20
// jump from stair 2 to 4: cost = |40 - 50| = 10
// Total Cost = 20 + 10 = 30

// trying out the memoization tabulation methods to solve the problem 

#include <iostream> 
#include <vector> 

using namespace std  ;

// simple recursive solution 
int f1(int ind , vector<int> &heights) {
    if(ind == 0) return 0 ; 
    
    int left = f1(ind -1 , heights) + abs( heights[ind] - heights[ind - 1]); 
    int right = INT_MAX;  

    if( ind > 1 ) right = f1(ind - 2 , heights) + abs( heights[ind] - heights[ind-2] ) ;  

    return min( left , right ) ; 
} 

// memoization top to bottom
int f2(int ind  , vector<int> &heights , vector<int> &dp )  {
    if( ind == 0 ) return 0 ; 
    if( dp[ind] != - 1 ) return dp[ind] ; 

    int left = f2(ind - 1 , heights , dp ) + abs( heights[ind] - heights[ind - 1]) ; 
    int right = INT_MAX ; 
    int right = f2(ind - 2 , heights , dp ) + abs( heights[ind] - heights[ind - 2]) ; 

    return dp[ind] = min( left , right ) ; 
}

// tabulation bottom up 
int f3( vector<int> &heights , int n ) {
    vector<int> dp( n , 0 ) ; 

    dp[0] = 0 ; 

    for(int i=1 ; i<n ; i++ ){
        int left = dp[n-1] + abs( heights[i] - heights[i-1] ) ; 
        int right = INT_MAX;   

        if( i>1 ) right = dp[n-2] + abs( heights[i] - heights[i-2] ) ;  

        dp[i] = min( left , right ) ; 
    }  

    return dp[n-1] ; 
} 

int f4(int n , vector<int> &heights){
    int prev = 0 , prev2 = 0; 

    for(int i=1 ; i<n ; i++) {
        int left = prev + abs( heights[i] - heights[i-1] ) ;  
        int right = INT_MAX ; 
         
        right = prev2 + abs( heights[i] - heights[i-1] ) ;   

        int curi = min( left , right ) ; 

        prev2 = prev ; 
        prev = curi ; 
    } 

    return prev ; 
}

int main() { 
    int n ; 
    cin >> n ; 

    vector<int> heights(n)  ; 
    for( auto &it : heights) cin >> it ; 

    vector<int> dp( n+1 , -1 ) ;  
    cout << f2(n-1 , heights , dp ) << endl;  
}