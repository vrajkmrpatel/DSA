#include <bits/stdc++.h>

using namespace std;

bool isValid(string word)
{

      unordered_set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

      int n = word.size();
      if (n < 3)
      {
            return false;
      }

      bool df = false, uf = false, lf = false, vf = false, cf = false;

      for (auto c : word)
      {

            if (!isdigit(c) && !isalpha(c))
                  return false;
            if (isdigit(c))
                  df = true;
            if (islower(c))
                  lf = true;
            if (isupper(c))
                  uf = true;
            if (s.count(c))
                  vf = true;
            else if (!s.count(c) && isalpha(c))
                  cf = true;
      }
      return ((df || uf || lf) && vf && cf);
}
int main()
{

      string s = "234Adas";
      if (isValid(s))
      {
            cout << "String is Valid" << endl;
      }
      else
      {
            cout << "String is not Valid" << endl;
      }
      return 0;
}