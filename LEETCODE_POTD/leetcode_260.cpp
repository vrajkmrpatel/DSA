#include <bits/stdc++.h>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
      unordered_map<int, int> mpp;

      for (int i = 0; i < nums.size(); i++)
      {
            mpp[nums[i]]++;
      }

      vector<int> ans;
      for (int i = 0; i < nums.size(); i++) {

            
      }
}

int main()
{
      vector<int> nums = {1, 2, 1, 3, 2, 5};
      singleNumber(nums);

      return 0;
}