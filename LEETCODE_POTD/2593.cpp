#include <bits/stdc++.h>

using namespace std;

long long findScore(vector<int> &nums)
{
      int n = nums.size();
      long long score = 0;

      vector<pair<int, int>> sorted(n);
      for (int i = 0; i < n; i++)
      {
            sorted[i] = make_pair(nums[i], i);
      }

      sort(sorted.begin(), sorted.end());

      vector<bool> marked(n, false);
      for (int i = 0; i < n; i++)
      {
            int number = sorted[i].first;
            int index = sorted[i].second;
            if (!marked[index])
            {
                  score += number;
                  marked[index] = true;
                  if (index - 1 >= 0)
                  {
                        marked[index - 1] = true;
                  }
                  if (index + 1 < n)
                  {
                        marked[index + 1] = true;
                  }
            }
      }
      return score;
}
int main()
{
      vector<int> nums = {2, 1, 3, 4, 5, 2};
      cout << findScore(nums) << endl;
      return 0;
}