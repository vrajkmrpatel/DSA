#include <bits/stdc++.h>

using namespace std;

int LowerBound(int n, int arr[], int x)
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
void ProblemB(int n, int k, int arr[], int queries[])
{
      for (int i = 0; i < n; i++)
      {
            cout << LowerBound(n, arr, queries[i]) << endl;
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

      ProblemB(n, k, arr, queries);
      return 0;
}