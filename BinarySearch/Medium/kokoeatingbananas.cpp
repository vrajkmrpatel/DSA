#include <bits/stdc++.h>

using namespace std;

int calculateK(vector<int> &arr, int mid)
{

      int count = 0;
      for (int i = 0; i < arr.size(); i++)
      {
            count += ceil((double)arr[i] / (double)mid);
      }

      return count;
}
int kokoEatingBananas(vector<int> &arr, int h)
{

      int n = arr.size();
      int maxEle = *max_element(arr.begin(), arr.end());

      int low = 1;
      int high = maxEle;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;
            int totalH = calculateK(arr, mid);
            if (totalH <= h)
            {
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

      vector<int> arr = {30, 11, 23, 4, 20};

      int ans = kokoEatingBananas(arr, 6);
      cout << ans << endl;
      return 0;
}