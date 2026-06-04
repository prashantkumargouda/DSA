// Minimum size subarray sum
// finding the min length of subarray where subarray sum is equal to target

#include <bits/stdc++.h>
using namespace std;

int minLength(int target, vector<int> &nums)
{
    int n = nums.size();

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // can use this to find the subarray sum
    // sum(l,r) = prefix[r+1] - prefix[l]  # inclusive l and r

    int sum = 0;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = prefix[j + 1] - prefix[i];

            if (sum >= target)
            {
                mini = min(mini, j - i + 1);
            }
        }
    }
    return mini;
}

int minLength(int target , vector<int> &nums) {
    int n = nums.size() ;  
    int mini = INT_MAX ; 

    int sum = 0; 
    int left = 0 ; 

    for(int right = 0 ; right < n ; right++ ) {
        sum += nums[right] ; 

        while( sum >= target ) {
            mini = min( mini , right - left + 1 ) ; 
            sum = sum - nums[left++] ; 
        } 
    } 

    return ( mini == INT_MAX ) ? 0 : mini ; 

}