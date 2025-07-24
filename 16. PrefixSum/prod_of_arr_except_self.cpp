#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

vector<int> productExceptSelf(vector<int> &nums)
{
      /* // Brute Force
       // TC:O(N^2)
       // SC: O(1)
       int n = nums.size();
       vector<int> ans(n, 1);
       for (int i = 0; i < n; i++)
       {
             for (int j = 0; j < n; j++)
             {
                   if (i != j)
                         ans[i] *= nums[j];
             }
       }
       return ans;
       */

     /* // Using prefix, suffix
      // TC : O(3*N) N for prefix calculation
      // N for suffix & N for prod calculation
      // SC: O(2*N) N for using prefix suffix arrays
      int n = nums.size();
      vector<int> ans(n, 1);
      vector<int> prefix(n, 1);
      vector<int> suffix(n, 1);

      // prefix
      prefix[0] = 1;
      for (int i = 1; i < n; i++)
      {
            prefix[i] = prefix[i - 1] * nums[i - 1];
      }

      // suffix
      suffix[n - 1] = 1;
      for (int i = n - 2; i >= 0; i--)
      {
            suffix[i] = suffix[i + 1] * nums[i + 1];
      }

      // calculating product array
      for (int i = 0; i < n; i++)
      {
            ans[i] = prefix[i] * suffix[i];
      }
      return ans;
      */

      // Optimize for Space
      // TC:O(N)
      // SC:O(1)
      int n = nums.size();
      vector<int> ans(n, 1);

      // prefix
      for (int i = 1; i < n; i++)
      {
            ans[i] = ans[i - 1] * nums[i - 1];
      }

      // suffix
      int suffix = 1;
      for (int i = n - 2; i >= 0; i--)
      {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
      }

      return ans;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {1, 2, 3, 4};
      vector<int> ans = productExceptSelf(nums);

      for (auto it : ans)
      {
            cout << it << " ";
      }

      return 0;
}