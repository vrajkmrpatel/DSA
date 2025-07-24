#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

void printF(int ind, vector<int> &arr, vector<int> &ds, int n)
{
      if (ind == n)
      {
            for (int it : ds)
            {
                  cout << it << " ";
            }
            if (ds.size() == 0)
            {
                  cout << "{}" << " ";
            }
            cout << endl;
            return;
      }

      // take or pick the particular index into the subsequence
      ds.push_back(arr[ind]);
      printF(ind + 1, arr, ds, n);

      // not pick, or not take condition, this element is not added to your subsequence
      ds.pop_back();
      printF(ind + 1, arr, ds, n);
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      vector<int> arr = {3, 1, 2};
      int n = 3;

      vector<int> ds;
      printF(0, arr, ds, n);

      return 0;
}