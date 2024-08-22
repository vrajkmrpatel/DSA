#include<bits/stdc++.h>

using namespace std;

int main()
{
      string str;
      cin >> str;

      for(auto &x: str)
      {
            x = tolower(x);
      }
      
      str[0] = toupper(str[0]);

      cout << str << endl;
      return 0;
}