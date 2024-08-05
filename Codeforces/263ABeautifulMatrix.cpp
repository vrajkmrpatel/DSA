#include <bits/stdc++.h>

using namespace std;

int main()
{
      int mat[6][6];
      int i, j, r, c;
      int ans = 0;

      for (int i = 1; i < 6; i++)
      {
            for (int j = 1; j < 6; j++)
            {
                  cin >> mat[i][j];
                  if (mat[i][j] == 1)
                  {
                        r = abs(3 - i);
                        c = abs(3 - j);
                  }
            }
      }

      ans = r + c;

      cout << ans << endl;
      return 0;
}