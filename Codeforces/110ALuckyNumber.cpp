#include <bits/stdc++.h>

using namespace std;

int main()
{
      long long int n;
      cin >> n;

      while (n > 0)
      {
            long long int rem = n % 10;
            if (rem != 4 && rem != 7)
            {
                  cout << "NO" << endl;
                  break;
            }
            n /= 10;
      }
      if (n == 0)
      {
            cout << "YES" << endl;
      }

      return 0;
}