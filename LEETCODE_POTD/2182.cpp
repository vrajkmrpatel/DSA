// Construct String with repeat limit

#include <bits/stdc++.h>

using namespace std;

string repeatLimitedString(string s, int repeatLimit)
{
      int len = s.length();
      vector<int> freq(26);

      // store the frequency of characters in string
      for (char &ch : s)
      {
            freq[ch - 'a']++;
      }

      string ans = "";
      // start from the largest character
      int index = 25;
      while (index >= 0)
      {
            if (freq[index] == 0)
            {
                  index--;
                  continue;
            }

            int used = min(freq[index], repeatLimit);
            for (int k = 0; k < used; k++)
            {
                  ans += (char)('a' + index);
            }
            freq[index] -= used;

            if (freq[index] > 0)
            {
                  int prevIndex = index - 1;

                  while (prevIndex >= 0 && freq[prevIndex] == 0)
                  {
                        prevIndex--;
                  }

                  if (prevIndex < 0)
                  {
                        break;
                  }
                  ans += (char)('a' + prevIndex);
                  freq[prevIndex]--;
            }
      }
      return ans;
}

int main()
{
      string s = "cczazcc";
      int repeatLimit = 3;

      cout << repeatLimitedString(s, repeatLimit);
      return 0;
}