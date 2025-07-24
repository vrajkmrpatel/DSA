#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
      if (day == 0)
      {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                  if (task != last)
                  {
                        maxi = max(maxi, arr[0][task]);
                  }
            }
            return maxi;
      }

      if (dp[day][last] != -1)
            return dp[day][last];

      int maxi = 0;
      for (int task = 0; task < 3; task++)
      {
            if (task != last)
            {
                  int point = arr[day][task] + f(day - 1, task, arr, dp);
                  maxi = max(maxi, point);
            }
      }
      return dp[day][last] = maxi;
}
int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
      if (day == 0)
      {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                  if (task != last)
                  {
                        maxi = max(maxi, arr[0][task]);
                  }
            }
            return maxi;
      }

      if (dp[day][last] != -1)
      {
            return dp[day][last];
      }

      int maxi = 0;
      for (int task = 0; task < 3; task++)
      {
            if (task != last)
            {
                  int point = arr[day][task] + f(day - 1, task, arr, dp);
                  maxi = max(maxi, point);
            }
      }
      return dp[day][last] = maxi;
}
int maximumPoints(vector<vector<int>> &arr)
{
      int n = arr.size();

      // Using Recursion
      // return f(n - 1, 3, arr);

      // Using memoization
      // vector<vector<int>> dp(n, vector<int>(4, -1));
      // return f(n - 1, 3, arr, dp);

      // Using tabulation
      // vector<vector<int>> dp(n, vector<int>(4, 0));
      // dp[0][0] = max(arr[0][1], arr[0][2]);
      // dp[0][1] = max(arr[0][0], arr[0][2]);
      // dp[0][2] = max(arr[0][1], arr[0][0]);
      // dp[0][3] = max(arr[0][1], max(arr[0][2], arr[0][3]));

      // for (int day = 1; day < n; day++)
      // {
      //       for (int last = 0; last < 4; last++)
      //       {
      //             dp[day][last] = 0;
      //             for (int task = 0; task < 3; task++)
      //             {
      //                   if (task != last)
      //                   {
      //                         int point = arr[day][task] + dp[day - 1][task];
      //                         dp[day][last] = max(dp[day][last], point);
      //                   }
      //             }
      //       }
      // }
      // return dp[n - 1][3];

      // Using Space Optimization
      vector<int> prev(4, 0);
      prev[0] = max(arr[0][1], arr[0][2]);
      prev[1] = max(arr[0][0], arr[0][2]);
      prev[2] = max(arr[0][1], arr[0][0]);
      prev[3] = max(arr[0][1], max(arr[0][2], arr[0][3]));

      for (int day = 1; day < n; day++)
      {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                  temp[last] = 0;
                  for (int task = 0; task < 3; task++)
                  {
                        if (task != last)
                        {
                              temp[last] = max(temp[last], arr[day][task] + prev[task]);
                        }
                  }
            }
            prev = temp;
      }
      return prev[3];
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<vector<int>> arr = {{1, 2   , 5}, {3, 1, 1}, {3, 3, 3}};
      cout << maximumPoints(arr);

      return 0;
}