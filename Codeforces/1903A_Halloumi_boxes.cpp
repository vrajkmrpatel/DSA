#include <bits/stdc++.h>

using namespace std;

void halloumiboxes(vector<int> &arr, int n, int k)
{
      vector<int> ans(n);
      ans = arr;
      sort(ans.begin(), ans.end());

      if (ans == arr)
      {
            cout << "YES" << endl;
      }
      else if (n > k && k == 1)
      {
            cout << "NO" << endl;
      }
      else
      {
            cout << "YES" << endl;
      }
}
int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n, k;
            cin >> n >> k;

            vector<int> arr(n);
            for (int i = 0; i < n; i++)
            {
                  cin >> arr[i];
            }

            halloumiboxes(arr, n, k);
      }
      return 0;
}