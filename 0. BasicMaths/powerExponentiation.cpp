#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod1 1000000007
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";

int powerExponentiation(int x, int n)
{
      int ans = 1;
      while (n > 0)
      {
            if (n & 1)
            {
                  ans = ans * x;
                  n = n - 1;
            }
            else
            {
                  x = x * x;
                  n = n >> 1; // n / 2;
            }
      }
      return ans;
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int x = 3;
      int n = 9;
      cout << powerExponentiation(x, n) << endl;

      return 0;
}