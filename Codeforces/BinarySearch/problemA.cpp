#include <bits/stdc++.h>

using namespace std;

bool isPresent(int n, int arr[], int key)
{
      int low = 0;
      int high = n - 1;

      while (low <= high)
      {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                  return true;
            }
            else if (arr[mid] < key)
            {
                  low = mid + 1;
            }
            else
            {
                  high = mid - 1;
            }
      }
      return false;
}
void ProblemA(int n, int k, int arr[], int queries[])
{

      for (int i = 0; i < k; i++)
      {
            if (isPresent(n, arr, queries[i]))
            {
                  cout << "YES" << endl;
            }
            else
            {
                  cout << "NO" << endl;
            }
      }
}
int main()
{
      int n, k;
      cin >> n >> k;

      int arr[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      int queries[k];
      for (int i = 0; i < k; i++)
      {
            cin >> queries[i];
      }

      ProblemA(n, k, arr, queries);
      return 0;
}