#include <bits/stdc++.h>

using namespace std;

int main()
{

      int t;
      cin >> t;

      while(t--)
      {
            int y, x;
            cin >> y >> x;

            cout << spiral[y - 1][x - 1] << endl;
      }

      return 0;
}