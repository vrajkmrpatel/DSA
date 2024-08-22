#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr, int n)
{
      int ans = 0;
      for (int i = 0; i < n; i++)
      {
            if (i + 1 != arr[i])
            {
                  ans = i + 1;
            }
      }
      return ans;
}
int main()
{

      int n;
      cin >> n;

      vector<int> arr(n);
      for (int i = 0; i < n - 1; i++)
      {
            cin >> arr[i];
      }

      sort(arr.begin(), arr.end());

      cout << solve(arr, n) << endl;

      return 0;
}