#include <bits/stdc++.h>

using namespace std;

void monotonicIncreasing(vector<int> &arr)
{
      int n = arr.size();

      stack<int> st;
      vector<int> result;
      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && st.top() > arr[i])
            {
                  st.pop();
            }
            st.push(arr[i]);
      }

      while (!st.empty())
      {
            result.insert(result.begin(), st.top());
            st.pop();
      }

      for (int it: result)
      {
            cout << it << " ";
      }
}
int main()
{
      vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};

      monotonicIncreasing(nums);
      return 0;
}