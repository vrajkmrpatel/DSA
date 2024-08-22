#include <bits/stdc++.h>

using namespace std;

void minMoves(vector<int> &arr, int n)
{
      int minInd = 0;
      int min = arr[0];

      int maxInd = 0;
      int max = arr[0];
      int res = 0;

      for (int i = 1; i < n; i++)
      {
            if (arr[i] <= min)
            {
                  minInd = i;
                  min = arr[i];
            }

            else if (arr[i] > max)
            {
                  maxInd = i;
                  max = arr[i];
            }
      }

      int swaps = maxInd + (n - 1 - minInd);

      // if maxEle is before the minEle than we save 1 swap
      if (maxInd > minInd)
      {
            swaps--;
      }

      cout << swaps << endl;
}
int main()
{
      int n;
      cin >> n;

      vector<int> arr(n);
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      minMoves(arr, n);
      return 0;
}