#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int solve(int ind, vector<int> &height, vector<int> &dp)
{
      if (ind == 0)
            return 0;

      if (dp[ind] != -1)
            return dp[ind];
      int left = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
      int right = INT_MAX;
      if (ind > 1)
      {
            right = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
      }

      return dp[ind] = min(left, right);
}
int minCost(vector<int> &height)
{
      // Code here

      // Recursion
      int n = height.size();

      // Using memoization
      // vector<int> dp(n + 1, -1);
      // return solve(n - 1, height, dp);

      // Using Tabulation
      // vector<int> dp(n, 0);
      // dp[0] = 0;

      // for (int i = 1; i < n; i++)
      // {
      //       int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
      //       int ss = INT_MAX;
      //       if (i > 1)
      //       {
      //             ss = dp[i - 2] + abs(height[i] - height[i - 2]);
      //       }
      //       dp[i] = min(fs, ss);
      // }
      // return dp[n - 1];

      // Space Optimization
      int prev = 0;
      int prev2 = 0;

      for (int i = 1; i < n; i++)
      {
            int fs = prev + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
            {
                  ss = prev2 + abs(height[i] - height[i - 2]);
            }
            int curi = min(fs, ss);
            prev2 = prev;
            prev = curi;
      }
      return prev;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> height = {30, 10, 60, 10, 60, 50};
      cout << minCost(height);

      return 0;
}