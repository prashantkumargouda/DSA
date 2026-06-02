// finding the minimum difference between highest and lowest of K scores

/*
    To explain this better, which this description failed to do in my opinion. Let's assume we have the following array {20, 200,300, 1000 } and that k is 3
we would need to compare subarrays of size k and get the minimum value out of the subtraction between the lowest and highest number of that subarray.
To illustrate:
{20,200, 300} the difference between the highest (300) and lowest (20) number will be 280
{200, 300, 1000} the difference between the highest (1000) and lowest (200) will be 800
That's it there are not more subarrays of size K and so we compare 800 and 280 and the smallest difference is 280.

*/

#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = k - 1;
    int mini = INT_MAX;

    while (right < n)
    {
        mini = min(mini, nums[right] - nums[left]);
        left++;
        right++;
    }

    return mini;
}

static int minimumDifference(vector<int> &nums, int k)
{
    const int n = nums.size();
    if (k == 1)
        return 0;
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    for (int l = 0, r = k - 1; r < n; r++, l++)
    {
        diff = min(diff, nums[r] - nums[l]);
    }
    return diff;
}