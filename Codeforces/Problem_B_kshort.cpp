#include <bits/stdc++.h>

using namespace std;

int main()
{

      int t;
      cin >> t;

      while (t--)
      {
            int n;
            cin >> n;

            vector<int> a(n);

            for (int i = 0; i < n; ++i)
            {

                  cin >> a[i];
            }

            long long coins = 0;
            for (int i = 1; i < n; i++)
            {

                  if (a[i] < a[i - 1])
                  {
                        int diff = a[i - 1] - a[i];
                        a[i] += diff;
                        coins += diff;
                  }
            }

            cout << coins << endl;
      }
      return 0;
}