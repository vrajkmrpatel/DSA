#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
      bool isSpecial(string str)
      {
            char ch = str[0];
            for (int i = 1; i < str.length(); i++)
            {
                  if (ch != str[i])
                  {
                        return false;
                  }
            }
            return true;
      }
      int maximumLength(string s)
      {

            int n = s.length();
            unordered_map<string, int> freq;

            for (int i = 0; i < n; i++)
            {
                  string substring = "";
                  for (int j = i; j < n; j++)
                  {
                        if (substring.length() == 0 || s[j] == substring[substring.length() - 1])
                        {
                              substring += s[j];
                              freq[substring]++;
                        }
                        else
                        {
                              break;
                        }
                  }
            }

            int len = -1;
            for (auto curr : freq)
            {
                  if (curr.second >= 3)
                  {
                        int curLength = curr.first.length();
                        len = max(len, curLength);
                  }
            }

            return len;
      }
};

int main()
{
      Solution s;
      string str = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde";

      cout << s.maximumLength(str) << endl;
      return 0;
}