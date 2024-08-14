#include <bits/stdc++.h>

using namespace std;

int minOperations(int a, int b, int n)
{
      int count = 0;

      while (max(a, b) <= n)
      {
            if (a < b)
            {
                  a += b;
            }
            else
            {
                  b += a;
            }
            count++;
      }

      return count;
}
int main()
{
      int T;
      cin >> T;

      while (T--)
      {
            int a, b, n;
            cin >> a >> b >> n;

            cout << minOperations(a, b, n) << endl;
      }
      return 0;
}