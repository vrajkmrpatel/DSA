#include <bits/stdc++.h>

using namespace std;

bool isvowel(char ch)
{
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
      {
            return true;
      }
      return false;
}
string stringTask(string str)
{
      string ans = "";
      int n = str.length();

      transform(str.begin(), str.end(), str.begin(), ::tolower);

      for (int i = 0; i < n; i++)
      {
            if (!isvowel(str[i]))
            {
                  ans += '.';
                  ans += str[i];
            }
      }

      return ans;
}
int main()
{
      string str;
      cin >> str;

      cout << stringTask(str) << endl;
      return 0;
}