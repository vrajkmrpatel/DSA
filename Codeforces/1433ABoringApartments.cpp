#include <bits/stdc++.h>

using namespace std;

int main()
{
      int T;
      cin >> T;

      while (T--)
      {
            int x;
            cin >> x;

            int num = x;
            int ans = 0;
            int count = 0;
            while (x > 0)
            {
                  count++;
                  x /= 10;
            }

            int rem = num % 10;
            ans = rem * 10;

            if (count == 3)
            {
                  cout << ans - 4 << endl;
            }
            else if (count == 2)
            {
                  cout << ans - 7 << endl;
            }
            else if (count == 1)
            {
                  cout << ans - 9 << endl;
            }
            else
            {
                  cout << ans << endl;
            }
      }
      return 0;
}