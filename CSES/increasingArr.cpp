#include <bits/stdc++.h>

using namespace std;

long long int solve(vector<long long int> &arr, long long int n)
{
      long long int move = 0;

      for (int i = 1; i < n; i++)
      {
            if (arr[i - 1] > arr[i])
            {
                  move += (arr[i - 1] - arr[i]);
                  arr[i] += (arr[i - 1] - arr[i]);
            }
      }

      return move;
}
int main()
{
      long long int n;
      cin >> n;

      vector<long long int> arr(n);
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      cout << solve(arr, n) << endl;

      return 0;
}