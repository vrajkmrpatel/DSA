#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n;
      cin >> n;

      int maxN = 0;
      int tram = 0;

      while (n--)
      {
            int a, b;
            cin >> a >> b;

            tram = tram - a;
            tram = tram + b;

            maxN = max(maxN, tram);
      }

      cout << maxN << endl;
      return 0;
}