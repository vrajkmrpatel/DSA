// Sum of Subarray Minimums

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> findPSEE(vector<int> &arr)
{
      int n = arr.size();
      vector<int> psee(n, -1);
      stack<int> st;
      for (int i = 0; i < n; i++)
      {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                  st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
      }
      return psee;
}

vector<int> findNSE(vector<int> &arr)
{
      int n = arr.size();
      vector<int> nse(n, n);
      stack<int> st;
      for (int i = n - 1; i >= 0; i--)
      {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                  st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
      }
      return nse;
}
int sumSubarrayMins(vector<int> &arr)
{

      // Brute Force
      // Time Complexity: O(n^3)
      // Space Complexity: O(1)
      // int n = arr.size();
      // int total = 0;
      // for (int i = 0; i < n; i++)
      // {
      //       for (int j = i; j < n; j++)
      //       {
      //             int minEle = arr[i];
      //             for (int k = i; k <= j; k++)
      //             {
      //                   if (arr[k] < minEle)
      //                   {
      //                         minEle = arr[k];
      //                   }
      //             }
      //             total += minEle;
      //       }
      // }
      // return total;

      // Optimized Approach
      // Time Complexity: O(n)
      // Space Complexity: O(n)
      int n = arr.size();
      vector<int> nse(n);
      vector<int> psee(n);
      nse = findNSE(arr);
      psee = findPSEE(arr);
      long long mod = 1e9 + 7;
      long long left, right;

      int total = 0;
      for (int i = 0; i < n; i++)
      {
            left = i - psee[i];
            right = nse[i] - i;
            total = (total + (left* right* 1LL * arr[i]) % mod) % mod;
      }
      return total;
}
int main()
{
      vector<int> arr = {11, 81, 94, 43, 3};
      cout << sumSubarrayMins(arr) << endl;

      return 0;
}