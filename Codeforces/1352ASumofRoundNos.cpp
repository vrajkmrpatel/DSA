#include <bits/stdc++.h>

using namespace std;

int main()
{
      int T;
      cin >> T;

      while (T--)
      {
            int num;
            cin >> num;

            vector<int> ans;
            int count = 0;
            int cntnz = 0;

            while (num > 0)
            {
                  int rem = num % 10;
                  count++;
                  if (rem)
                  {
                        cntnz++;
                        ans.push_back(rem * pow(10, count - 1));
                  }

                  num /= 10;
            }

            cout << cntnz << endl;
            for (auto it : ans)
            {
                  cout << it << " ";
            }
            cout << endl;
      }
      return 0;
}