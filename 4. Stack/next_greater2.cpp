#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
      int n = nums.size();
      vector<int> nge(n, -1);
      stack<int> st;

      for (int i = 2 * n - 1; i >= 0; i--)
      {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                  st.pop();
            }

            if (i < n)
            {
                  if (!st.empty())
                  {
                        nge[i] = st.top();
                  }
            }
            st.push(nums[i % n]);
      }
      return nge;
}

int main()
{
      vector<int> nums = {5, 7, 1, 2, 6, 0};

      vector<int> ans = nextGreaterElements(nums);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}