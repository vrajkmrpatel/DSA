#include <bits/stdc++.h>

using namespace std;

int singleElementInSortedArray(vector<int> &arr)
{

      int n = arr.size();
      int low = 0;
      int high = n - 1;

      if (n == 1)
            return arr[0];
      if (arr[0] != arr[1])
            return arr[0];
      if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            {

                  return arr[mid];
            }

            // left half
            if (mid % 2 == 1 && arr[mid - 1] == arr[mid] || mid % 2 == 0 && arr[mid] == arr[mid + 1])
            {
                  low = mid + 1;
            }

            // right half
            else
            {
                  high = mid - 1;
            }
      }
      return -1;
}
int main()
{

      vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6};

      int ele = singleElementInSortedArray(arr);

      cout << "Single element is: " << ele << endl;
      return 0;
}