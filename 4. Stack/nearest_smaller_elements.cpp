#include <bits/stdc++.h>

using namespace std;
vector<int> nearestSmaller(vector<int> &arr)
{
      // Using Stack
      int n = arr.size();
      stack<int> st;
      vector<int> nse(n, -1);

      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && st.top() >= arr[i])
            {
                  st.pop();
            }

            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
      }
      return nse;
}
int main()
{
      vector<int> nums = {4, 5, 2, 10, 8};

      vector<int> ans = nearestSmaller(nums);
      for (auto it : ans)
      {
            cout << it << " ";
      }
      return 0;
}