#include <bits/stdc++.h>

using namespace std;

string FindUncommon(string A, string B)
{

      int map1[26] = {0};
      int map2[26] = {0};

      for (auto &x : A)
      {

            map1[x - 'a'] = 1;
      }

      for (auto &x : B)
      {

            map2[x - 'a'] = 1;
      }

      string ans = "";

      for (int i = 0; i < 26; i++)
      {

            if (map1[i] ^ map2[i])
            {

                  ans += char(i + 'a');
            }
      }
      if (ans == "")
            return "-1";
      else
            return ans;
}

int main()
{
      string A = "geeksforgeeks";
      string B = "geeksquiz";

      string ans = FindUncommon(A, B);

      for (int i = 0; i < ans.length(); i++)
      {

            cout << ans[i];
      }
      return 0;
}