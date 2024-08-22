#include <bits/stdc++.h>

using namespace std;

long long solve(long long n, long long m)
{

      if (m % n != 0)
      {
            return -1;
      }

      long long quotient = m / n;
      int count = 0;

      while (quotient % 2 == 0)
      {
            quotient /= 2;
            count++;
      }

      while (quotient % 3 == 0)
      {
            quotient /= 3;
            count++;
      }

      if (quotient == 1)
      {
            return count;
      }
      else
      {
            return -1;
      }
}
int main()
{
      long long n, m;
      cin >> n >> m;

      cout << solve(n, m) << endl;

      return 0;
}