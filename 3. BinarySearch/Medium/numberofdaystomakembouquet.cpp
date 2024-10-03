#include <bits/stdc++.h>

using namespace std;

bool possible(vector<int> &arr, int day, int m, int k)
{

      int cnt = 0;
      int noOfBouqets = 0;

      for (int i = 0; i < arr.size(); i++)
      {

            if (arr[i] <= day)
            {
                  cnt++;
            }
            else
            {
                  noOfBouqets += (cnt / k);
                  cnt = 0;
            }
      }

      noOfBouqets += (cnt / k);

      if (noOfBouqets >= m)
      {
            return true;
      }
      else
      {
            return false;
      }
}

int minDays(vector<int> &arr, int m, int k)
{
      int n = arr.size();
      int mini = *min_element(arr.begin(), arr.end());
      int maxi = *max_element(arr.begin(), arr.end());

      // Brute Force Approach

      // if (n < m * k)
      //       return -1;
      // for (int i = mini; i <= maxi; i++)
      // {
      //       if (possible(arr, i, m, k) == true)
      //       {
      //             return i;
      //       }
      // }

      // return -1;

      int low = mini;
      int high = maxi;

      int ans;

      if (n < m * k)
            return -1;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k))
            {
                  ans = mid;
                  high = mid - 1;
            }
            else
            {
                  low = mid + 1;
            }
      }

      return low;
}

int main()
{

      vector<int> arr = {7, 7, 7, 7, 12, 11, 7};

      int ans = minDays(arr, 2, 3);

      cout << ans;

      return 0;
}