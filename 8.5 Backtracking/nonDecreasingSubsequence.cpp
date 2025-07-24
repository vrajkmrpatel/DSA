#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

vector<vector<int>> result;
void solve(int ind, vector<int> &nums, vector<int> &curr)
{

      // base case
      // is len >= 2 add to result
      if (curr.size() >= 2)
      {
            result.push_back(curr);
      }

      unordered_set<int> st; // for no duplicates
      for (int i = ind; i < nums.size(); i++)
      {
            if ((curr.empty() ||
                 nums[i] >= curr.back()) &&
                (st.find(nums[i]) == st.end()))
            {
                  curr.push_back(nums[i]);
                  solve(i + 1, nums, curr);
                  curr.pop_back();

                  st.insert(nums[i]);
            }
      }
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{

      vector<int> curr;
      solve(0, nums, curr);
      return result;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> nums = {4, 6, 7, 7};
      vector<vector<int>> res = findSubsequences(nums);

      cout << "[ ";
      for (auto &row : res)
      {
            cout << "[";
            for (auto &num : row)
            {
                  cout << " " << num << " ";
            }
            cout << "],";
      }
      cout << "] ";

      return 0;
}