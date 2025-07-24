#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int goodSubarray(vector<int> &nums, int k)
{
      int n = nums.size();
      int cnt = 0;
      unordered_map<int, int> map;
      int l = 0, r = 0;
      while (r < n)
      {
            map[nums[r]]++;
            while (map.size() > k)
            {
                  map[nums[l]]--;
                  if (map[nums[l]] == 0)
                  {
                        map.erase(nums[l]);
                  }
                  l++;
            }
            cnt += (r - l + 1);
            r++;
      }
      return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{

      return goodSubarray(nums, k) - goodSubarray(nums, k - 1);
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {1, 2, 1, 2, 3};
      int k = 2;
      cout << subarraysWithKDistinct(nums, k);

      return 0;
}