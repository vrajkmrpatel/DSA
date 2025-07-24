#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int f(int i, int j)
{
      // base condition
      if (i == 0 && j == 0)
      {
            return 1;
      }
      if (i < 0 || j < 0)
      {
            return 0;
      }

      int up = f(i - 1, j);
      int left = f(i, j - 1);
      return up + left;
}
int f(int i, int j, vector<vector<int>> &dp)
{
      // base condition
      if (i == 0 && j == 0)
      {
            return 1;
      }
      if (i < 0 || j < 0)
      {
            return 0;
      }

      if (dp[i][j] != -1)
            return dp[i][j];
      int up = f(i - 1, j, dp);
      int left = f(i, j - 1, dp);
      return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{

      // Using Recursion
      // return f(m - 1, n - 1);

      // Memoization
      // vector<vector<int>> dp(m, vector<int>(n, -1));
      // return f(m - 1, n - 1, dp);

      // Tabulation
      vector<vector<int>> dp(m, vector<int>(n, 0));

      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  if (i == 0 && j == 0)
                  {
                        dp[i][j] = 1;
                  }
                  else
                  {
                        int up = 0, left = 0;
                        if (i > 0)
                              up = dp[i - 1][j];
                        if (j > 0)
                              left = dp[i][j - 1];

                        dp[i][j] = up + left;
                  }
            }
      }
      return dp[m - 1][n - 1];
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int m = 3, n = 7;
      cout << uniquePaths(m, n);

      return 0;
}