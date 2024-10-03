#include <bits/stdc++.h>

using namespace std;

int LowerBound(vector<int> &arr, int n, int x)
{
      int low = 0;
      int high = n - 1;

      int ans = n;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (arr[mid] >= x)
            {
                  ans = mid;
                  high = mid - 1;
            }
            else
            {
                  low = mid + 1;
            }
      }
      return ans;
}


int main()
{
      vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};

      int n = arr.size();

      int target = 18;
      int ans = LowerBound(arr, n, target);

      // Using cpp direct method
      // int ans = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

      cout << ans << endl;
      return 0;
}