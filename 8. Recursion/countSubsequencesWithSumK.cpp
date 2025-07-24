#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int solve(int ind, int arr[], int s, int sum, int n)
{
      if (ind == n)
      {
            // condition satisfied
            if (s == sum)
            {
                  return 1;
            }
            // condition not satisfied
            return 0;
      }

      s += arr[ind];

      int l = solve(ind + 1, arr, s, sum, n);

      s -= arr[ind];

      int r = solve(ind + 1, arr, s, sum, n);

      return l + r;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n = 3;
      int arr[n] = {1, 2, 1};

      int sum = 2;
      cout << solve(0, arr, 0, sum, n);
      return 0;
}