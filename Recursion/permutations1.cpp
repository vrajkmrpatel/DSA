#include <bits/stdc++.h>

using namespace std;

// using extra data structure space
// void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
// {

//       if(ds.size() == nums.size())
//       {
//             ans.push_back(ds);
//             return;
//       }

//       for (int i = 0; i < nums.size(); i++)
//       {
//             if(!freq[i])
//             {
//                   ds.push_back(nums[i]);
//                   freq[i] = 1;
//                   recurPermute(ds, nums, ans, freq);
//                   freq[i] = 0;
//                   ds.pop_back();
//             }
//       }
// }

void recurPermute(int ind, vector<int> &nums, vector<vector<int>> &ans)
{
      if (ind == nums.size())
      {
            ans.push_back(nums);
            return;
      }

      for (int i = ind; i < nums.size(); i++)
      {
            swap(nums[ind], nums[i]);
            recurPermute(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
      }
}

vector<vector<int>> permute(vector<int> &nums)
{
      // vector<vector<int>> ans;
      // vector<int> ds;

      // int freq[nums.size()] = {0};
      // recurPermute(ds, nums, ans, freq);
      // return ans;

      vector<vector<int>> ans;
      recurPermute(0, nums, ans);
      return ans;
}

int main()
{
      vector<int> nums = {1, 1, 2};

      vector<vector<int>> ans = permute(nums);

      cout << "[";
      for (int i = 0; i < ans.size(); i++)
      {
            cout << "[";
            for (auto it : ans[i])
            {
                  cout << " " << it << " ";
            }
            cout << "]" << ",";
      }
      cout << "]";
      return 0;
}