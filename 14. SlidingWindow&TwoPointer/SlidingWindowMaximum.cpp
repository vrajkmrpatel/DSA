#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
      /*
      // Brute Force
      // Time : O(N - K) * K
      // Space : O(N - K)
      int n = nums.size();
      vector<int> ans;
      for (int i = 0; i <= n - k; i++)
      {
            int maxi = nums[i];

            for (int j = i; j <= i + k - 1; j++)
            {
                  maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
      }
      return ans;
      */

      // Optimal Solution
      // Time : O(N)
      // Space : O(K) + O(N - K)
      int n = nums.size();
      vector<int> list;
      deque<int> dq;
      for (int i = 0; i < n; i++)
      {
            if (!dq.empty() && dq.front() <= i - k)
            {
                  dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                  dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                  list.push_back(nums[dq.front()]);
            }
      }
      return list;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {6, 5, 4, 3, 2, 1};
      int k = 3;

      vector<int> ans = maxSlidingWindow(nums, k);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}