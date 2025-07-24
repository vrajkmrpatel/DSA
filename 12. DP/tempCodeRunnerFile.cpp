vector<vector<int>> dp(n, vector<int>(4, 0));
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