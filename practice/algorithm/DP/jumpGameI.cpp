// jump game I - find if is possible to reach n-1 or not

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();

    int farthest = 0;

    for (int i = 0; i < n; i++)
    {
        if (farthest < i)
            return false; // if it is not reachable even to the i index

        farthest = max(farthest, i + nums[i]);

        if (farthest >= nums.size() - 1)
            return true;
    }

    return true;
}

// recursion solution
bool check1(int ind, vector<int> &nums)
{
    if (ind >= nums.size() - 1)
        return true;

    int jumps = nums[ind];

    for (int i = 1; i <= jumps; i++)
    {
        if (check1(ind + i, nums))
            return true;
    }

    return false;
}

// memoization solution
bool check2(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind >= nums.size() - 1)
        return true;

    if (dp[ind] != -1)
        return dp[ind];

    for (int i = 1; i <= nums[ind]; i++)
    {
        if (check2(ind + i, nums, dp))
            return dp[ind] = true;
    }

    return dp[ind] = false;
}

// tabulation solution

bool check3(vector<int> &nums) { 
    int n = nums.size() ; 
    vector<bool> dp( n , false ) ;  

    dp[n-1] = true ; 

    for(int i=n-2 ; i>=0 ; i--){ 

        if( nums[i] + i >= n-1 ) {
            dp[i] = true ; 
            continue ; 
        } 

        for(int j=1 ; j<= nums[i] ; j++) {   
            int next = i + j ; 
            if( next < n && dp[next] ) {
                dp[i] = true ; 
                break ; 
            }
        }
    } 

    return dp[0] ; 
}