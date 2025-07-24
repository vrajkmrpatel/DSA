#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int waysToSplitArray(vector<int> &nums)
{

      // TC: O(N)
      // SC: O(1)
      int n = nums.size();
      int cnt = 0;
      long long totalSum = 0;
      for (int i = 0; i < n; i++)
      {
            totalSum += nums[i];
      }

      long long lsum = 0;
      for (int i = 0; i < n - 1; i++)
      {
            lsum += nums[i];
            // condition to check
            if (lsum >= (totalSum - lsum))
            {
                  cnt++;
            }
      }
      return cnt;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {10, 4, -8, 7};
      cout << waysToSplitArray(nums);

      return 0;
}