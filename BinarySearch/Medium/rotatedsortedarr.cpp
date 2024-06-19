#include <bits/stdc++.h>

using namespace std;

int findIndex(vector<int> &arr, int n, int k)
{
      // time: O(LogN) Using binary search
      // INDENTIFY SORTED HALF TO SOLVE THIS PROBLEM

      int low = 0;
      int high = n - 1;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (arr[mid] == k)
            {
                  return mid;
            }
            // include in case of duplicate
            //  if((arr[low] == arr[mid]) && (arr[mid] == arr[high])) {
            //        low++;
            //        high--;

            // }
            else if (arr[low] <= arr[mid])
            {

                  if (arr[low] <= k && k <= arr[mid])
                  {

                        high = mid - 1;
                  }
                  else
                  {
                        low = mid + 1;
                  }
            }
            else
            {
                  if (arr[mid] <= k && k <= arr[high])
                  {
                        low = mid + 1;
                  }
                  else
                  {
                        high = mid - 1;
                  }
            }
      }
      return -1;
}
int main()
{
      vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
      int n = arr.size();
      int target = 1;
      int idx = findIndex(arr, n, target);

      cout << idx << endl;

      return 0;
}