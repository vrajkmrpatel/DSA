#include <bits/stdc++.h>

using namespace std;

void RemainingStr(string s, int count)
{

      int cnt = 0;
      string ans = "";
      int index = 0;

      for (int i = 0; i < s.length(); i++)
      {

            if (cnt == count)
            {
                  index = i;
                  break;
            }
            index++;
      }
      int k = 0;
      for (int j = index; j < s.length(); j++)
      {

            ans[k] += s[j];
            k++;
      }

      for (int i = 0; i < ans.length(); i++)
      {

            cout << ans[i];
      }
}
int main()
{

      string s = "Thisisdemostring";
      int count = 3;
      RemainingStr(s, count);

      return 0;
}