// finding the minimum falling path sum

#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    vector<vector<int>> matrix ;
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> dp(m, 0);

    for (int i = 0; i < m; i++)
    {
        dp[i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            int ld = 1e9;
            int rd = 1e9;

            int s = matrix[i][j] + dp[j];

            if (j > 0)
                ld = matrix[i][j] + dp[j - 1];
            if (j < m - 1)
                rd = matrix[i][j] + dp[j + 1];

            temp[j] = min(min(rd, ld), s);
        }
        dp = temp;
    }

    int mini = dp[0];

    for (int i = 1; i < m; i++)
    {
        mini = min(mini, dp[i]);
    }

    return mini;
}