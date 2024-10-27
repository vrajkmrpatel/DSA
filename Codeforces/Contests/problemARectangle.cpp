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

            int maxW = 0, maxH = 0;
            while (n--)
            {
                  int w, h;
                  cin >> w >> h;

                  if (w > maxW)
                  {
                        maxW = w;
                  }
                  if (h > maxH)
                  {
                        maxH = h;
                  }
            }

            int perimeter = (2 * maxW) + (2 * maxH);
            cout << perimeter << endl;
      }
      return 0;
}