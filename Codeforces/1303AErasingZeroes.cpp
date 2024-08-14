#include <bits/stdc++.h>

using namespace std;

int main()
{
      int T;
      cin >> T;

      while (T--)
      {
            string str;
            cin >> str;

            int count = 0;

            int first = str.find('1');
            int last = str.rfind('1');

            if (first == string::npos || first == last)
            {
                  cout << 0 << endl;
            }
            else
            {
                  for (int i = first + 1; i < last; i++)
                  {
                        if (str[i] == '0')
                        {
                              count++;
                        }
                  }
                  cout << count << endl;
            }
      }
      return 0;
}