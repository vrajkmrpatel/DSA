#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;

      while (t--)
      {
            int n, k;
            cin >> n >> k;

            vector<int> arr;
            for (int i = 0; i < n; i++)
            {
                  cin >> arr[i];
            }

            for (auto it : arr)
            {
                  cout << it << " ";
            }
      }
      return 0;
}