#include <bits/stdc++.h>

using namespace std;

int isPossible(vector<int> &arr, int n, int pages)
{
      int stu = 1;
      int pagesStudent = 0;

      for (int i = 0; i < n; i++)
      {
            if (pagesStudent + arr[i] <= pages)
            {
                  pagesStudent += arr[i];
            }
            else
            {
                  stu++;
                  pagesStudent = arr[i];
            }
      }

      return stu;
}
int bookAllocation(vector<int> &arr, int m)
{

      int n = arr.size();
      if (m > n)
            return -1;

      int sum = 0;
      for (int i = 0; i < n; i++)
      {
            sum += arr[i];
      }

      int low = *max_element(arr.begin(), arr.end());
      int high = sum;

      // linear search
      // for (int pages = low; pages < high; pages++)
      // {

      //       int cntStudents = isPossible(arr, n, pages);

      //       if (cntStudents == m)
      //       {
      //             return pages;
      //       }
      // }
      // return -1;

      // binary search

      while (low <= high)
      {
            int mid = low + (high - low) / 2;

            int stu = isPossible(arr, n, mid);

            if (stu > m)
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }

      return low;
}

int main()
{
      vector<int> arr = {25, 46, 28, 49, 24};

      int m = 4;
      cout << bookAllocation(arr, m) << endl;
      return 0;
}