// solved using iterative appraoch
// solved using recursion
// it can be solved using DP

#include <bits/stdc++.h>

using namespace std;

int minCoins(vector<int> &coins, int m, int amount)
{
      // iterative
      sort(coins.begin(), coins.end());

      vector<int> ans;
      int res = 0;
      for (int i = m - 1; i >= 0; i++)
      {
            while (amount >= coins[i])
            {
                  amount -= coins[i];
                  ans.push_back(coins[i]);
                  res += 1;
            }
      }

      return res;

      // Recursion Approach
      // base case
      // if (amount == 0)
      //       return 0;

      // int res = INT_MAX;

      // // for every coin that have smaller value
      // for (int i = 0; i < m; i++)
      // {
      //       if (coins[i] <= amount)
      //       {
      //             int sub_res = minCoins(coins, m, amount - coins[i]);

      //             if (sub_res != INT_MAX && sub_res + 1 < res)
      //                   res = sub_res + 1;
      //       }
      // }

      // return res;
}
int main()
{
      vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
      int m = coins.size();
      int amount = 93;

      cout << "Minimum coins required is: " << minCoins(coins, m, amount);
      return 0;
}