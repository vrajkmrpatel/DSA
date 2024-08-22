#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n;
      cin >> n;

      string t;
      cin >> t;

      string s;
      int inc = 1;
      for (int i = 0; i < t.length(); i += inc)
      {
            s += t[i];
            inc++;
      }

      cout << s << endl;
      return 0;
}