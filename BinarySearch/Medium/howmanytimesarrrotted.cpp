// Same Code as findingmininrotatedsortedarray

#include <bits/stdc++.h>

using namespace std;

int howManyTimesArrayRotated(vector<int> &arr, int n)
{

      // time: O(LogN) Using binary search
      // INDENTIFY SORTED HALF TO SOLVE THIS PROBLEM

      int low = 0;
      int high = n - 1;
      int ans = INT_MAX;
      int index = -1;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            // include in case of duplicate
            // if ((arr[low] == arr[mid]) && (arr[mid] == arr[high]))
            // {
            //       low++;
            //       high--;
            // }

            // if low <= mid <= high then optimized for better
            if (arr[low] <= arr[high])
            {
                  if (arr[low] < ans)
                  {
                        index = low;
                        ans = arr[low];
                  }
                  break;
            }

            // left part is sorted, so update min element in left sorted part and move to right part
            if (arr[low] <= arr[mid])
            {
                  if (arr[low] < ans)
                  {
                        index = low;
                        ans = arr[low];
                  }
                  low = mid + 1;
            }
            // right part is sorted, so update min element in right sorted part and move to left part
            else
            {
                  if (arr[mid] < ans)
                  {

                        index = mid;
                        ans = arr[mid];
                  }
                  high = mid - 1;
            }
      }
      return index;
}
int main()
{
      vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
      // vector<int> arr = {1, 0, 1, 1, 1, 1, 1}; // for duplicate
      int n = arr.size();

      int index = howManyTimesArrayRotated(arr, n);

      cout << index << endl;

      return 0;
}