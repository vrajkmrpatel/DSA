#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n, x;
            cin >> n >> x;

            vector<int> arr(n);
            for (int i = 0; i < n; i++)
            {
                  cin >> arr[i];
            }
            
            int ans = 0;
            ans = arr[0];
            if(n == 1)
            {
                  ans = max(arr[0], x - arr[0]);
            }

            for (int i = 0; i < n - 1; i++)
            {
                  ans = max(arr[i + 1] - arr[i], ans);
            }

            ans = max(2 * (x - arr[n - 1]), ans);

            cout << ans << endl;
      }
      return 0;
}