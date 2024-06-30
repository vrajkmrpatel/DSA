#include <bits/stdc++.h>

using namespace std;

int main()
{
      int t;
      cin >> t;

      int count = 0;

      while (t--)
      {
            int p, v, t;
            cin >> p >> v >> t;

            if ((p && v) || (v && t) || (p && t))
            {

                  count++;
            }
      }

      cout << count;
      return 0;
}