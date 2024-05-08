#include <bits/stdc++.h>

using namespace std;

char toLowercase(char ch)
{
      if (ch >= 'a' && ch <= 'z')
      {
            return ch;
      }
      else
      {
            char temp = ch - 'A' + 'a';
            return temp;
      }
}

bool checkPalindrome(string s)
{
      int st = 0;
      int e = s.length() - 1;

      while (st <= e)
      {
            if (s[st] != s[e])
            {
                  return 0;
            }
            st++;
            e--;
      }
      return 1;
}

bool isValid(char ch)
{
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
      {
            return 1;
      }
      return 0;
}

int main()
{
      string str = "   LOL , men . are ? // alive and ;;;;'@ jinda    ";

      string temp;
      for (int i = 0; i < str.length(); i++)
      {
            if (isValid(str[i]))
            {
                  temp.push_back(toLowercase(str[i]));
            }
      }

      cout << (checkPalindrome(temp) ? "is Palindrome" : "is Not a Palindrome") << endl;
      for (auto st : temp)
      {
            cout << st;
      }
}