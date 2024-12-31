#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int getMaxArea(vector<int> &heights)
{
      int n = heights.size();
      stack<int> st;
      int nse = 0, pse = 0, ele;
      int maxArea = 0;

      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                  // calcualte area for previous element only
                  // when new element is smaller than st.top() element
                  // so new element becomes NSE for previous element
                  // and PSE for previous element is stored on stack
                  ele = st.top();
                  st.pop();
                  nse = i;
                  pse = st.empty() ? -1 : st.top();
                  maxArea = max(heights[ele] * (nse - pse - 1), maxArea);
            }
            // otherwise push index
            st.push(i);
      }

      // if there are element left which are last element which has no NSE
      // and an element which has no PSE
      while (!st.empty())
      {
            nse = n;
            ele = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[ele] * (nse - pse - 1), maxArea);
      }
      return maxArea;
}
int maximalRectangle(vector<vector<int>> &matrix)
{

      // Brute Force
      // By converting matrix into histogram
      // TC: O(N*M)
      // SC:O(N)

      int n = matrix.size();
      int m = matrix[0].size();

      vector<int> arr(m, 0);
      int area = 0;

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < m; j++)
            {
                  if (matrix[i][j] == 1)
                  {
                        arr[j]++;
                  }
                  else
                  {
                        arr[j] = 0;
                  }
            }

            // for each column we calculate getMaxArea
            area = max(area, getMaxArea(arr));
      }
      return area;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<vector<int>> matrix = {{1, 0, 1, 0, 0},
                                    {1, 0, 1, 1, 1},
                                    {1, 1, 1, 1, 1},
                                    {1, 0, 0, 1, 0}};

      cout << maximalRectangle(matrix) << endl;
}