#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(std::vector<int> &weights, std::vector<int> &values, int W)
{
      int n = weights.size();
      std::vector<std::vector<int>> DP(n + 1, std::vector<int>(W + 1, 0));

      for (int i = 1; i <= n; ++i)
      {
            for (int w = 0; w <= W; ++w)
            {
                  if (weights[i - 1] <= w)
                  {
                        DP[i][w] = std::max(DP[i - 1][w], DP[i - 1][w - weights[i - 1]] + values[i - 1]);
                  }
                  else
                  {
                        DP[i][w] = DP[i - 1][w];
                  }
            }
      }
      return DP[n][W];
}

int main()
{
      std::vector<int> weights = {1, 3, 4, 5};
      std::vector<int> values = {1, 4, 5, 7};
      int W = 7;
      int maxValue = knapsack(weights, values, W);
      std::cout << "Maximum value in knapsack: " << maxValue << std::endl;
      return 0;
}
