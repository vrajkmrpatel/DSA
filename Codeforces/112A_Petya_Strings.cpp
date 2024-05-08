#include <bits/stdc++.h>

using namespace std;

int main()
{
      long long i;
      string f, s;

      while (cin >> f >> s)
      {

            long sum1 = 0, sum2 = 0;
            for (int i = 0; i < f.size(); i++)
            {

                  if (f[i] >= 'A' && f[i] <= 'Z')
                        f[i] = f[i] - 'A' + 'a';

                  if (s[i] >= 'A' && s[i] <= 'Z')
                        s[i] = s[i] - 'A' + 'a';
            }

            for (int i = 0; i < s.size(); i++)
            {

                  if (f[i] > s[i])
                  {
                        cout << "1\n";
                        return 0;
                  }

                  if (f[i] < s[i])
                  {
                        cout << "-1\n";
                        return 0;
                  }
            }
            cout << "0\n";
      }
      return 0;
}