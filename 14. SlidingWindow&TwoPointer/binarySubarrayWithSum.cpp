#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int numSubarraysWithSum(vector<int> &nums, int goal)
{

      // Brute Force
      int n = nums.size();
      int ans = 0;
      for (int i = 0; i < n; i++)
      {
            int sum = nums[i];
            for (int j = i; j < n; j++)
            {
                  sum += nums[j];
                  if (sum == goal)
                        ans++;
                  if (sum > goal)
                        break;
            }
      }
      return ans;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {1, 0, 1, 0, 1};
      int goal = 2;
      cout << numSubarraysWithSum(nums, goal);

      return 0;
}