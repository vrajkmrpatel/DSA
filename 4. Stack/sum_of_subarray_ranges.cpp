// Sum of Subarray Ranges

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// vector<int> findPSEE(vector<int> &arr)
// {
//       int n = arr.size();
//       vector<int> psee(n, -1);
//       stack<int> st;
//       for (int i = 0; i < n; i++)
//       {
//             while (!st.empty() && arr[st.top()] > arr[i])
//             {
//                   st.pop();
//             }
//             psee[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//       }
//       return psee;
// }

// vector<int> findNSE(vector<int> &arr)
// {
//       int n = arr.size();
//       vector<int> nse(n, n);
//       stack<int> st;
//       for (int i = n - 1; i >= 0; i--)
//       {
//             while (!st.empty() && arr[st.top()] >= arr[i])
//             {
//                   st.pop();
//             }
//             nse[i] = st.empty() ? n : st.top();
//             st.push(i);
//       }
//       return nse;
// }
long long subArrayRanges(vector<int> &nums)
{

      // Brute Force
      // Time Complexity: O(n^2)
      // Space Complexity: O(1)
      // int n = nums.size();
      // long long total = 0;
      // for (int i = 0; i < n; i++)
      // {
      //       int minE = nums[i];
      //       int maxE = nums[i];
      //       for (int j = i; j < n; j++)
      //       {
      //             minE = min(minE, nums[j]);
      //             maxE = max(maxE, nums[j]);
      //             total += (maxE - minE);
      //       }
      // }
      // return total;

      // Optimized Approach
      // Time Complexity: O(n)
      // Space Complexity: O(n)
      int n = nums.size();
      long long sum = 0;
      stack<int> st;
      vector<int> minPrev(n, -1), minNext(n, n), maxPrev(n, -1), maxNext(n, n);

      // Previous Smaller Element
      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                  st.pop();
            }
            if (!st.empty())
                  minPrev[i] = st.top();
            st.push(i);
      }
      while (!st.empty())
      {
            st.pop();
      }

      // Next Smaller Element
      for (int i = n - 1; i >= 0; i--)
      {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                  st.pop();
            }
            if (!st.empty())
                  minNext[i] = st.top();
            st.push(i);
      }

      // Previous Larger Element
      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                  st.pop();
            }
            if (!st.empty())
                  maxPrev[i] = st.top();
            st.push(i);
      }
      while (!st.empty())
      {
            st.pop();
      }

      // Next Larger Element
      for (int i = n - 1; i >= 0; i--)
      {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                  st.pop();
            }
            if (!st.empty())
                  maxNext[i] = st.top();
            st.push(i);
      }

      // Calculating Sum of Ranges
      for (int i = 0; i < n; i++)
      {
            long leftMin = i - minPrev[i];
            long rightMin = minNext[i] - i;
            long lefMax = i - maxPrev[i];
            long rightMax = maxNext[i] - i;

            sum += (lefMax * rightMax - leftMin * rightMin) * nums[i];
      }
      return sum;
}
int main()
{
      vector<int> arr = {4, -2, -3, 4, 1};
      cout << subArrayRanges(arr) << endl;

      return 0;
}