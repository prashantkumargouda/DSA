// maximum no of points with cost

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

typedef long long ll;

using namespace std;

// dp memoization technique
long long maxP(int ind, int last, vector<vector<int>> &points, int m, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        ll maxi = LLONG_MIN;
        for (int i = 0; i < m; i++)
        {
            maxi = max(maxi, (ll)points[ind][i] - abs(i - last));
        }
        return maxi;
    }

    if (dp[ind][last] != -1)
        return dp[ind][last];
    ll maxi = LLONG_MIN;

    for (int i = 0; i < m; i++)
    {
        ll check = points[ind][i] - abs(i - last);
        maxi = max(maxi, check);
    }
    return dp[ind][last] = maxi;
}

// tabulation method 
long long maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int m = points[0].size();

    // dp[i][j] = max points we can collect
    //            from row 0 to row i, ending at column j
    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    // base case: fill first row as it is
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = points[0][j];
    }

    // fill row by row
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long best = LLONG_MIN;
            // try every column k from previous row
            for (int k = 0; k < m; k++)
            {
                long long val = dp[i - 1][k] + points[i][j] - abs(j - k);
                best = max(best, val);
            }
            dp[i][j] = best;
        }
    }

    // answer is max value in last row
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
} 

// space optimized technique
long long maxPoints1(vector<vector<int>> &points)
{
    int n = points.size();
    int m = points[0].size();

    // only keep previous row instead of entire n x m table
    vector<long long> prev(m);

    // base case: first row
    for (int j = 0; j < m; j++)
    {
        prev[j] = points[0][j];
    }

    // fill row by row
    for (int i = 1; i < n; i++)
    {
        vector<long long> curr(m, LLONG_MIN);

        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                long long val = prev[k] + points[i][j] - abs(j - k);
                curr[j] = max(curr[j], val);
            }
        }

        prev = curr; // current row becomes previous for next iteration
    }

    return *max_element(prev.begin(), prev.end());
}

// most optimized version  
// uses O(n^2) time complexity 

long long maxPoints2(vector<vector<int>> &points) {
    int n = points.size() ; 
    int m = points[0].size() ; 
    
    vector<ll> dp( m ) ; 

    for(int i=0 ; i<m ; i++) {
        dp[i] = points[0][i] ;
    } 

    for(int i=1 ; i<n ; i++) {
        vector<ll> temp(m) ; 

        
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, -1));
}