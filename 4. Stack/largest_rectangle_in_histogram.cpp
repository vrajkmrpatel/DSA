#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

// Previous Smaller Element
vector<int> findPSE(vector<int> &nums)
{
      int n = nums.size();
      vector<int> pse(n, -1);
      stack<int> st;
      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                  st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
      }
      return pse;
}

// Next Smaller Element
vector<int> findNSE(vector<int> &nums)
{
      int n = nums.size();
      vector<int> nse(n, n);
      stack<int> st;
      for (int i = n - 1; i >= 0; i--)
      {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                  st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
      }
      return nse;
}

int largestRectangleArea(vector<int> &heights)
{

      /* int n = heights.size();
       vector<int> pse = findPSE(heights);
       vector<int> nse = findNSE(heights);

       int maxi = 0;

       for(int i = 0; i<n; i++)
       {
             maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
       }
       return maxi;
       */

      // Optimal Solution
      // Time : O(N) + O(N)
      // Space  O(N)

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
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> heights = {3, 2, 10, 11, 5, 10, 6, 3};
      cout << largestRectangleArea(heights) << endl;

      return 0;
}