#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int longestOnes(vector<int> &nums, int k)
{

      /* // Brute Force
       // TC: O(N^2)
       // SC: O(1)
       int n = nums.size();
       int maxlen = 0, len = 0;
       for (int i = 0; i < n; i++)
       {
             int zeros = 0;
             for (int j = i; j < n; j++)
             {
                   if (nums[j] == 0)
                   {
                         zeros++;
                   }
                   if(zeros <= k)
                   {
                         len = j - i + 1;
                         maxlen = max(maxlen, len);
                   }
                   else {
                         break;
                   }
             }
       }
       return maxlen;
       */

      // Most Optimal
      // TC: O(N)
      // SC: O(1)
      int n = nums.size();
      int l = 0, r = 0, zeros = 0;
      int len = 0, maxlen = 0;
      while (r < nums.size())
      {
            if (nums[r] == 0)
                  zeros++;
            if (zeros > k)
            {
                  if (nums[l] == 0)
                        zeros--;
                  l++;
            }
            if (zeros <= k)
            {
                  len = r - l + 1;
                  maxlen = max(len, maxlen);
            }
            r++;
      }
      return maxlen;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
      int k = 2;
      cout << longestOnes(nums, k) << endl;

      return 0;
}