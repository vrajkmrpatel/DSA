#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

void solve(int ind, int arr[], vector<int> &ds, int s, int sum, int n)
{

      if (ind == n)
      {
            if (s == sum)
            {
                  // print(ds)
                  for (int i : ds)
                  {
                        cout << i << " ";
                  }
                  cout << endl;
            }
            return;
      }
      ds.push_back(arr[ind]);
      s += arr[ind];

      solve(ind + 1, arr, ds, s, sum, n);

      ds.pop_back();
      s -= arr[ind];
      solve(ind + 1, arr, ds, s, sum, n);
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int n = 3;
      int arr[n] = {1, 2, 1};
      vector<int> ds;
      int sum = 2;
      solve(0, arr, ds, 0, sum, n);
      return 0;
}