#include <bits/stdc++.h>

using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
      int cntCows = 1;
      int last = stalls[0];

      for (int i = 1; i < stalls.size() - 1; i++)
      {

            if (stalls[i] - last >= dist)
            {
                  cntCows++;
                  last = stalls[i];
            }

            if (cntCows >= cows)
                  return true;
      }
      return false;
}

int solve(int n, vector<int> &stalls, int cows)
{

      sort(stalls.begin(), stalls.end());

      // Using iterative solution
      // TC: O(max - min)* O(N)
      // SC: O(1)

      // int max = *max_element(stalls.begin(), stalls.end());
      // int min = *min_element(stalls.begin(), stalls.end());

      // for (int i = 1; i <= max - min; i++)
      // {

      //       if (canWePlace(stalls, i, cows))
      //       {
      //             continue;
      //       }
      //       else
      //       {
      //             return i - 1;
      //       }
      // }
      // return -1;

      // Using Binary Search

      int low = 1;
      int high = stalls[n - 1] - stalls[0];

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (canWePlace(stalls, mid, cows))
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }
      return high;
}

int main()
{

      vector<int> arr = {1, 2, 4, 8, 9};
      int n = arr.size();

      int k = 3;

      int ans = solve(n, arr, k);

      cout << ans;
      return 0;
}