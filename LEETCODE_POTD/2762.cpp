#include <bits/stdc++.h>

using namespace std;

long long continuousSubarrays(vector<int> &nums)
{
      int n = nums.size();
      map<int, int> freq;
      int left = 0, right = 0;
      int count = 0;

      while (right < n)
      {
            freq[nums[right]]++;

            while (freq.rbegin()->first - freq.begin()->first > 2)
            {
                  freq[nums[left]]--;
                  if (freq[nums[left]] == 0)
                  {
                        freq.erase(nums[left]);
                  }
                  left++;
            }

            count += right - left + 1;
            right++;
      }
      return count;
}
int main()
{
      vector<int> nums = {5, 4, 2, 4};

      cout << continuousSubarrays(nums) << endl;

      return 0;
}