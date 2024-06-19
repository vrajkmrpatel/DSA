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

int firstOccurence(vector<int> &arr, int n, int k)
{

      int first = -1;
      int low = 0;
      int high = n - 1;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (arr[mid] == k)
            {
                  first = mid;
                  high = mid - 1;
            }
            else if (arr[mid] < k)
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }
      return first;
}

int lastOccurence(vector<int> &arr, int n, int k)
{

      int last = -1;
      int low = 0;
      int high = n - 1;

      while (low <= high)
      {

            int mid = low + (high - low) / 2;

            if (arr[mid] == k)
            {
                  last = mid;
                  low = mid + 1;
            }
            else if (arr[mid] < k)
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }
      return last;
}

pair<int, int> FindFirstAndLast(vector<int> &arr, int target)
{
      int n = arr.size();

      // Linear Approach
      // Time O(N)

      // int first = -1, last = -1;
      // for (int i = 0; i < n; i++)
      // {

      //       if (arr[i] == target)
      //       {
      //             if (first == -1)
      //             {
      //                   first = i;
      //             }
      //             last = i;
      //       }
      // }
      // pair<int, int> ans = {first, last};
      // return ans;

      // Using Prewritten Code of Lowerbound & Upperbound

      // int lb = LowerBound(arr, n, target);
      // if (lb == n || arr[lb] != target)
      // {
      //       return {-1, -1};
      // }
      // return {lb, UpperBound(arr, n, target) - 1};

      // Binary search from scratch

      int first = firstOccurence(arr, n, target);
      if (first == -1)
            return {-1, -1};

      int last = lastOccurence(arr, n, target);
      return {first, last};
}

int main()
{

      vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
      int target = 12;

      pair<int, int> p = FindFirstAndLast(arr, target);

      cout << p.first << " " << p.second << endl;
      return 0;
}