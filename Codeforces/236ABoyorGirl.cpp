#include<bits/stdc++.h>

using namespace std;

string isBoyorGirl(string str)
{
      unordered_set<char> ansSet;

      for (int i = 0; i < str.length(); i++)
      {
            ansSet.insert(str[i]);
      }

      if(ansSet.size() % 2 == 0)
      {
            return "CHAT WITH HER!";
      }
      else {
            return "IGNORE HIM!";
      }
}
int main()
{
      string str;
      cin >> str;

      cout << isBoyorGirl(str) << endl;
      return 0;
}