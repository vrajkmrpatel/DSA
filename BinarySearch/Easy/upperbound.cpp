#include <bits/stdc++.h>

using namespace std;

int UpperBound(vector<int> &arr, int n, int x)
{
      int low = 0;
      int high = n - 1;

      int ans = n;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (arr[mid] > x)
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

      int target = 6;
      int ans = UpperBound(arr, n, target);

      cout << ans << endl;
      return 0;
}