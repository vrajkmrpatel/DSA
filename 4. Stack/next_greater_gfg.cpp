#include <bits/stdc++.h>

using namespace std;
vector<int> nextGreaterElement(vector<int> &arr)
{
      // Using Stack
      int n = arr.size();
      vector<int> ans(n, -1);
      stack<int> st;

      for (int i = n - 1; i >= 0; i--)
      {
            while (!st.empty() && st.top() <= arr[i])
            {
                  st.pop();
            }

            if (i < n)
            {
                  if(!st.empty())
                        ans[i] = st.top();
            }
            st.push(arr[i]);
      }
      return ans;
}
int main()
{
      vector<int> nums = {6, 8, 0, 1, 3};

      vector<int> ans = nextGreaterElement(nums);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}