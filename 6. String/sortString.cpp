#include <bits/stdc++.h>

using namespace std;

int main()
{
      string str = "klijghefcdab";

      // using sort method
      // TC: O(nlogn)
      // SC: O(1)
      // sort(str.begin(), str.end());
      // cout << str << endl;

      // using hashed array
      // TC: O(MAX_CHAR * N) --> OVERALL O(N) MAX_CHAR IS CONSTANT, N IS THE LENGTH OF THE STRING
      // SC: O(1)
      const int MAX_CHAR = 26;

      int charCount[MAX_CHAR] = {0};

      for (int i = 0; i < str.length(); i++)
      {
            charCount[str[i] - 'a']++;
      }

      for (int i = 0; i < MAX_CHAR; i++)
      {
            for (int j = 0; j < charCount[i]; j++)
            {
                  cout << (char)('a' + i);
            }
      }
      return 0;
}